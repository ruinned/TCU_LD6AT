/**
 * \file
 *
 * \brief AUTOSAR PduR
 *
 * This file contains the implementation of the AUTOSAR
 * module PduR.
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2013 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

/*==================[inclusions]============================================*/

#include <PduR_Trace.h>
#include <TSAutosar.h>            /* EB specific standard types */
#include <TSAtomic_Assign.h>      /* Atomic assignments from Base PlugIn */
#include <TSMem.h>                /* TS_MemCpy */
#include <ComStack_Types.h>       /* AUTOSAR Communication Stack types */
#include <PduR_Internal_Static.h> /* Internal API (static part) */
#include <PduR_Api_Depend.h>      /* Public API (depend part) */

#if ((PDUR_ZERO_COST_OPERATION_TP == STD_OFF) && (PDUR_TPGATEWAY_SUPPORT == STD_ON))
#include <SchM_PduR.h>            /* Schedule Manager for module PduR */
#include <PduR_Lcfg.h>            /* Link-time configurable data */
/*==================[macros]================================================*/

/*==================[type definitions]======================================*/

/*==================[external function declarations]========================*/

/*==================[internal function declarations]========================*/

/* AUTOSAR Memory Mapping - start section for code */
#if (TS_MERGED_COMPILE == STD_OFF)
#define PDUR_START_SEC_CODE
#include <MemMap.h>
#endif

/**
 ** \brief Auxiliary Tp gateway handler function
 **
 ** Auxiliary function that copies received data to the allocated TP buffer.
 ** The TP gateway session members AvailableBufferSize and RxWriteIndex
 ** are updated appropriately.
 **
 ** \param[in] SessionIndex        Index of considered TP gateway session.
 ** \param[in] PduInfoPtr          Pointer to the buffer (SduDataPtr) and its length (SduLength)
 **                                containing the data to be copied by PDU Router module in
 **                                case of TP gateway.
 **
 ** \return Result of request to copy received data to allocated TP buffer.
 ** \retval BUFREQ_E_NOT_OK: SduDataPtr set to null for enabled DET.
 **                          Received data exceeds available size of TP buffer or
 **                          available size of TP buffer equals zero.
 ** \retval BUFREQ_OK:       Received data is copied successfully to TP buffer.
 **/
STATIC FUNC(BufReq_ReturnType, PDUR_CODE) PduR_CopyDataToTpBuffer
(
   PduR_GateTpSessionIndexType SessionIndex,
   P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) PduInfoPtr
);

/*==================[external constants]====================================*/

/*==================[internal constants]====================================*/

/*==================[external data]=========================================*/

/*==================[internal data]=========================================*/

/*==================[external function definitions]=========================*/

FUNC(BufReq_ReturnType, PDUR_CODE) PduR_GateTpCopyRxData
(
   PduIdType GMPduId,
   P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) PduInfoPtr,
   P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) BufferSizePtr
)
{
   /* initialize return value */
   BufReq_ReturnType RetVal = BUFREQ_E_NOT_OK;

   /* get TP gateway session in use */
   PduR_GateTpSessionIndexType SessionIndex;

   boolean CallLoTpTransmit = FALSE;

   /* pointer to routing table */
   CONSTP2CONST(PduR_GTabTpRxType, AUTOMATIC, PDUR_APPL_CONST) pGTabTpRx =
      PDUR_GET_CONFIG_ADDR(PduR_GTabTpRxType, PduR_gConfigPtr->PduR_GTabTpConfig.GTabRxRef);

   /* pointer to TP gateway sessions */
   CONSTP2VAR(PduR_GateTpSessionInfoType, AUTOMATIC, PDUR_VAR_NOINIT) pSessionInfos =
      PDUR_GET_RAM_ADDR(PduR_GateTpSessionInfoType, PduR_gConfigPtr->PduR_GateTpSessionInfoRef);

#if (PDUR_DEV_ERROR_DETECT == STD_ON)
   boolean CallDetReportError = FALSE;
   uint8 DetErrorCode = PDUR_E_INVALID_REQUEST;
#endif /* if (PDUR_DEV_ERROR_DETECT == STD_ON) */

   DBG_PDUR_GATETPCOPYRXDATA_ENTRY(GMPduId, PduInfoPtr, BufferSizePtr);

   /* ENTER CRITICAL SECTION */
   SchM_Enter_PduR_SCHM_PDUR_EXCLUSIVE_AREA_0();

   /* get TP gateway session in use */
   SessionIndex = PduR_GetGateTpSessionInUse(GMPduId);

   /* CopyRxData called without preceding StartOfReception */
#if (PDUR_DEV_ERROR_DETECT == STD_ON)
   if(SessionIndex == PDUR_NO_GATETP_SESSION_ASSIGNED)
   {
      CallDetReportError = TRUE;
      DetErrorCode = PDUR_E_INVALID_REQUEST;
   }
   else
#endif /* if (PDUR_DEV_ERROR_DETECT == STD_ON) */
   {
      uint8 ResultGetBitAbort;

      PduR_PduLengthType AvailableBufferSize = pSessionInfos[SessionIndex].AvailableBufferSize;

      /* set BufferSize to initial value */
      *BufferSizePtr = AvailableBufferSize;

      /* check if transmission shall be aborted (e.g. Tx site failed) */
      TS_GetBit(&pSessionInfos[SessionIndex].Status, PDUR_GATETP_ABORT_POS, uint8,
                ResultGetBitAbort);
      if(ResultGetBitAbort > 0U)
      {
         /* BUFREQ_E_NOT_OK from initialization is returned */
      }
      /* return available length of reserved TP buffer */
      else if(PduInfoPtr->SduLength == (PduLengthType)PDUR_SDU_LENGTH_ZERO)
      {
         RetVal = BUFREQ_OK;
      }
      /* available TP buffer size is to small */
      else if(AvailableBufferSize < PduInfoPtr->SduLength)
      {
         TS_AtomicSetBit_8(&pSessionInfos[SessionIndex].Status, PDUR_GATETP_ABORT_POS);
         /* RetVal from initialization is returned */
      }
      /* copy data on reception */
      else
      {

#if (PDUR_DEV_ERROR_DETECT == STD_ON)
         /* check if input parameter member is NULL */
         if(PduInfoPtr->SduDataPtr == NULL_PTR)
         {
            CallDetReportError = TRUE;
            DetErrorCode = PDUR_E_NULL_POINTER;
            /* RetVal from initialization is returned */
         }
         else
#endif /* #if (PDUR_DEV_ERROR_DETECT == STD_ON) */
         {
            /* copy data from buffer of LoTp to TP buffer of PduR */
            RetVal = PduR_CopyDataToTpBuffer(SessionIndex, PduInfoPtr);
         }

         /* set BufferSize to updated value */
         *BufferSizePtr = pSessionInfos[SessionIndex].AvailableBufferSize;

         /* PduR_CopyDataToTpBuffer returned successfully */
         if(RetVal == BUFREQ_OK)
         {
            uint8 ResultGetBitTxComplete;

            const PduR_PduLengthType AvailableDataSize = PduR_CalcAvailableDataSize(SessionIndex);

            /* call Transmit if TpThreshold is reached for the first time,
               this is only possible for a single destination - routing on the fly */
            TS_GetBit(&pSessionInfos[SessionIndex].Status, PDUR_GATETP_TX_COMPLETE_POS, uint8,
                      ResultGetBitTxComplete);
            if((AvailableDataSize >= pGTabTpRx[GMPduId].TpThreshold) &&
               (ResultGetBitTxComplete == 0U))
            {
               /* call LoTp_Transmit after critical section is closed */
               CallLoTpTransmit = TRUE;
            }
         }
         /* PduR_CopyDataToTpBuffer returned not successfully */
         else
         {
            TS_AtomicSetBit_8(&pSessionInfos[SessionIndex].Status, PDUR_GATETP_ABORT_POS);
            /* RetVal from PduR_CopyDataToTpBuffer is returned (BUFREQ_E_NOT_OK) */
         }
      }
   }

   /* EXIT CRITICAL SECTION */
   SchM_Exit_PduR_SCHM_PDUR_EXCLUSIVE_AREA_0();

   if(CallLoTpTransmit)
   {
      /* return value of Transmit */
      Std_ReturnType RetValTransmit;

      /* PduInfo to Transmit */
      PduInfoType PduR_PduInfo;

      /* reference to set of target module API functions */
      const PduR_RefToModuleAPI TargetAPIRef = pGTabTpRx[GMPduId].TargetModuleAPIRef;

      /* get pointer to Transmit function */
      const PduR_TransmitFpType TransmitFp = PduR_TpModuleAPI[TargetAPIRef].TpTransmit;

      /* get target PDU ID to Transmit function from routing table */
      const PduR_PduIdType TargetPduId = pGTabTpRx[GMPduId].TargetPduId;

      /* setup PduInfo for Transmit */
      /* No explicit cast is necessary since PduR_PduLengthType and PduLengthType are both fixed
       * with uint16 by the Java generator.
       * Since session member TpSduLength is only updated (written) by StartOfReception, no
       * protection is necessary. */
      PduR_PduInfo.SduLength = pSessionInfos[SessionIndex].TpSduLength;
      PduR_PduInfo.SduDataPtr = NULL_PTR;

      /* call Transmit for routing on the fly - only single destination possible */
      RetValTransmit = TransmitFp(TargetPduId, &PduR_PduInfo);

      /* ENTER CRITICAL SECTION */
      SchM_Enter_PduR_SCHM_PDUR_EXCLUSIVE_AREA_0();

      if(RetValTransmit == E_OK)
      {
         /* increment counter for pending TxConfirmation */
         pSessionInfos[SessionIndex].PendTxConfCount++;

         RetVal = BUFREQ_OK;

         TS_AtomicSetBit_8(&pSessionInfos[SessionIndex].Status, PDUR_GATETP_TX_COMPLETE_POS);
      }
      else
      {
         TS_AtomicSetBit_8(&pSessionInfos[SessionIndex].Status, PDUR_GATETP_ABORT_POS);

         RetVal = BUFREQ_E_NOT_OK;

         /* development error detection handling for rejected transmit call */
#if (PDUR_DEV_ERROR_DETECT == STD_ON)
         CallDetReportError = TRUE;
         DetErrorCode = PDUR_E_TP_TX_REQ_REJECTED;
#endif /* if (PDUR_DEV_ERROR_DETECT == STD_ON) */
      }

      /* EXIT CRITICAL SECTION */
      SchM_Exit_PduR_SCHM_PDUR_EXCLUSIVE_AREA_0();
   }

   /* Conglomerate DET handling */
#if (PDUR_DEV_ERROR_DETECT == STD_ON)
   if(CallDetReportError)
   {
      PDUR_DET_REPORT_ERROR(PDUR_SID_LOTP_COPY_RX_DATA, DetErrorCode);
   }
#endif /* if (PDUR_DEV_ERROR_DETECT == STD_ON) */

   DBG_PDUR_GATETPCOPYRXDATA_EXIT(RetVal, GMPduId, PduInfoPtr, BufferSizePtr);

   return RetVal;
}

/*==================[internal function definitions]=========================*/

STATIC FUNC(BufReq_ReturnType, PDUR_CODE) PduR_CopyDataToTpBuffer
(
   PduR_GateTpSessionIndexType SessionIndex,
   P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) PduInfoPtr
)
{
   /* initialize return value */
   BufReq_ReturnType RetVal = BUFREQ_E_NOT_OK;

   const PduR_BufTpIndexType BufTpIndex = (PduR_BufTpIndexType)SessionIndex;

   /* pointer to TP gateway sessions */
   CONSTP2VAR(PduR_GateTpSessionInfoType, AUTOMATIC, PDUR_VAR_NOINIT) pGateTpSessions =
      PDUR_GET_RAM_ADDR(PduR_GateTpSessionInfoType, PduR_gConfigPtr->PduR_GateTpSessionInfoRef);

   /* pointer to TP buffer configurations */
   CONSTP2CONST(PduR_BufTpConfigType, AUTOMATIC, PDUR_APPL_CONST) pBufTpConfig =
      PDUR_GET_CONFIG_ADDR(PduR_BufTpConfigType, PduR_gConfigPtr->PduR_BufTpConfigRef);

   /* index to the first element of the TP buffer where to write the data by reception */
   PduR_PduLengthType RxWriteIndex = pGateTpSessions[SessionIndex].RxWriteIndex;

   /* length of the associated TP buffer (used also to determine TxReadIndex) */
   const PduR_PduLengthType BufTpLength = pBufTpConfig[BufTpIndex].Length;

   /* pointer to the first element of the TP buffer */
   CONSTP2VAR(uint8, AUTOMATIC, PDUR_VAR_NOINIT) pStartTpBuf =
      PDUR_GET_RAM_ADDR(uint8, pBufTpConfig[BufTpIndex].MemRef);

   PduR_PduLengthType AvailableBufferSize = pGateTpSessions[SessionIndex].AvailableBufferSize;

   /* index to the first element of the TP buffer where to read the data by transmit */
   const PduR_PduLengthType TxReadIndex =
      (RxWriteIndex + AvailableBufferSize) % pBufTpConfig[BufTpIndex].Length;

   DBG_PDUR_COPYDATATOTPBUFFER_ENTRY(SessionIndex, PduInfoPtr);

   /* copy data to TP buffer with already wrapped RxWriteIndex */
   if(TxReadIndex > RxWriteIndex)
   {
      TS_MemCpy(&pStartTpBuf[RxWriteIndex], PduInfoPtr->SduDataPtr, PduInfoPtr->SduLength);

      RetVal = BUFREQ_OK;

      RxWriteIndex += PduInfoPtr->SduLength;

      /* update available TP buffer size */
      AvailableBufferSize -= PduInfoPtr->SduLength;
   }
   /* copy data to TP buffer without wrapped RxWriteIndex, RxWriteIndex >= TxReadIndex */
   else
   {
      /* received data fits completely at the end of the TP buffer */
      if(PduInfoPtr->SduLength <= (BufTpLength - RxWriteIndex))
      {
         TS_MemCpy(&pStartTpBuf[RxWriteIndex], PduInfoPtr->SduDataPtr, PduInfoPtr->SduLength);

         RxWriteIndex += PduInfoPtr->SduLength;

         /* reset RxWriteIndex */
         if(RxWriteIndex == BufTpLength)
         {
            RxWriteIndex = 0U;
         }
      }
      /* received data exceeds free size at the end of the TP buffer */
      else
      {
         /* constants used to avoid MISRA 10.1 violation in TS_MemCpy due to complex
            expressions of the form u16a - u16b for third parameter */
         const PduR_PduLengthType SizeToEndOfBuffer = BufTpLength - RxWriteIndex;
         const PduR_PduLengthType RemainingSduSize = PduInfoPtr->SduLength - SizeToEndOfBuffer;

         TS_MemCpy(&pStartTpBuf[RxWriteIndex], PduInfoPtr->SduDataPtr, SizeToEndOfBuffer);
         TS_MemCpy(&pStartTpBuf[0], &PduInfoPtr->SduDataPtr[SizeToEndOfBuffer],
                   RemainingSduSize);

         RxWriteIndex = RemainingSduSize;
      }

      RetVal = BUFREQ_OK;

      /* update available TP buffer size */
      AvailableBufferSize -= PduInfoPtr->SduLength;
   }

   /* reassign available TP buffer size and current write index */
   pGateTpSessions[SessionIndex].AvailableBufferSize = AvailableBufferSize;
   pGateTpSessions[SessionIndex].RxWriteIndex = RxWriteIndex;

   DBG_PDUR_COPYDATATOTPBUFFER_EXIT(RetVal, SessionIndex, PduInfoPtr);

   return RetVal;
}


/* AUTOSAR Memory Mapping - end section for code */
#if (TS_MERGED_COMPILE == STD_OFF)
#define PDUR_STOP_SEC_CODE
#include <MemMap.h>
#endif

#else /* if (PDUR_ZERO_COST_OPERATION_TP == STD_OFF) && .. */

#include <TSCompiler.h>           /* usage of macro in TSCompiler_Default.h */

/* Avoid empty translation unit according to ISO C90 */
TS_PREVENTEMPTYTRANSLATIONUNIT

#endif /* if (PDUR_ZERO_COST_OPERATION_TP == STD_OFF) && .. */
/*==================[end of file]===========================================*/

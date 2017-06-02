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
#if (!defined PDUR_INTERNAL_STATIC_H)
#define PDUR_INTERNAL_STATIC_H

/*
 *  MISRA-C:2004 Deviation List
 *
 *  MISRA-1) Deviated Rule: 19.7 (advisory)
 *   A function should be used in preference to a function-like macro.
 *
 *   Reason:
 *   As the function is called very often and consists only of a few lines
 *   here a macro based implementation has been chosen.
 *
 *  MISRA-2) Deviated Rule: 11.3 (advisory)
 *   A cast should not be performed between a pointer type and an integral
 *   type.
 *
 *   Reason:
 *   Definition of NULL_PTR performs a cast from unsigned int to (void).
 *
 *  MISRA-3) Deviated Rule: 8.12 (advisory)
 *   When an array is declared with external linkage, its size shall be
 *   stated explicitly or defined implicitly by initialization.
 *
 *   Reason:
 *   The deviation is necessary as the size can only be determined
 *   at link time.
 *
 *  MISRA-4) Deviated Rule: 19.6 (required)
 *   '#undef' shall not be used.
 *
 *   Reason:
 *   The macros TS_RELOCATABLE_CFG_ENABLE might be used by more
 *   modules than the PduR modules. To avoid that this macro is used by other modules
 *   accidentally an undef is used here.
 */

/*==================[inclusions]============================================*/

#include <TSAutosar.h>            /* EB specific standard types        */
#include <ComStack_Types.h>       /* AUTOSAR Communication Stack types */
#include <PduR_Api_Static.h>      /* AUTOSAR PDU Router header file */
#include <PduR_Cfg.h>             /* DET configuration */
#include <PduR_Lcfg_Static.h>     /* Lcfg header file for PduR_gMemPtr */
#include <PduR_Version.h>         /* Module's version declaration (e.g. PDUR_MODULE_ID) */

#define TS_RELOCATABLE_CFG_ENABLE PDUR_RELOCATABLE_CFG_ENABLE
#include <TSPBConfig_Access.h>    /* Post Build Config Helpers (TS_UNCHECKEDGET..) */
/* Deviation MISRA-4 */
#undef TS_RELOCATABLE_CFG_ENABLE

#if (PDUR_DEV_ERROR_DETECT == STD_ON)
#include <Det.h>                  /* Header file of Development Error Tracer*/
#endif /* if (PDUR_DEV_ERROR_DETECT == STD_ON) */


/*==================[macros]================================================*/

#if (defined PDUR_DET_REPORT_ERROR) /* to prevent double declaration */
#error PDUR_DET_REPORT_ERROR already defined
#endif /* if (defined PDUR_DET_REPORT_ERROR) */

#if (PDUR_DEV_ERROR_DETECT == STD_ON)

/* Deviation MISRA-1 */
/** \brief Macro for reporting an error to Det
 **
 ** \param[in] SID Service ID of the API function
 ** \param[in] ERROR_CODE Error code reported to Det module
 **/
#define PDUR_DET_REPORT_ERROR(SID, ERROR_CODE)\
   do{\
         (void)Det_ReportError(\
               (uint16) (PDUR_MODULE_ID),\
               (uint8) (PDUR_INSTANCE_ID),\
               (uint8) (SID),\
               (uint8) (ERROR_CODE)\
               );\
   }while(0)

#endif /* if (PDUR_DEV_ERROR_DETECT == STD_ON) */


#if (defined PDUR_NO_MULTITP_SESSION_ASSIGNED) /* to prevent double declaration */
#error PDUR_NO_MULTITP_SESSION_ASSIGNED already defined
#endif /* if (defined PDUR_NO_MULTITP_SESSION_ASSIGNED) */

/** \brief Macro definition for unassigned multicast transmit session
    - the maximum value of PduR_PduIdType */
#define PDUR_NO_MULTITP_SESSION_ASSIGNED 0xFFU


#if (defined PDUR_NO_GATETP_SESSION_ASSIGNED) /* to prevent double declaration */
#error PDUR_NO_GATETP_SESSION_ASSIGNED already defined
#endif /* if (defined PDUR_NO_GATETP_SESSION_ASSIGNED) */

/** \brief Macro definition for unassigned session - the maximum value of PduR_PduIdType */
#define PDUR_NO_GATETP_SESSION_ASSIGNED 0xFFFFU


#if (defined PDUR_NO_GATETP_QUEUEING_POSSIBLE) /* to prevent double declaration */
#error PDUR_NO_GATETP_QUEUEING_POSSIBLE already defined
#endif /* if (defined PDUR_NO_GATETP_QUEUEING_POSSIBLE) */

/** \brief Macro definition if TP gateway session can not be queued */
#define PDUR_NO_GATETP_QUEUEING_POSSIBLE 0xFFU


#if (defined PDUR_GATETPTHRESHOLD_DIRECT) /* to prevent double declaration */
#error PDUR_GATETPTHRESHOLD_DIRECT already defined
#endif /* if (defined PDUR_GATETPTHRESHOLD_DIRECT) */

/** \brief Macro definition for TpThreshold value used by direct routing */
#define PDUR_GATETPTHRESHOLD_DIRECT 0xFFFFU


#if (defined PDUR_GATETPQUEUE_FIRSTINDEX) /* to prevent double declaration */
#error PDUR_GATETPQUEUE_FIRSTINDEX already defined
#endif /* if (defined PDUR_GATETPQUEUE_FIRSTINDEX) */

/** \brief Macro definition of the array index holding the first of the queued TP gateway sessions */
#define PDUR_GATETPQUEUE_FIRSTINDEX 0U


#if (defined PDUR_SDU_LENGTH_ZERO) /* to prevent double declaration */
#error PDUR_SDU_LENGTH_ZERO already defined
#endif /* if (defined PDUR_SDU_LENGTH_ZERO) */

/** \brief Macro definition for SduLength used to return available data/buffer
  and to indicate that the current position shall not be rewound for retry */
#define PDUR_SDU_LENGTH_ZERO 0U


#if (defined PDUR_TP_SDU_LENGTH_UNKNOWN) /* to prevent double declaration */
#error PDUR_TP_SDU_LENGTH_UNKNOWN already defined
#endif /* if (defined PDUR_TP_SDU_LENGTH_UNKNOWN) */

/** \brief Macro definition for TpSduLength 0 to indicate unknown message length */
#define PDUR_TP_SDU_LENGTH_UNKNOWN 0U


#if (defined PDUR_TPBUFFER_LENGTH_ZERO) /* to prevent double declaration */
#error PDUR_TPBUFFER_LENGTH_ZERO already defined
#endif /* if (defined PDUR_TPBUFFER_LENGTH_ZERO) */

/** \brief Macro definition for length of TP buffer used if no TP buffer could be allocated  */
#define PDUR_TPBUFFER_LENGTH_ZERO 0U


#if (defined PDUR_LAST_MULTICAST_ENTRY_OF_PDUID) /* to prevent double declaration */
#error PDUR_LAST_MULTICAST_ENTRY_OF_PDUID already defined
#endif /* if (defined PDUR_LAST_MULTICAST_ENTRY_OF_PDUID) */

/** \brief Macro definition of final element of each multiplexed PDU ID in routing table is marked */
#define PDUR_LAST_MULTICAST_ENTRY_OF_PDUID 0U


#if (defined PDUR_GET_CONFIG_ADDR) /* to prevent double declaration */
#error PDUR_GET_CONFIG_ADDR already defined
#endif /* if (defined PDUR_GET_CONFIG_ADDR) */

/** \brief Define PDUR_GET_CONFIG_ADDR macro for getting a reference to a config element */
#define PDUR_GET_CONFIG_ADDR(type, offset) \
TS_UNCHECKEDGETCFG(PduR_gConfigPtr, type, PDUR, offset)


#if (defined PDUR_GET_RAM_ADDR) /* to prevent double declaration */
#error PDUR_GET_RAM_ADDR already defined
#endif /* if (defined PDUR_GET_RAM_ADDR) */

/** \brief Define PDUR_GET_RAM_ADDR macro to get a reference to a post-build RAM element */
#define PDUR_GET_RAM_ADDR(type, offset) \
TS_UNCHECKEDGETVAR(PduR_gMemPtr, type, PDUR, offset)


#if (PDUR_TPGATEWAY_SUPPORT == STD_ON)
/** \brief Bit position of flags of member Status of a multicast PduId reception session **/
/* values provided in order of appearance */
/* bit position set if reception of a multicast PduId shall be aborted */
#define PDUR_GATETP_ABORT_POS 3U
/* bit position set if reception has finished with TpRxIndication */
#define PDUR_GATETP_RECEPT_FIN_POS 2U
/* bit position set if all Transmit calls are completed */
#define PDUR_GATETP_TX_COMPLETE_POS 1U
/* bit position set if Tp gateway session is occupied */
#define PDUR_GATETP_OCCUPIED_SES_POS 0U

/** \brief Mask of element Status in TP gateway session **/
#define PDUR_GATETP_RST_STATUS_MSK        0x00U
#define PDUR_GATETP_NO_PEND_TXCONF_MSK    0x00U
#endif /*if (PDUR_TPGATEWAY_SUPPORT == STD_ON)*/


#if (PDUR_MULTICAST_UPTOLOTP_SUPPORT == STD_ON)
/** \brief Bit position of flags of member Status in multicast transmit session **/
/* bit position set if all Transmit calls are completed */
#define PDUR_MULTITPTX_TX_COMPLETE_POS 7U
/* bit position set if multicast transmission shall be aborted */
#define PDUR_MULTITPTX_ABORT_POS 6U
/* bit position set if first Up_CopyTxData is called for SduLength greater zero */
#define PDUR_MULTITPTX_1ST_COPYTX_POS 5U
/* bit position set if Up_CopyTxData is called (protection against concurrent calls) */
#define PDUR_MULTITPTX_UP_COPYTX_PROT_POS 4U

/** \brief Mask/value of element Status in multicast transmit session **/
#define PDUR_MULTITPTX_PENDTXCOUNT_MSK       0x0FU
#define PDUR_MULTITPTX_NO_PENDING_TX_MSK     0x00U
#define PDUR_MULTITPTX_RESET_STATUS_VAL      0x00U
#endif /*if (PDUR_MULTICAST_UPTOLOTP_SUPPORT == STD_ON)*/


/* provide assertion in the sense of defensive programming */
#if (defined PDUR_UNREACHABLE_CODE_ASSERT) /* to prevent double declaration */
#error PDUR_UNREACHABLE_CODE_ASSERT is already defined
#endif /* if (defined PDUR_UNREACHABLE_CODE_ASSERT) */

#if (PDUR_DEV_ERROR_DETECT == STD_ON)
#define PDUR_UNREACHABLE_CODE_ASSERT(SId) PDUR_DET_REPORT_ERROR(SId, PDUR_E_NULL_POINTER)
#endif

/*==================[type definitions]======================================*/

/*==================[external data]=========================================*/

/*==================[external function declarations]========================*/
#define PDUR_START_SEC_CODE
#include <MemMap.h>


/*------------------[multicast handler functions]---------------------------*/
#if (PDUR_ZERO_COST_OPERATION_IF == STD_OFF)
#if (PDUR_MULTICAST_FROMIF_SUPPORT == STD_ON)
/**
 ** \brief If-Multicast handler function
 **
 ** This function performs multicast operations on PDUs received from lower
 ** layer modules
 **
 **
 ** \param[in]  MPduId ID of multicast PDU
 ** \param[in]  PduInfoPtr    Contains the length (SduLength) of the received I-PDU
 **                           and a pointer to a buffer (SduDataPtr) containing the I-PDU.
 **/
extern FUNC(void,PDUR_CODE) PduR_MultiIfRxIndication
(
   PduIdType  MPduId,
   P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) PduInfoPtr
);
#endif

#if(PDUR_MULTICAST_TOIF_SUPPORT == STD_ON)
/**
 ** \brief If-Multicast handler function
 **
 ** This function performs multicast operations on I-PDUs sent by upper layer
 ** module &lt;Up&gt; to interface communication modules (e.g. CanIf).
 **
 **
 ** \param[in]  MPduId ID of multicast PDU
 ** \param[in]  PduInfoPtr    Pointer to a structure with PDU related data
 **                           that shall be transmitted: data length and
 **                           pointer to data buffer
 **
 ** \return Function execution success status
 ** \retval E_OK        Transmit request has been accepted by all the destinations
 ** \retval E_NOT_OK    At least one of the transmit requests was rejected.
 **
 **/
extern FUNC(Std_ReturnType,PDUR_CODE) PduR_MultiUpIfTransmit
(
   PduIdType MPduId,
   P2CONST(PduInfoType,AUTOMATIC,PDUR_APPL_DATA) PduInfoPtr
);
#endif

#if ((PDUR_IFGATEWAY_SUPPORT == STD_ON) && (PDUR_LOIF_STATPAYLOAD_ENABLED == STD_ON))
/*--------------[If-gateway handler functions for static I-PDU length optimization]----------------*/

#if (PDUR_SB_TX_BUFFER_SUPPORT == STD_ON)
/**
 ** \brief Gateway handler function (single buffer) for static I-PDU length optimization
 **
 ** This function performs gateway operations on PDUs using a single buffer
 **
 **
 ** \param[in]  GPduId ID of If-gateway PDU
 ** \param[in]  PduInfoPtr    Pointer to a structure with PDU related data
 **                           that shall be transmitted: data length and
 **                           pointer to data buffer.
 **/
extern FUNC(void,PDUR_CODE) PduR_GateIfRxIndicationSb
(
   PduIdType  GPduId,
   P2VAR(PduInfoType,AUTOMATIC,PDUR_APPL_DATA) PduInfoPtr
);
#endif

#if (PDUR_SB_TX_BUFFER_SUPPORT == STD_ON)
/**
 ** \brief Gateway handler function (single buffer) for static I-PDU length optimization
 **
 ** \param[in]  GPduId        ID of If-gateway PDU
 ** \param[in]  PduInfoPtr    Contains the length (SduLength) of the received I-PDU
 **                           and a pointer to a buffer (SduDataPtr) containing the I-PDU.
 **
 ** \return Function execution success status
 ** \retval E_OK        Transmit request has been accepted by all the destinations
 ** \retval E_NOT_OK    At least one of the transmit requests was rejected.
 **/
extern FUNC(Std_ReturnType, PDUR_CODE) PduR_GateIfTriggerTransmitSb
(
    PduIdType          GPduId,
    P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) PduInfoPtr
);
#endif

#if (PDUR_FIFO_TX_BUFFER_SUPPORT == STD_ON)
/**
 ** \brief Gateway handler function (D-FIFO buffer) for static I-PDU length optimization
 **
 ** This function performs gateway operations on PDUs using a D-FIFO buffer
 **
 **
 ** \param[in]  GPduId        ID of If-gateway PDU
 ** \param[in]  PduInfoPtr    Pointer to a structure with PDU related data
 **                           that shall be transmitted: data length and
 **                           pointer to data buffer.
 **/
extern FUNC(void,PDUR_CODE) PduR_GateIfRxIndicationDf
(
   PduIdType  GPduId,
   P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) PduInfoPtr
);
#endif

#if (PDUR_FIFO_TX_BUFFER_SUPPORT == STD_ON)
/**
 ** \brief Gateway handler function (D-FIFO buffer) for static I-PDU length optimization
 **
 ** This function performs gateway operations on PDUs using a D-FIFO buffer
 **
 ** \param[in]  GPduId ID of If-gateway PDU
 **/
extern FUNC(void,PDUR_CODE) PduR_GateIfTxConfirmationDf
(
    PduIdType  GPduId
);
#endif

#if (PDUR_FIFO_TX_BUFFER_SUPPORT == STD_ON)
/**
 ** \brief Gateway handler function (TT-FIFO buffer) for static I-PDU length optimization
 **
 ** This function performs gateway operations on PDUs using a TT-FIFO buffer
 **
 **
 ** \param[in]  GPduId        ID of If-gateway PDU
 ** \param[in]  PduInfoPtr    Pointer to a structure with PDU related data
 **                           that shall be transmitted: data length and
 **                           pointer to data buffer.
 **/
extern FUNC(void,PDUR_CODE) PduR_GateIfRxIndicationTf
(
   PduIdType  GPduId,
   P2VAR(PduInfoType,AUTOMATIC,PDUR_APPL_DATA) PduInfoPtr
);
#endif

#if (PDUR_FIFO_TX_BUFFER_SUPPORT == STD_ON)
/**
 ** \brief Gateway handler function (TT-FIFO buffer) for static I-PDU length optimization
 **
 ** This function performs gateway operations on PDUs using a TT-FIFO buffer
 **
 ** \param[in]  GPduId ID of If-gateway PDU
 **/
extern FUNC(void,PDUR_CODE) PduR_GateIfTxConfirmationTf
(
    PduIdType  GPduId
);
#endif

#if (PDUR_FIFO_TX_BUFFER_SUPPORT == STD_ON)
/**
 ** \brief Gateway handler function (TT-FIFO buffer) for static I-PDU length optimization
 **
 ** This function performs gateway operations on PDUs using a TT-FIFO buffer
 **
 ** \param[in]  GPduId        ID of If-gateway PDU
 ** \param[in]  PduInfoPtr    Contains the length (SduLength) of the received I-PDU
 **                           and a pointer to a buffer (SduDataPtr) containing the I-PDU.
 **
 ** \return Function execution success status
 ** \retval E_OK        Transmit request has been accepted by all the destinations
 ** \retval E_NOT_OK    At least one of the transmit requests was rejected.
 **/
extern FUNC(Std_ReturnType, PDUR_CODE) PduR_GateIfTriggerTransmitTf
(
    PduIdType          GPduId,
    P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) PduInfoPtr
);
#endif
#endif /* ((PDUR_IFGATEWAY_SUPPORT == STD_ON) && (PDUR_LOIF_STATPAYLOAD_ENABLED == STD_ON)) */
#endif /* (PDUR_ZERO_COST_OPERATION_IF == STD_OFF) */

#if (PDUR_ZERO_COST_OPERATION_TP == STD_OFF)
#if (PDUR_TPGATEWAY_SUPPORT == STD_ON)
/*------------------[Tp-gateway handler functions]---------------------------*/

/**
 ** \brief Tp-Gateway handler function
 **
 ** function called by StartOfReception function of the respective LoTp.
 **
 ** \param[in]  GMPduId             Identification of the received I-PDU.
 ** \param[in]  TpSduLength         Total length of the PDU to be received.
 ** \param[out] BufferSizePtr       Available receive buffer in the receiving module.
 **                                 This parameter will be used to compute the Block Size (BS) in
 **                                 the transport protocol module.
 **
 ** \return Result of buffer request
 ** \retval BUFREQ_OK        Connection has been accepted.
 **                          BufferSizePtr indicates the available receive buffer.
 **                          Reception is continued.
 ** \retval BUFREQ_E_OVFL    No Buffer of the required length can be provided. Reception is aborted.
 **                          BufferSizePtr remains unchanged.
 ** \retval BUFREQ_E_NOT_OK  Connection has been rejected. Reception is aborted.
 **                          BufferSizePtr remains unchanged.
 **
 **/
extern FUNC(BufReq_ReturnType, PDUR_CODE) PduR_GateTpStartOfReception
(
   PduIdType GMPduId,
   PduLengthType TpSduLength,
   P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) BufferSizePtr
);

/**
 ** \brief Tp-Gateway handler function
 **
 ** function called by CopyRxData function of the respective LoTp.
 **
 ** \param[in]  GMPduId             Identification of the received I-PDU.
 ** \param[in]  PduInfoPtr          Pointer to the buffer (SduDataPtr) and its length (SduLength)
 **                                 containing the data to be copied by PDU Router module in
 **                                 case of gateway or upper layer module in case of reception.
 ** \param[out] BufferSizePtr       Available receive buffer after data has been copied.
 **
 ** \return Result of buffer request
 ** \retval BUFREQ_OK        Data copied successfully.
 ** \retval BUFREQ_E_NOT_OK  Data was not copied because an error occurred.
 **
 **/
extern FUNC(BufReq_ReturnType, PDUR_CODE) PduR_GateTpCopyRxData
(
   PduIdType GMPduId,
   P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) PduInfoPtr,
   P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) BufferSizePtr
);


/**
 ** \brief Tp-Gateway handler function
 **
 ** This service is called by the transport protocol module after an I-PDU has been received
 ** successfully or when an error occurred. It is also used to confirm cancellation of an I-PDU.
 **
 ** \param[in]  GMPduId      Identification of the received I-PDU.
 ** \param[in]  Result       Result of the reception.
 **/
extern FUNC(void, PDUR_CODE) PduR_GateTpRxIndication
(
    PduIdType    GMPduId,
    NotifResultType  Result
);


/**
 ** \brief Tp-Gateway handler function
 **
 ** function called by CopyTxData function of the respective LoTp.
 **
 ** \param[in]  GMPduId             Identification of the transmitted I-PDU.
 ** \param[out] PduInfoPtr          Provides destination buffer and the number of bytes to copy.
 **                                 In case of gateway the PDU Router module will copy,
 **                                 otherwise the source upper layer module will copy the data.
 **                                 If not enough transmit data is available,
 **                                 no data is copied. The transport protocol module will retry.
 **                                 A copy size of 0 can be used to indicate state changes in the
 **                                 retry parameter.
 ** \param[in]  RetryInfoPtr        This parameter is used to retransmit data because problems
 **                                 during the last service call.
 **                                 If the I-PDU is transmitted from a local module (e.g. DCM) the
 **                                 PDU router module will just forward the parameter value
 **                                 without check. If the I-PDU is gatewayed from another bus,
 **                                 the PDU Router module will make the following interpretation:
 **                                 If the transmitted TP I-PDU does not support the retry feature
 **                                 a NULL_PTR is provided. It indicates that the copied transmit
 **                                 data can be removed from the buffer after it has been copied.
 **                                 If the retry feature is used by the Tx I-PDU, RetryInfoPtr must
 **                                 point to a valid RetryInfoType element.
 **                                 If TpDataState indicates TP_CONFPENDING, the previously
 **                                 copied data must remain in the TP buffer to be available for
 **                                 error recovery.
 **                                 TP_DATACONF indicates that all data that have been copied
 **                                 so far are confirmed and can be removed from the TP buffer.
 **                                 Data copied by this API call are excluded and will be
 **                                 confirmed later.
 **                                 TP_DATARETRY indicates that this API call shall copy
 **                                 already copied data in order to recover from an error. In this
 **                                 case AvailableDataPtr specifies the offset of the first byte to be
 **                                 copied by the API call.
 ** \param[out] AvailableDataPtr    Indicates the remaining number of bytes that are available in
 **                                 the PduR Tx buffer. AvailableDataPtr can be used by
 **                                 TP modules that support dynamic payload lengths (e.g. FlexRay
 **                                 ISO Transport Layer) to determine the size of the following CFs.
 **
 ** \return Result of buffer request
 ** \retval BUFREQ_OK        Data has been copied to the transmit buffer completely as requested.
 ** \retval BUFREQ_E_BUSY    Request could not be fulfilled, because the required amount of
 **                          Tx data is not available. TP layer might retry later on.
 **                          No data has been copied.
 ** \retval BUFREQ_E_NOT_OK  Data has not been copied. Request failed.
 **
 **/
extern FUNC(BufReq_ReturnType, PDUR_CODE) PduR_GateTpCopyTxData
(
   PduIdType GMPduId,
   P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) PduInfoPtr,
   P2VAR(RetryInfoType, AUTOMATIC, PDUR_APPL_DATA) RetryInfoPtr,
   P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) AvailableDataPtr
);


/**
 ** \brief Tp-Gateway handler function
 **
 ** function called by TxConfirmation function of the respective LoTp.
 **
 ** \param[in]  GMPduId           Tx-PDU ID of LoTp Module.
 ** \param[in]  Result            Result of the TP transmission.
 **/
extern FUNC(void, PDUR_CODE) PduR_GateTpTxConfirmation
(
   PduIdType   GMPduId,
   NotifResultType  Result
);


/**
 ** \brief Auxiliary TP gateway handler function
 **
 ** Auxiliary function that releases the TP gateway session allocated to GMPduId.
 **
 **
 ** \param[in]   pSessionInfo    pointer to allocated TP gateway session
 **/
TS_MOD_PRIV_DECL FUNC(void, PDUR_CODE) PduR_ReleaseGateTpSession
(
   CONSTP2VAR(PduR_GateTpSessionInfoType, AUTOMATIC, PDUR_VAR_NOINIT) pSessionInfo
);


/**
 ** \brief Auxiliary TP gateway handler function
 **
 ** Auxiliary function that releases the TP gateway queue of GMPduId.
 **
 ** \param[in]  GMPduId       Identification of the gateway (multicast) PDU.
 **/
TS_MOD_PRIV_DECL FUNC(void, PDUR_CODE) PduR_ReleaseGateTpQueue
(
   PduR_PduIdType GMPduId
);


/**
 ** \brief Auxiliary TP gateway handler function
 **
 ** Auxiliary function that determines the TP gateway session allocated to GMPduId.
 **
 ** \param[in]  GMPduId       Identification of the gateway (multicast) PDU.
 **
 ** \return Result of request for determination of the allocated TP gateway session.
 ** \retval PduR_GateTpSessionIndexType: Index of the allocated TP gateway session.
 **                                      PDUR_NO_GATETP_SESSION_ASSIGNED if no TP gateway session
 **                                      is associated.
 **/
TS_MOD_PRIV_DECL FUNC(PduR_GateTpSessionIndexType, PDUR_CODE) PduR_GetGateTpSessionInUse
(
   PduR_PduIdType GMPduId
);


/**
 ** \brief Auxiliary Tp gateway handler function
 **
 ** Auxiliary function that calculates the amount of available data in a
 ** TP buffer by the information provided by the associated TP gateway session.
 **
 ** \param[in] SessionIndex        Index of considered TP gateway session.
 **
 ** \return Result of request to calculate the available data.
 ** \retval PduR_PduLengthType: Data size available within the allocated TP buffer.
 **/
TS_MOD_PRIV_DECL FUNC(PduR_PduLengthType, PDUR_CODE) PduR_CalcAvailableDataSize
(
   PduR_GateTpSessionIndexType SessionIndex
);
#endif /* (PDUR_TPGATEWAY_SUPPORT == STD_ON) */


#if (PDUR_MULTICAST_LOTPTOUP_SUPPORT == STD_ON)
/**
 ** \brief TP gateway handler function
 **
 ** This function performs operations on an I-PDU received by a lower layer TP module
 ** and forwarded to a single upper layer module (e.g. Dcm) while the I-PDU is transmitted
 ** via the TP gateway as well.
 **
 ** \param[in]  RxPduId       RxPduId of upper layer module.
 ** \param[in]  PduInfoPtr    Pointer to a structure with PDU related data
 **                           that shall be transmitted: data length and
 **                           pointer to data buffer.
 **
 ** \return Function execution success status
 ** \retval E_OK        Transmit request has been accepted by all the destinations
 ** \retval E_NOT_OK    At least one of the transmit requests was rejected.
 **
 **/
extern FUNC(Std_ReturnType, PDUR_CODE) PduR_GateTpUpReception
(
   PduIdType RxPduId,
   P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) PduInfoPtr,
   PduR_RefToModuleAPI TargetAPIRef
);
#endif /* (PDUR_MULTICAST_LOTPTOUP_SUPPORT == STD_ON) */


#if (PDUR_MULTICAST_UPTOLOTP_SUPPORT == STD_ON)
/*------------------[Tp-multicast handler functions]---------------------------*/

/**
 ** \brief Tp-Multicast handler function
 **
 ** This function performs multicast operations on I-PDUs sent by an upper layer
 ** module &lt;Up&gt; to transport protocol modules (e.g. CanTp).
 **
 **
 ** \param[in]  MTpTxPduId    ID of Tp-multicast Transmit-PDU.
 ** \param[in]  PduInfoPtr    Pointer to a structure with PDU related data
 **                           that shall be transmitted: data length and
 **                           pointer to data buffer.
 **
 ** \return Function execution success status
 ** \retval E_OK        Transmit request has been accepted by all the destinations
 ** \retval E_NOT_OK    At least one of the transmit requests was rejected.
 **
 **/
extern FUNC(Std_ReturnType, PDUR_CODE) PduR_MultiTpTransmit
(
  PduIdType MTpTxPduId,
  P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) PduInfoPtr
);


/**
 ** \brief Tp-Multicast handler function
 **
 ** function called by CopyTxData function of the respective LoTp.
 **
 ** \param[in]  MTpTxPduId             Identification of the transmitted I-PDU.
 ** \param[out] PduInfoPtr          Provides destination buffer and the number of bytes to copy.
 **                                 In case of gateway the PDU Router module will copy,
 **                                 otherwise the source upper layer module will copy the data.
 **                                 If not enough transmit data is available, no data is copied.
 **                                 The transport protocol module will retry.
 **                                 A copy size of 0 can be used to indicate state changes in the
 **                                 retry parameter.
 ** \param[in]  RetryInfoPtr        This parameter is used to retransmit data because problems
 **                                 during the last service call.
 **                                 If the I-PDU is transmitted from a local module (e.g. DCM) the
 **                                 PDU router module will just forward the parameter value
 **                                 without check. If the I-PDU is gatewayed from another bus,
 **                                 the PDU Router module will make the following interpretation:
 **                                 If the transmitted TP I-PDU does not support the retry feature
 **                                 a NULL_PTR is provided. It indicates that the copied transmit
 **                                 data can be removed from the buffer after it has been copied.
 **                                 If the retry feature is used by the Tx I-PDU, RetryInfoPtr must
 **                                 point to a valid RetryInfoType element.
 **                                 If TpDataState indicates TP_CONFPENDING, the previously
 **                                 copied data must remain in the TP buffer to be available for
 **                                 error recovery.
 **                                 TP_DATACONF indicates that all data that have been copied
 **                                 so far are confirmed and can be removed from the TP buffer.
 **                                 Data copied by this API call are excluded and will be
 **                                 confirmed later.
 **                                 TP_DATARETRY indicates that this API call shall copy
 **                                 already copied data in order to recover from an error. In this
 **                                 case AvailableDataPtr specifies the offset of the first byte to be
 **                                 copied by the API call.
 ** \param[out] AvailableDataPtr    Indicates the remaining number of bytes that are available in
 **                                 the PduR Tx buffer. AvailableDataPtr can be used by
 **                                 TP modules that support dynamic payload lengths (e.g. FlexRay
 **                                 ISO Transport Layer) to determine the size of the following CFs.
 **
 ** \return Result of buffer request
 ** \retval BUFREQ_OK        Data has been copied to the transmit buffer completely as requested.
 ** \retval BUFREQ_E_BUSY    Request could not be fulfilled, because the required amount of
 **                          Tx data is not available. TP layer might retry later on.
 **                          No data has been copied.
 ** \retval BUFREQ_E_NOT_OK  Data has not been copied. Request failed.
 **
 **/
extern FUNC(BufReq_ReturnType, PDUR_CODE) PduR_MultiTpCopyTxData
(
   PduIdType MTpTxPduId,
   P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) PduInfoPtr,
   P2VAR(RetryInfoType, AUTOMATIC, PDUR_APPL_DATA) RetryInfoPtr,
   P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) AvailableDataPtr
);


/**
 ** \brief Tp-Multicast handler function
 **
 ** Generic function called by TxConfirmation function of the respective LoTp.
 **
 ** \param[in]  MTpTxPduId        Tx-PDU ID of LoTp Module.
 ** \param[in]  Result            Result of the TP transmission.
 **/
extern FUNC(void, PDUR_CODE) PduR_MultiTpTxConfirmation
(
   PduIdType   MTpTxPduId,
   NotifResultType  Result
);


/**
 ** \brief Auxiliary TP multicast handler function
 **
 ** Determines the multicast transmit session index of an ongoing transmission.
 ** If no multicast transmit session is assigned PDUR_NO_MULTITP_SESSION_ASSIGNED is returned.
 **
 ** \param[in]  MTpTxPduId  PduId group of multicast Transmit to LoTP(s)
 **
 ** \return     Multicast transmit session index of an ongoing transmission.
 ** \retval     uint8       Multicast transmit session index assigned
 **                         or PDUR_NO_MULTITP_SESSION_ASSIGNED if no session is assigned.
 **
 **/
TS_MOD_PRIV_DECL FUNC(uint8, PDUR_CODE) PduR_SearchMultiTpTxSessionIndex
(
  PduR_PduIdType MTpTxPduId
);


/**
 ** \brief Auxiliary TP multicast handler function
 **
 ** Releases multicast transmit session.
 **
 ** \param[in]  SessionIndex  Index of the multicast transmit session to be released
 **/
TS_MOD_PRIV_DECL FUNC(void, PDUR_CODE) PduR_ReleaseMultiTpTxSession
(
   uint8 SessionIndex
);

#endif /*if (PDUR_MULTICAST_UPTOLOTP_SUPPORT == STD_ON) */
#endif /* (PDUR_ZERO_COST_OPERATION_TP == STD_OFF) */

/*------------------[Generic If-functions]---------------------------*/
#if (PDUR_ZERO_COST_OPERATION_IF == STD_OFF)
#if (PDUR_LOIF_ENABLED == STD_ON)
/**
 ** \brief Generic RxIndication function
 **
 ** Generic function called by RxIndication function of the respective &lt;Lo&gt;-Module.
 **
 ** \param[in]  RxPduId           Rx-PDU ID of &lt;Lo&gt;-Module.
 ** \param[in]  PduInfoPtr        Contains the length (SduLength) of the received I-PDU
 **                               and a pointer to a buffer (SduDataPtr) containing the I-PDU.
 ** \param[in]  RTabLoIfConfigIdx Index referring to the configuration of the &lt;Lo&gt;-Module.
 **/
 extern FUNC(void,PDUR_CODE) PduR_GenericIfRxIndication
 (
   PduIdType   RxPduId,
   P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) PduInfoPtr,
   uint8 RTabLoIfConfigIdx
);
#endif /* (PDUR_LOIF_ENABLED == STD_ON) */

#if (PDUR_UPIF_ENABLED == STD_ON)
/**
 ** \brief Generic Transmit function
 **
 ** Generic function called by Transmit function of the respective Upper Module
 ** sending to interface module.
 **
 ** \param[in]  TxPduId           Tx-PDU ID of Upper Module.
 ** \param[in]  PduInfoPtr        Pointer to structure with PDU related data that shall be
                                  transmitted: data length and pointer to data buffer.
 ** \param[in]  RTabUpIfConfigIdx Index referring to the configuration of the Upper Module.
 **
 ** \return Function execution success status
 ** \retval E_OK        Transmit request has been accepted by all the destinations
 ** \retval E_NOT_OK    At least one of the transmit requests was rejected.
 **
 **/
extern FUNC(Std_ReturnType, PDUR_CODE) PduR_GenericIfTransmit
(
   PduIdType    TxPduId,
   P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) PduInfoPtr,
   uint8 RTabUpIfConfigIdx
);
#endif /* (PDUR_UPIF_ENABLED == STD_ON) */

#if (PDUR_LOIF_TRIGGERTX_ENABLED == STD_ON)
/**
 ** \brief Generic TriggerTransmit function
 **
 ** Generic function called by TriggerTransmit function of the respective LoIf.
 **
 ** \param[in]  TxPduId       Tx-PDU ID of LoIf Module.
 ** \param[in]  PduInfoPtr    Contains the length (SduLength) of the received I-PDU
 **                           and a pointer to a buffer (SduDataPtr) containing the I-PDU.
 ** \param[in]  RTabLoIfConfigIdx Index referring to the configuration of the LoIf-Module.
 **
 ** \return Function execution success status
 ** \retval E_OK        Transmit request has been accepted by all the destinations
 ** \retval E_NOT_OK    At least one of the transmit requests was rejected.
 **/
extern FUNC(Std_ReturnType, PDUR_CODE) PduR_GenericIfTriggerTransmit
(
   PduIdType    TxPduId,
   P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) PduInfoPtr,
   uint8 RTabLoIfConfigIdx
);
#endif /* (PDUR_LOIF_TRIGGERTX_ENABLED == STD_ON) */

#if (PDUR_LOIF_TXCONF_ENABLED == STD_ON)
/**
 ** \brief Generic TxConfirmation function
 **
 ** Generic function called by TxConfirmation function of the respective LoIf.
 **
 ** \param[in]  TxPduId           Tx-PDU ID of LoIf Module.
 ** \param[in]  RTabLoIfConfigIdx Index referring to the configuration of the LoIf-Module.
 **/
extern FUNC(void, PDUR_CODE) PduR_GenericIfTxConfirmation
(
   PduIdType    TxPduId,
   uint8 RTabLoIfConfigIdx
);
#endif /* (PDUR_LOIF_TXCONF_ENABLED == STD_ON) */
#endif /* (PDUR_ZERO_COST_OPERATION_IF == STD_OFF) */

/*------------------[Generic Cancel Rx/Tx and ChangeParameter-functions]---------------------------*/
#if (PDUR_ZERO_COST_OPERATION_TP == STD_OFF)
#if (PDUR_UPTP_CANCELTX_ENABLED == STD_ON)
/**
 ** \brief Generic CancelTransmit function
 **
 ** Generic request for cancellation of an ongoing transmission of an transport protocol module I-PDU.
 **
 ** \param[in]  TxPduId             Unique identifier of the I-PDU which transfer has to be canceled.
 ** \param[in]  RTabUpTpConfigIdx   Index referring to the configuration of the Upper Module.
 **
 ** \return Function execution success status
 ** \retval E_OK        request is accepted by the destination module.
 ** \retval E_NOT_OK    request is not accepted by the destination module.
 **/
extern FUNC(Std_ReturnType, PDUR_CODE) PduR_GenericTpCancelTransmit
(
    PduIdType TxPduId,
    uint8 RTabUpTpConfigIdx
);
#endif /* (PDUR_UPTP_CANCELTX_ENABLED == STD_ON) */

#if (PDUR_UPTP_CHANGEPARAM_ENABLED == STD_ON)
/**
 ** \brief Generic ChangeParameter function
 **
 ** Generic function called by ChangeParameter function of the respective upper layer module.
 **
 ** \param[in]  RxPduId             Rx-PDU ID of Up Module.
 ** \param[in]  TPParameter         The selected parameter that the request shall change.
 ** \param[in]  TPParameterValue    The new value of the parameter
 ** \param[in]  RTabUpTpConfigIdx   Index referring to the configuration of the upper Tp-Module.
 **
 ** \return Function execution success status
 ** \retval E_OK        request is accepted.
 ** \retval E_NOT_OK    request is not accepted.
 **/
extern FUNC(Std_ReturnType, PDUR_CODE) PduR_GenericTpChangeParameter
(
    PduIdType RxPduId,
    TPParameterType TPParameter,
    uint16 TPParameterValue,
    uint8 RTabUpTpConfigIdx
);
#endif /* (PDUR_UPTP_CHANGEPARAM_ENABLED == STD_ON) */

#if (PDUR_UPTP_CANCELRX_ENABLED == STD_ON)
/**
 ** \brief Generic CancelReceive function
 **
 ** Generic function called by CancelReceive function of the respective upper layer module.
 **
 ** \param[in]  RxPduId              Rx-PDU ID of Up Module.
 ** \param[in]  RTabUpTpConfigIdx    Index referring to the configuration of the upper Tp-Module.
 **
 ** \return Function execution success status
 ** \retval E_OK        request is accepted.
 ** \retval E_NOT_OK    request is not accepted.
 **/
extern FUNC(Std_ReturnType,PDUR_CODE) PduR_GenericTpCancelReceive
(
    PduIdType RxPduId,
    uint8 RTabUpTpConfigIdx
);
#endif /* (PDUR_UPTP_CANCELRX_ENABLED == STD_ON) */



#if (PDUR_LOTP_ENABLED == STD_ON)
/*---------------------------------[Generic Tp-functions]------------------------------------------*/

/**
 ** \brief Generic StartOfReception function
 **
 ** Generic function called by StartOfReception function of the respective LoTp.
 **
 ** \param[in]  RxPduId             Identification of the received I-PDU.
 ** \param[in]  TpSduLength         Total length of the PDU to be received.
 ** \param[out] BufferSizePtr       Available receive buffer in the receiving module.
 **                                 This parameter will be used to compute the Block Size (BS) in
 **                                 the transport protocol module.
 ** \param[in]  RTabLoTpConfigIdx   Index referring to the configuration of the LoTp-Module.
 **
 ** \return Result of buffer request
 ** \retval BUFREQ_OK        Connection has been accepted.
 **                          BufferSizePtr indicates the available receive buffer.
 **                          Reception is continued.
 ** \retval BUFREQ_E_OVFL    No Buffer of the required length can be provided. Reception is aborted.
 **                          BufferSizePtr remains unchanged.
 ** \retval BUFREQ_E_NOT_OK  Connection has been rejected. Reception is aborted.
 **                          BufferSizePtr remains unchanged.
 **
 **/
extern FUNC(BufReq_ReturnType, PDUR_CODE) PduR_GenericTpStartOfReception
(
   PduIdType RxPduId,
   PduLengthType TpSduLength,
   P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) BufferSizePtr,
   uint8 RTabLoTpConfigIdx
);


/**
 ** \brief Generic CopyRxData function
 **
 ** Generic function called by CopyRxData function of the respective LoTp.
 **
 ** \param[in]  RxPduId             Identification of the received I-PDU.
 ** \param[in]  PduInfoPtr          Pointer to the buffer (SduDataPtr) and its length (SduLength)
 **                                 containing the data to be copied by PDU Router module in
 **                                 case of gateway or upper layer module in case of reception.
 ** \param[out] BufferSizePtr       Available receive buffer after data has been copied.
 ** \param[in]  RTabLoTpConfigIdx   Index referring to the configuration of the LoTp-Module.
 **
 ** \return Result of buffer request
 ** \retval BUFREQ_OK        Data copied successfully.
 ** \retval BUFREQ_E_NOT_OK  Data was not copied because an error occurred.
 **
 **/
extern FUNC(BufReq_ReturnType, PDUR_CODE) PduR_GenericTpCopyRxData
(
   PduIdType RxPduId,
   P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) PduInfoPtr,
   P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) BufferSizePtr,
   uint8 RTabLoTpConfigIdx
);


/**
 ** \brief Generic RxIndication function
 **
 ** Generic function called by RxIndication function of the respective LoTp.
 **
 ** \param[in]  RxPduId             Rx-PDU ID of LoTp-Module.
 ** \param[in]  Result              Result of the TP reception.
 ** \param[in]  RTabLoTpConfigIdx   Index referring to the configuration of the LoTp-Module.
 **/
extern FUNC(void,PDUR_CODE) PduR_GenericTpRxIndication
(
   PduIdType   RxPduId,
   NotifResultType  Result,
   uint8 RTabLoTpConfigIdx
);


/**
 ** \brief Generic CopyTxData function
 **
 ** Generic function called by CopyTxData function of the respective LoTp.
 **
 ** \param[in]  TxPduId             Identification of the transmitted I-PDU.
 ** \param[out] PduInfoPtr          Provides destination buffer and the number of bytes to copy.
 **                                 In case of gateway the PDU Router module will copy,
 **                                 otherwise the source upper layer module will copy the data.
 **                                 If not enough transmit data is available, no data is copied.
 **                                 The transport protocol module will retry.
 **                                 A copy size of 0 can be used to indicate state changes in the
 **                                 retry parameter.
 ** \param[in]  RetryInfoPtr        This parameter is used to retransmit data because problems
 **                                 during the last service call.
 **                                 If the I-PDU is transmitted from a local module (e.g. DCM) the
 **                                 PDU router module will just forward the parameter value
 **                                 without check. If the I-PDU is gatewayed from another bus,
 **                                 the PDU Router module will make the following interpretation:
 **                                 If the transmitted TP I-PDU does not support the retry feature
 **                                 a NULL_PTR is provided. It indicates that the copied transmit
 **                                 data can be removed from the buffer after it has been copied.
 **                                 If the retry feature is used by the Tx I-PDU, RetryInfoPtr must
 **                                 point to a valid RetryInfoType element.
 **                                 If TpDataState indicates TP_CONFPENDING, the previously
 **                                 copied data must remain in the TP buffer to be available for
 **                                 error recovery.
 **                                 TP_DATACONF indicates that all data that have been copied
 **                                 so far are confirmed and can be removed from the TP buffer.
 **                                 Data copied by this API call are excluded and will be
 **                                 confirmed later.
 **                                 TP_DATARETRY indicates that this API call shall copy
 **                                 already copied data in order to recover from an error. In this
 **                                 case AvailableDataPtr specifies the offset of the first byte to be
 **                                 copied by the API call.
 ** \param[out] AvailableDataPtr    Indicates the remaining number of bytes that are available in
 **                                 the PduR Tx buffer. AvailableDataPtr can be used by
 **                                 TP modules that support dynamic payload lengths (e.g. FlexRay
 **                                 ISO Transport Layer) to determine the size of the following CFs.
 ** \param[in]  RTabLoTpConfigIdx   Index referring to the configuration of the LoTp-Module.
 **
 ** \return Result of buffer request
 ** \retval BUFREQ_OK        Data has been copied to the transmit buffer completely as requested.
 ** \retval BUFREQ_E_BUSY    Request could not be fulfilled, because the required amount of
 **                          Tx data is not available. TP layer might retry later on.
 **                          No data has been copied.
 ** \retval BUFREQ_E_NOT_OK  Data has not been copied. Request failed.
 **
 **/
extern FUNC(BufReq_ReturnType, PDUR_CODE) PduR_GenericTpCopyTxData
(
   PduIdType TxPduId,
   P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) PduInfoPtr,
   P2VAR(RetryInfoType, AUTOMATIC, PDUR_APPL_DATA) RetryInfoPtr,
   P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) AvailableDataPtr,
   uint8 RTabLoTpConfigIdx
);


/**
 ** \brief Generic TxConfirmation function
 **
 ** Generic function called by TxConfirmation function of the respective LoTp.
 **
 ** \param[in]  TxPduId           Tx-PDU ID of LoTp Module.
 ** \param[in]  Result            Result of the TP transmission.
 ** \param[in]  RTabLoTpConfigIdx Index referring to the configuration of the LoTp-Module.
 **/
extern FUNC(void,PDUR_CODE) PduR_GenericTpTxConfirmation
(
   PduIdType   TxPduId,
   NotifResultType  Result,
   uint8 RTabLoTpConfigIdx
);
#endif

#if (PDUR_UPTP_ENABLED == STD_ON)
/**
 ** \brief Generic Transmit function
 **
 ** Generic function called by Transmit function of the respective Upper Module
 ** sending to transport protocol module.
 **
 ** \param[in]  TxPduId           Tx-PDU ID of Upper Module.
 ** \param[in]  PduInfoPtr        Pointer to structure with PDU related data that shall be
                                  transmitted: data length and pointer to data buffer.
 ** \param[in]  RTabUpTpConfigIdx Index referring to the configuration of the Upper Module.
 **
 ** \return Function execution success status
 ** \retval E_OK        Transmit request has been accepted by all the destinations
 ** \retval E_NOT_OK    At least one of the transmit requests was rejected.
 **
 **/
extern FUNC(Std_ReturnType, PDUR_CODE) PduR_GenericTpTransmit
(
   PduIdType TxPduId,
   P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) PduInfoPtr,
   uint8 RTabUpTpConfigIdx
);
#endif
#endif /* (PDUR_ZERO_COST_OPERATION_TP == STD_OFF) */

#if (PDUR_ZERO_COST_OPERATION_IF == STD_OFF)
#if (PDUR_IFGATEWAY_SUPPORT == STD_ON)
/*--------------------------------------[If-gateway handler functions]---------------------------*/
/**
 ** \brief Gateway handler function (no buffer)
 **
 ** This function performs If-gateway operations on PDUs using no buffer.
 **
 **
 ** \param[in]  GPduId ID of If-gateway PDU
 ** \param[in]  PduInfoPtr    Pointer to a structure with PDU related data
 **                           that shall be transmitted: data length and
 **                           pointer to data buffer.
 **/
extern FUNC(void,PDUR_CODE) PduR_GateIfRxIndicationNb
(
   PduIdType  GPduId,
   P2VAR(PduInfoType,AUTOMATIC,PDUR_APPL_DATA) PduInfoPtr
);

#if (PDUR_SB_TX_BUFFER_SUPPORT == STD_ON)
/**
 ** \brief Gateway handler function (single buffer) from Lower Interface Module
 **
 ** This function performs If-gateway operations on variable length PDUs using single buffers.
 **
 **
 ** \param[in]  GPduId        ID of If-gateway PDU
 ** \param[in]  PduInfoPtr    Pointer to a structure with PDU related data
 **                           that shall be transmitted: data length and
 **                           pointer to data buffer.
 **/
extern FUNC(void,PDUR_CODE) PduR_GateIfRxIndicationSbDynPyld
(
   PduIdType  GPduId,
   P2VAR(PduInfoType,AUTOMATIC,PDUR_APPL_DATA) PduInfoPtr
);
#endif /* (PDUR_SB_TX_BUFFER_SUPPORT == STD_ON) */

#if (PDUR_FIFO_TX_BUFFER_SUPPORT == STD_ON)
/**
 ** \brief Gateway handler function (D-FIFO buffer) from Lower Interface Module
 **
 ** This function performs gateway operations on variable length PDUs
 ** using a D-FIFO buffer.
 **
 **
 ** \param[in]  GPduId        ID of If-gateway PDU
 ** \param[in]  PduInfoPtr    Pointer to a structure with PDU related data
 **                           that shall be transmitted: data length and
 **                           pointer to data buffer.
 **/
extern FUNC(void,PDUR_CODE) PduR_GateIfRxIndicationDfDynPyld
(
   PduIdType  GPduId,
   P2VAR(PduInfoType,AUTOMATIC,PDUR_APPL_DATA) PduInfoPtr
);
#endif /* (PDUR_FIFO_TX_BUFFER_SUPPORT == STD_ON) */

#if (PDUR_FIFO_TX_BUFFER_SUPPORT == STD_ON)
/**
 ** \brief Gateway handler function (T-FIFO buffer) from Lower Interface Module
 **
 ** This function performs If-gateway operations on variable length PDUs using T-FIFO buffers.
 **
 **
 ** \param[in]  GPduId        ID of If-gateway PDU
 ** \param[in]  PduInfoPtr    Pointer to a structure with PDU related data
 **                           that shall be transmitted: data length and
 **                           pointer to data buffer.
 **/
extern FUNC(void,PDUR_CODE) PduR_GateIfRxIndicationTfDynPyld
(
   PduIdType  GPduId,
   P2VAR(PduInfoType,AUTOMATIC,PDUR_APPL_DATA) PduInfoPtr
);
#endif /* (PDUR_FIFO_TX_BUFFER_SUPPORT == STD_ON) */

#if (PDUR_FIFO_TX_BUFFER_SUPPORT == STD_ON)
/**
 ** \brief Gateway handler function (D-FIFO buffer) from Lower Interface Module
 **
 ** This function performs gateway operations on variable length PDUs
 ** using a D-FIFO buffer.
 **
 ** \param[in]  GPduId  ID of If-gateway PDU
 **/
extern FUNC(void,PDUR_CODE) PduR_GateIfTxConfirmationDfDynPyld
(
    PduIdType  GPduId
);
#endif /* (PDUR_FIFO_TX_BUFFER_SUPPORT == STD_ON) */

#if (PDUR_FIFO_TX_BUFFER_SUPPORT == STD_ON)
/**
 ** \brief Gateway handler function (T-FIFO buffer) from Lower Interface Module
 **
 ** This function performs gateway operations on variable length PDUs
 ** using a T-FIFO buffer.
 **
 ** \param[in]  GPduId  ID of If-gateway PDU
 **/
extern FUNC(void,PDUR_CODE) PduR_GateIfTxConfirmationTfDynPyld
(
    PduIdType  GPduId
);
#endif /* (PDUR_FIFO_TX_BUFFER_SUPPORT == STD_ON) */

#if (PDUR_SB_TX_BUFFER_SUPPORT == STD_ON)
/**
 ** \brief Gateway handler function (single buffer) from Lower Interface Module
 **
 ** This function performs If-gateway operations on variable length PDUs using single buffers.
 **
 **
 ** \param[in]  GPduId        ID of If-gateway PDU
 ** \param[in]  PduInfoPtr    Contains the length (SduLength) of the received I-PDU
 **                           and a pointer to a buffer (SduDataPtr) containing the I-PDU.
 **
 ** \return Function execution success status
 ** \retval E_OK        Transmit request has been accepted by all the destinations
 ** \retval E_NOT_OK    At least one of the transmit requests was rejected.
 **/
extern FUNC(Std_ReturnType, PDUR_CODE) PduR_GateIfTriggerTransmitSbDynPyld
(
    PduIdType          GPduId,
    P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) PduInfoPtr
);
#endif /* (PDUR_SB_TX_BUFFER_SUPPORT == STD_ON) */

#if (PDUR_FIFO_TX_BUFFER_SUPPORT == STD_ON)
/**
 ** \brief Gateway handler function (T-FIFO buffer) from Lower Interface Module
 **
 ** This function performs gateway operations on variable length PDUs
 ** using a T-FIFO buffer.
 **
 ** \param[in]  GPduId        ID of If-gateway PDU
 ** \param[in]  PduInfoPtr    Contains the length (SduLength) of the received I-PDU
 **                           and a pointer to a buffer (SduDataPtr) containing the I-PDU.
 **
 ** \return Function execution success status
 ** \retval E_OK        Transmit request has been accepted by all the destinations
 ** \retval E_NOT_OK    At least one of the transmit requests was rejected.
 **/
extern FUNC(Std_ReturnType, PDUR_CODE) PduR_GateIfTriggerTransmitTfDynPyld
(
    PduIdType          GPduId,
    P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) PduInfoPtr
);
#endif /* (PDUR_FIFO_TX_BUFFER_SUPPORT == STD_ON) */
#endif /* (PDUR_IFGATEWAY_SUPPORT == STD_ON) */
#endif /* (PDUR_ZERO_COST_OPERATION_IF == STD_OFF) */

#define PDUR_STOP_SEC_CODE
#include <MemMap.h>
/*==================[internal function declarations]========================*/

/*==================[external constants]====================================*/

/*==================[internal constants]====================================*/

/*==================[internal data]=========================================*/

/*==================[external function definitions]=========================*/

/*==================[internal function definitions]=========================*/

#endif /* if !defined( PDUR_INTERNAL_STATIC_H ) */
/*==================[end of file]===========================================*/

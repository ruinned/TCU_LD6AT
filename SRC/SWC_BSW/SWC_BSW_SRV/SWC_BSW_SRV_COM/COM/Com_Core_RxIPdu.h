/**
 * \file
 *
 * \brief AUTOSAR Com
 *
 * This file contains the implementation of the AUTOSAR
 * module Com.
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2013 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */
#ifndef COM_CORE_RXIPDU_H_
#define COM_CORE_RXIPDU_H_
/*==================[inclusions]============================================*/


#include <TSAutosar.h>          /* EB specific standard types */
#include <Com_Api.h>                /* get module interface */

#if (COM_DEV_ERROR_DETECT == STD_ON)
#include <Det.h>                /* get development error tracer interface */
#endif /* (COM_DEV_ERROR_DETECT == STD_ON) */

/*==================[version check]=========================================*/

/*==================[macros]================================================*/

/*==================[type definitions]======================================*/

/*==================[external function declarations]========================*/

/*==================[internal function declarations]========================*/

/*==================[external constants]====================================*/

/*==================[internal constants]====================================*/

/*==================[external data]=========================================*/

/*==================[internal data]=========================================*/

/*==================[external function definitions]=========================*/

/*==================[internal function definitions]=========================*/


#define COM_START_SEC_CODE
#include <MemMap.h>


#if (COM_NOTIFY_RECEIVERS_ENABLE == STD_ON)

/** \brief Com_EB_NotifyReceivers
 * Notifies the receivers about the reception of an PDU. For signals within
 * the PDU Reception filtering is performed
 * \param[in] IPduPtr: pointer to the configuration of the PDU
 * \retval none
 */
TS_MOD_PRIV_DECL FUNC(void, COM_CODE) Com_EB_NotifyReceivers
(
   P2CONST(ComRxIPduType, AUTOMATIC, COM_APPL_CONST) IPduPtr
);

#endif /* (COM_NOTIFY_RECEIVERS_ENABLE == STD_ON) */



#if (COM_RX_TIMEOUT_FACTOR_AVAILABLE == STD_ON)

/** \brief Com_EB_RxDMQueue - "rewind" the RxDM timeout for an IPDU
 * This function starts a timeout for the Rx deadline monitoring of an IPDU
 * Preconditions:
 * - must only be invoked within a critical section
 * - prior to this call, the COM must be initialized.
 * \param[in] IPduPtr - reference to the I-Pdu configuration
 * \param[in] TimeOutOffset - value which shall be used for "rewind"
 * \retval None
 */
TS_MOD_PRIV_DECL FUNC(void, COM_CODE) Com_EB_RxDMQueue
(
   P2CONST(ComRxIPduType, AUTOMATIC, COM_APPL_CONST) IPduPtr,
   Com_RxDMNextDueTimeType TimeOutOffset
);

#endif /* (COM_RX_TIMEOUT_FACTOR_AVAILABLE == STD_ON) */


/** \brief Com_EB_HandleRxIPdu - handles a Rx IPdu
 * function which manages starting/stopping a Rx I-Pdu and enabling/disabling
 * RxDM of Rx I-Pdu.
 * Preconditions:
 * - prior to this call, the COM module shall be initialized
 *
 * \param[in] mode - type of action which should be performed
 * (COM_IPDUGROUP_CONTROL, COM_IPDUGROUP_RXDM_CONTROL)
 * \param[in] toBeActivated - state of start/stop or activate/de-activate RxDM
 * \param[in] IPduPtr - configuration of the I-Pdu
 * \param[in] Initialize - defines if the Pdu group should be initialized
 * in case of starting of Pdus
 * \param[in] IPduId - Id of the I-Pdu
 * \retval None
 */

TS_MOD_PRIV_DECL FUNC(void, COM_CODE)Com_EB_HandleRxIPdu
(
   Com_IpduGroupModeType mode,
   boolean toBeActivated,
#if (COM_RX_TIMEOUT_FACTOR_AVAILABLE == STD_ON)
   P2CONST(ComRxIPduType, AUTOMATIC, COM_APPL_CONST) IPduPtr,
#endif /* (COM_RX_TIMEOUT_FACTOR_AVAILABLE == STD_ON) */
   boolean Initialize,
   ComIPduRefType IPduId
);


/** \brief Com_EB_InitRxIPdu - initializes the specified Rx IPdu and the
 * Rx-Signals associated with it
 * \param[in] RxPduId -IPdu which should be initialized
 * \retval E_OK if init was successful
 * \retval E_NOT_OK if init failed (wrong configuration)
 */

TS_MOD_PRIV_DECL FUNC(uint8, COM_CODE) Com_EB_InitRxIPdu
(
   ComIPduRefType RxPduId
);


/** \brief Com_EB_CreateReadProp - initializes the internal
 * structure for the representation of an Rx-signal
 * Preconditions:
 * - prior to this call, the COM module shall be initialized
 * \param[out] ComReadPropPtr - pointer where the result shall be stored
 * \param[in] SignalPtr - pointer to the description of the Rx signal
 * \param[in] IPduPtr - pointer to the description of the I-PDU of the signal
 * \param[in] TakePtrROM - defines if the initial value shall be used
 * \retval None
 */
TS_MOD_PRIV_DECL FUNC(void, COM_CODE) Com_EB_CreateReadProp
(
   P2VAR(ComCommonReadPropType, AUTOMATIC, AUTOMATIC) ComReadPropPtr,
   P2CONST(ComRxSignalType, AUTOMATIC, COM_APPL_CONST) SignalPtr,
   P2CONST(ComRxIPduType, AUTOMATIC, COM_APPL_CONST) IPduPtr
#if (COM_VALUE_INIT_REPLACE == STD_ON)
   ,boolean TakePtrROM
#endif /* (COM_VALUE_INIT_REPLACE == STD_ON) */
);

#define COM_STOP_SEC_CODE
#include <MemMap.h>

#endif /* COM_CORE_RXIPDU_H_ */
/*==================[end of file]===========================================*/


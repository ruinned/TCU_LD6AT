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
#ifndef COM_CORE_IPDUGROUP_H_
#define COM_CORE_IPDUGROUP_H_
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


/** \brief Com_EB_HandlePduGroupRx - handle PDU groups
 * function which manages starting/stopping of Rx-Pdus and enabling/disabling
 * RxDM of Rx-Pdus
 * Preconditions:
 * - prior to this call, the COM module shall be initialized
 *
 * \param[in] mode - type of action which should be performed
 * (COM_IPDUGROUP_CONTROL, COM_IPDUGROUP_RXDM_CONTROL)
 * \param[in] ipduGroupVector - I-PDU group vector containing the activation
 * state (stopped = 0/ started = 1) for all IPdus.
 * \param[in] Initialize - defines if the Pdu group should be initialized
 * in case of starting of Pdus
 * \retval None
 */

TS_MOD_PRIV_DECL FUNC(void, COM_CODE) Com_EB_HandlePduGroupRx
(
   Com_IpduGroupModeType mode,
   Com_IpduGroupVector ipduGroupVector,
   boolean Initialize
);


/** \brief Com_EB_HandlePduGroupTx - handle PDU groups
 * function which manages starting/stopping of Tx-Pdus
 * Preconditions:
 * - prior to this call, the COM module shall be initialized
 *
 * \param[in] ipduGroupVector - I-PDU group vector containing the activation
 * state (stopped = 0/ started = 1) for all IPdus.
 * \param[in] Initialize - defines if the Pdu should be initialized
 * \retval None
 */

TS_MOD_PRIV_DECL FUNC(void, COM_CODE) Com_EB_HandlePduGroupTx
(
   Com_IpduGroupVector ipduGroupVector,
   boolean Initialize
);


#if (COM_DEV_ERROR_DETECT == STD_ON)

/** \brief Com_EB_CheckIpduGroupVevtor - checks if an I-Pdu group
 * vector is valid.
 * Preconditions:
 * - prior to this call, the COM module shall be initialized
 *
 * \param[in] ipduGroupVector vector to be checked
 * \retval E_OK if vector is correct
 * \retval E_NOT_OK if vector is not correct
 */

TS_MOD_PRIV_DECL FUNC(Std_ReturnType, COM_CODE) Com_EB_CheckIpduGroupVector
(
   Com_IpduGroupVector ipduGroupVector
);

#endif /* (COM_DEV_ERROR_DETECT == STD_ON) */

#define COM_STOP_SEC_CODE
#include <MemMap.h>



#endif /* COM_CORE_IPDUGROUP_H_ */
/*==================[end of file]===========================================*/


/**
 * \file
 *
 * \brief AUTOSAR FiM
 *
 * This file contains the implementation of the AUTOSAR
 * module FiM.
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2013 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */
#if (!defined FIM_H)
#define FIM_H

/*==================[includes]===============================================*/
/* !LINKSTO dsn.FiM.IncludeStr,1 */

#include <Std_Types.h>   /* AUTOSAR standard types */

#include <FiM_Version.h> /* This modules' version declarations */

#include <FiM_Cfg.h>     /* Generated module configuration */
#include <FiM_Types.h>

#include <Dem_Types.h>   /* Dem callback-related types */

/*==================[macros]=================================================*/

#if (defined FIM_INSTANCE_ID)
#error FIM_INSTANCE_ID already defined
#endif
/** \brief Id of instance of FiM */
#define FIM_INSTANCE_ID                 0U

/*------------------[error codes]--------------------------------------------*/
/* !LINKSTO FIM047,1 */

#if (defined FIM_E_WRONG_PERMISSION_REQ)
#error FIM_E_WRONG_PERMISSION_REQ already defined
#endif
/** \brief Error Code.
 **
 ** FiM_GetFunctionPermission() is called by the application (SW-C) before
 ** complete initialization. */
#define FIM_E_WRONG_PERMISSION_REQ      0x01U

#if (defined FIM_E_WRONG_TRIGGER_ON_EVENT)
#error FIM_E_WRONG_TRIGGER_ON_EVENT already defined
#endif
/** \brief Error Code.
 **
 ** Dem calls FiM before the FiM is initialized. */
#define FIM_E_WRONG_TRIGGER_ON_EVENT    0x02U

#if (defined FIM_E_FID_OUT_OF_RANGE)
#error FIM_E_FID_OUT_OF_RANGE already defined
#endif
/** \brief Error Code.
 **
 ** FiM_GetFunctionPermission() called with wrong FID. */
#define FIM_E_FID_OUT_OF_RANGE          0x03U

#if (defined FIM_E_EVENTID_OUT_OF_RANGE)
#error FIM_E_EVENTID_OUT_OF_RANGE already defined
#endif
/** \brief Error Code.
 **
 ** Dem calls FiM with wrong EventId. */
#define FIM_E_EVENTID_OUT_OF_RANGE      0x04U

#if (defined FIM_E_INVALID_POINTER)
#error FIM_E_INVALID_POINTER already defined
#endif
/** \brief Error Code.
 **
 ** API is invoked with NULL Pointer. */
#define FIM_E_INVALID_POINTER           0x05U

#if (defined FIM_E_UNINIT)
#error FIM_E_UNINIT already defined
#endif
/** \brief Error Code.
 **
 ** FiM is not initialized. */
#define FIM_E_UNINIT                    0x06U

/*------------------[macros for service IDs]---------------------------------*/

#if (defined FIM_SID_INIT)
#error FIM_SID_INIT already defined
#endif
/** \brief AUTOSAR API service ID.
 **
 ** Definition of service ID for FiM_Init(). */
#define FIM_SID_INIT                    0x00U

#if (defined FIM_SID_GET_FUNCTION_PERMISSION)
#error FIM_SID_GET_FUNCTION_PERMISSION already defined
#endif
/** \brief AUTOSAR API service ID.
 **
 ** Definition of service ID for FiM_GetFunctionPermission(). */
#define FIM_SID_GET_FUNCTION_PERMISSION 0x01U

#if (defined FIM_SID_DEM_TRIGGER_ON_EVENT)
#error FIM_SID_DEM_TRIGGER_ON_EVENT already defined
#endif
/** \brief AUTOSAR API service ID.
 **
 ** Definition of service ID for FiM_DemTriggerOnEventStatus(). */
#define FIM_SID_DEM_TRIGGER_ON_EVENT    0x02U

#if (defined FIM_SID_DEM_INIT)
#error FIM_SID_DEM_INIT already defined
#endif
/** \brief AUTOSAR API service ID.
 **
 ** Definition of service ID for FiM_DemInit(). */
#define FIM_SID_DEM_INIT                0x03U

#if (defined FIM_SID_GET_VERSION_INFO)
#error FIM_SID_GET_VERSION_INFO already defined
#endif
/** \brief AUTOSAR API service ID.
 **
 ** Definition of service ID for FiM_GetVersionInfo(). */
#define FIM_SID_GET_VERSION_INFO        0x04U

#if (defined FIM_SID_MAIN_FUNCTION)
#error FIM_SID_MAIN_FUNCTION already defined
#endif
/** \brief AUTOSAR API service ID.
 **
 ** Definition of service ID for FiM_MainFunction(). */
#define FIM_SID_MAIN_FUNCTION           0x05U

/*==================[external function declarations]=========================*/

#define FIM_START_SEC_CODE
#include <MemMap.h>

#if (FIM_VERSION_INFO_API == STD_ON)
/** \brief Return the modules version information
 **
 ** This function provides the information to module vendor ID, module ID and
 ** software version major.minor.patch
 **
 ** Precondition: ::FIM_VERSION_INFO_API = ::STD_ON
 **
 ** \param[out]  VersionInfoPtr  Pointer to struct to be filled with the version
 **                              information
 **
 ** \ServiceID{::FIM_SID_GET_VERSION_INFO}
 ** \Reentrancy{Reentrant}
 ** \Synchronicity{Synchronous} */
extern FUNC(void, FIM_CODE) FiM_GetVersionInfo
(
  P2VAR(Std_VersionInfoType, AUTOMATIC, FIM_APPL_DATA) VersionInfoPtr
);
#endif

/*---------------[Interface ECU State Manager <--> FiM]----------------------*/

/** \brief Initializes the FiM.
 **
 ** This function initializes the FiM module.
 **
 ** Precondition: none
 **
 ** \param[in] FiMConfigPtr  refer to ::FiM_ConfigType
 **
 ** \ServiceID{::FIM_SID_INIT}
 ** \Reentrancy{Non-Reentrant}
 ** \Synchronicity{Synchronous} */
extern FUNC(void, FIM_CODE) FiM_Init(
  P2CONST(FiM_ConfigType, AUTOMATIC, FIM_APPL_CONST) FiMConfigPtr);

/*------------------[Scheduled functions]------------------------------------*/

#if (FIM_EVENT_UPDATE_TRIGGERED_BY_DEM == STD_OFF)
/** \brief This function is used to evaluate permission states cyclically.
 **
 ** Cyclic evaluation of the permission state of the fid is done using this
 ** function.
 ** Precondition: ::FIM_EVENT_UPDATE_TRIGGERED_BY_DEM = ::STD_OFF
 **
 ** \ServiceID{::FIM_SID_MAIN_FUNCTION} */
extern FUNC(void, FIM_CODE) FiM_MainFunction(void);
#endif

/*------------------[Interface SW-Components <--> FiM]-----------------------*/

#if (FIM_INCLUDE_RTE == STD_OFF)

/** \brief Reports the permission state to the functionality.
 **
 ** The SW Components and the BSW shall use this function
 ** to query for the permission to execute a certain functionality
 ** represented by the respective FID.
 **
 ** Precondition: none
 **
 ** \param[in]  FID  Identification of a functionality by assigned FID.
 **                  The FunctionId is configured in the FiM.
 ** \param[out]  Permission  Pointer to permission to be filled with the
 **                          permission information
 **
 ** \return success of operation
 ** \retval E_OK       request is accepted
 ** \retval E_NOT_OK   request is not accepted
 **
 ** \ServiceID{::FIM_SID_GET_FUNCTION_PERMISSION}
 ** \Reentrancy{Reentrant}
 ** \Synchronicity{Synchronous} */
extern FUNC(Std_ReturnType, FIM_CODE) FiM_GetFunctionPermission
(
  FiM_FunctionIdType                       FID,
  P2VAR(boolean, AUTOMATIC, FIM_APPL_DATA) Permission
);

#endif /* (FIM_INCLUDE_RTE == STD_OFF) */

/*------------------[Interface Dem <--> FiM]---------------------------------*/

#if (FIM_EVENT_UPDATE_TRIGGERED_BY_DEM == STD_ON)
/** \brief This service to be provided to the Dem in order to call FiM upon
 ** status changes.
 **
 ** The module Dem shall call this function whenever the status of an events
 ** changes.
 **
 ** Precondition: ::FIM_EVENT_UPDATE_TRIGGERED_BY_DEM = ::STD_ON
 **
 ** \param[in]  EventId  Identification of an Event by assigned event number.
 **                      The Event Number is configured in the Dem.
 ** \param[in]  EventStatusOld  Extended event status before change
 ** \param[in]  EventStatusNew  Detected / reported of event status
 **
 ** \ServiceID{::FIM_SID_DEM_TRIGGER_ON_EVENT}
 ** \Reentrancy{Reentrant}
 ** \Synchronicity{Synchronous} */
extern FUNC(void, FIM_CODE) FiM_DemTriggerOnEventStatus
(
  Dem_EventIdType EventId,
  uint8           EventStatusOld,
  uint8           EventStatusNew
);
#endif

/** \brief This service re-initializes the FiM.
 **
 ** The Dem shall call this function to re-initialize the FiM module in case
 ** the Dem detects a status change of a certain number of events.
 **
 ** Precondition: none
 **
 ** \ServiceID{::FIM_SID_DEM_INIT}
 ** \Reentrancy{Non-Reentrant}
 ** \Synchronicity{Synchronous} */
extern FUNC(void, FIM_CODE) FiM_DemInit(void);

#define FIM_STOP_SEC_CODE
#include <MemMap.h>

/*==================[internal function declarations]=========================*/

/*==================[external constants]=====================================*/

/*==================[internal constants]=====================================*/

/*==================[external data]==========================================*/

/*==================[internal data]==========================================*/

/*==================[external function definitions]==========================*/

/*==================[internal function definitions]==========================*/

#endif /* if !defined( FIM_H ) */
/*==================[end of file]============================================*/

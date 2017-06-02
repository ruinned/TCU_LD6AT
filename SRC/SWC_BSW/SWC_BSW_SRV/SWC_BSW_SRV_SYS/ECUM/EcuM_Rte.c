/**
 * \file
 *
 * \brief AUTOSAR EcuM
 *
 * This file contains the implementation of the AUTOSAR
 * module EcuM.
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2013 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

/*  MISRA-C:2004 Deviation List
 *
 *  MISRA-1) Deviated Rule: 19.6 (required)
 *     #undef shall not be used
 *
 *     Reason:
 *     The macro names used for memory mapping are different between
 *     AUTOSAR 3.x and AUTOSAR 4.x. For sake of compatibility between
 *     these worlds, both macros are defined.
 *     Since only one of them will be undefined within the MemMap.h file,
 *     all macros are undefined after the memory section ends.
 *     This avoids possible redundant macro definitions.
 *
 *  MISRA-2) Deviated Rule: 16.4 (required)
 *     The identifiers used in the declaration and definition of a function
 *     shall be identical.
 *
 *     Reason:
 *     The requirement 'EcuM3011' defines the arguments of EcuM_ShutdownTarget
 *     (ClientServerInterface EcuM_ShutdownTarget) as 'target' and 'mode' but
 *     the EcuM API specification defines the arguments as 'shutdownTarget' and
 *     'sleepMode' respectively. This issue has been reported in
 *     http://www.autosar.org/bugzilla/show_bug.cgi?id=58147
 */

/* !LINKSTO EcuM.EB.ASR32.EcuM016,1 */
/*==================[inclusions]============================================*/

#include <Std_Types.h>          /* AUTOSAR standard types */

/* define guard symbol to prevent redundant declaration of RTE symbols */
#define ECUM_INTERNAL_USE
/* !LINKSTO EcuM.EB.ASR32.EcuM017,1 */
#include <EcuM_BSW.h>    /* own API */
#include <EcuM_Int.h>    /* Internal declarations */

/* !LINKSTO EcuM2862,1 */
#include <SchM_EcuM.h>           /* SchM API for EcuM */
#include <Rte_Main.h>

#if (ECUM_INCLUDE_RTE == STD_ON)
/* !LINKSTO EcuM.EB.ASR32.EcuM017,1 */
#include <Rte_EcuM.h> /* API for EcuM as SW-C */
#endif

/*==================[macros]=====================================================================*/

#if (ECUM_INCLUDE_RTE == STD_ON)
/* check if expected State defines and typdefs are generated by the Rte */
# if !defined(ECUM_STATE_STARTUP)
#  error Rte usage is switched on for the EcuM but the \
Rte_EcuM_Type.h does not \
provide the required symbols.  This happens if the EcuM SWCD was not imported \
into the Rte configuration.  Import the swcd/EcuM_swc_*.arxml files with the \
system description importer and regenerate the project to solve this problem.
# endif

/* check if expected BootTarget defines and typdefs are generated by the Rte */
# if !defined(ECUM_BOOT_TARGET_APP)
#  error Rte usage is switched on for the EcuM but the \
Rte_EcuM_Type.h does not \
provide the required symbols.  This happens if the EcuM SWCD was not imported \
into the Rte configuration.  Import the swcd/EcuM_swc_*.arxml files with the \
system description importer and regenerate the project to solve this problem.
# endif

/** \brief number of mode mappings */
#define ECUM_EB_RTE_NUM_MODES 6U

# endif

/*==================[type definitions]======================================*/

/*==================[external function declarations]========================*/

/*==================[internal function declarations]========================*/

/*==================[external constants]====================================*/

/*==================[internal constants]====================================*/

#if (ECUM_INCLUDE_RTE == STD_ON)
#if (ECUM_ECUM_FIXED_SUPPORT == STD_ON)
#if (ECUM_EB_DEFAULT_ASR_SERVICE_API != ECUM_EB_SERVICE_API_NONE)

#define ECUM_START_SEC_CONST_8BIT
#define ECUM_START_SEC_CONST_8
#include <MemMap.h>

/* \brief map between EcuM's internal state defines and RTE defined modes
 *
 * This mapping table is needed as RTE mode type is generated in alphabetical
 * order whereas the EcuM states has "logical" order as well as decoupling
 * BSW code from RTE code. */
STATIC CONST(uint8, ECUM_CONST) EcuM_EB_RteModeMap[ECUM_EB_RTE_NUM_MODES] =
{
  RTE_MODE_EcuM_Mode_STARTUP,     /* ECUM_EB_MODE_STARTUP */
  RTE_MODE_EcuM_Mode_RUN,         /* ECUM_EB_MODE_RUN */
  RTE_MODE_EcuM_Mode_POST_RUN,    /* ECUM_EB_MODE_SHUTDOWN */
  RTE_MODE_EcuM_Mode_SHUTDOWN,    /* ECUM_EB_MODE_SLEEP */
  RTE_MODE_EcuM_Mode_SLEEP,       /* ECUM_EB_MODE_SLEEP */
  RTE_MODE_EcuM_Mode_WAKE_SLEEP   /* ECUM_EB_MODE_WAKE_SLEEP */
};

#define ECUM_STOP_SEC_CONST_8BIT
#define ECUM_STOP_SEC_CONST_8
#include <MemMap.h>
/* Deviation MISRA-1 <+4> */
#undef ECUM_START_SEC_CONST_8BIT
#undef ECUM_START_SEC_CONST_8
#undef ECUM_STOP_SEC_CONST_8BIT
#undef ECUM_STOP_SEC_CONST_8

#endif /* (ECUM_EB_DEFAULT_ASR_SERVICE_API != ECUM_EB_SERVICE_API_NONE) */
#endif /* (ECUM_ECUM_FIXED_SUPPORT == STD_ON) */
#endif /* (ECUM_INCLUDE_RTE == STD_ON) */

/*==================[external data]=========================================*/

/*==================[internal data]=========================================*/

/*==================[external function definitions]=========================*/

#if (ECUM_INCLUDE_RTE == STD_ON)
#if (ECUM_EB_DEFAULT_ASR_SERVICE_API != ECUM_EB_SERVICE_API_NONE)

#define ECUM_START_SEC_CODE
#include <MemMap.h>

#if (ECUM_ECUM_FIXED_SUPPORT == STD_ON)
FUNC(void, ECUM_CODE) EcuM_RteModeSwitch(uint8 mode)
{
  /* Return value is ignored because mode switch indication to Rte is compliant to a
   * fire and forget policy from EcuM's point of view. */
  (void)Rte_Switch_currentMode_currentMode(EcuM_EB_RteModeMap[mode]);
}

#endif /* (ECUM_ECUM_FIXED_SUPPORT == STD_ON) */

#if (ECUM_EB_DEFAULT_ASR_SERVICE_API == ECUM_EB_SERVICE_API_ASR32)
#if (ECUM_ECUM_FIXED_SUPPORT == STD_ON)

FUNC(Std_ReturnType, ECUM_CODE) EcuM_Rte_RequestRUN(EcuM_UserType user)
{
  /* !LINKSTO EcuM.EB.ASR32.EcuM111,1 */
  return EcuM_ASR32_RequestRUN(user);
}

FUNC(Std_ReturnType, ECUM_CODE) EcuM_Rte_ReleaseRUN(EcuM_UserType user)
{
  return EcuM_ASR32_ReleaseRUN(user);
}

FUNC(Std_ReturnType, ECUM_CODE) EcuM_Rte_RequestPOST_RUN(EcuM_UserType user)
{
  return EcuM_ASR32_RequestPOST_RUN(user);
}

FUNC(Std_ReturnType, ECUM_CODE) EcuM_Rte_ReleasePOST_RUN(EcuM_UserType user)
{
  return EcuM_ASR32_ReleasePOST_RUN(user);
}
#endif /* (ECUM_ECUM_FIXED_SUPPORT == STD_ON) */

FUNC(Std_ReturnType, ECUM_CODE) EcuM_Rte_SelectShutdownTarget
(
    EcuM_StateType target,
    uint8          mode
)
{
  /* !LINKSTO EcuM.EB.ASR32.EcuM111,1 */
  return EcuM_ASR32_SelectShutdownTarget(target, mode);
}

/* Deviation MISRA-2 */
FUNC(Std_ReturnType, ECUM_CODE) EcuM_Rte_GetShutdownTarget
(
    P2VAR(EcuM_StateType, AUTOMATIC, ECUM_APPL_DATA) shutdownTarget,
    P2VAR(uint8, AUTOMATIC, ECUM_APPL_DATA)          sleepMode
)
{
  /* !LINKSTO EcuM.EB.ASR32.EcuM111,1 */
  return EcuM_ASR32_GetShutdownTarget(shutdownTarget, sleepMode);
}

/* Deviation MISRA-2 */
FUNC(Std_ReturnType, ECUM_CODE) EcuM_Rte_GetLastShutdownTarget
(
    P2VAR(EcuM_StateType, AUTOMATIC, ECUM_APPL_DATA) shutdownTarget,
    P2VAR(uint8, AUTOMATIC, ECUM_APPL_DATA)          sleepMode
)
{
  /* !LINKSTO EcuM.EB.ASR32.EcuM111,1 */
  return EcuM_ASR32_GetLastShutdownTarget(shutdownTarget, sleepMode);
}

FUNC(Std_ReturnType,ECUM_CODE) EcuM_Rte_SelectBootTarget
(
    EcuM_BootTargetType target
)
{
  /* !LINKSTO EcuM.EB.ASR32.EcuM111,1 */
  return EcuM_ASR32_SelectBootTarget(target);
}

FUNC(Std_ReturnType,ECUM_CODE) EcuM_Rte_GetBootTarget
(
    P2VAR(EcuM_ASR32_BootTargetType, AUTOMATIC, RTE_APPL_DATA) target
)
{
  /* !LINKSTO EcuM.EB.ASR32.EcuM111,1 */
  return EcuM_ASR32_GetBootTarget(target);
}

#elif  (ECUM_EB_DEFAULT_ASR_SERVICE_API == ECUM_EB_SERVICE_API_ASR40)

#if (ECUM_ECUM_FIXED_SUPPORT == STD_ON)
FUNC(Std_ReturnType, ECUM_CODE) EcuM_Rte_RequestRUN(EcuM_UserType user)
{
  /* !LINKSTO EcuM.EB.ASR32.EcuM111,1 */
  return EcuM_ASR40_RequestRUN(user);
}

FUNC(Std_ReturnType, ECUM_CODE) EcuM_Rte_ReleaseRUN(EcuM_UserType user)
{
  return EcuM_ASR40_ReleaseRUN(user);
}

FUNC(Std_ReturnType, ECUM_CODE) EcuM_Rte_RequestPOST_RUN(EcuM_UserType user)
{
  return EcuM_ASR40_RequestPOST_RUN(user);
}

FUNC(Std_ReturnType, ECUM_CODE) EcuM_Rte_ReleasePOST_RUN(EcuM_UserType user)
{
  return EcuM_ASR40_ReleasePOST_RUN(user);
}
#endif /* (ECUM_ECUM_FIXED_SUPPORT == STD_ON) */

FUNC(Std_ReturnType, ECUM_CODE) EcuM_Rte_SelectShutdownTarget
(
    EcuM_StateType target,
    uint8          mode
)
{
  /* !LINKSTO EcuM.EB.ASR32.EcuM110,1 */
  return EcuM_ASR40_SelectShutdownTarget(target, mode);
}

/* Deviation MISRA-2 */
FUNC(Std_ReturnType, ECUM_CODE) EcuM_Rte_GetShutdownTarget
(
    P2VAR(EcuM_StateType, AUTOMATIC, ECUM_APPL_DATA) shutdownTarget,
    P2VAR(uint8, AUTOMATIC, ECUM_APPL_DATA)          sleepMode
)
{
  /* !LINKSTO EcuM.EB.ASR32.EcuM110,1 */
  return EcuM_ASR40_GetShutdownTarget(shutdownTarget, sleepMode);
}

/* Deviation MISRA-2 */
FUNC(Std_ReturnType, ECUM_CODE) EcuM_Rte_GetLastShutdownTarget
(
    P2VAR(EcuM_StateType, AUTOMATIC, ECUM_APPL_DATA) shutdownTarget,
    P2VAR(uint8, AUTOMATIC, ECUM_APPL_DATA)          sleepMode
)
{
  /* !LINKSTO EcuM.EB.ASR32.EcuM110,1 */
  return EcuM_ASR40_GetLastShutdownTarget(shutdownTarget, sleepMode);
}

FUNC(Std_ReturnType, ECUM_CODE) EcuM_Rte_SelectShutdownCause
(
  EcuM_ShutdownCauseType target
)
{
  /* !LINKSTO EcuM.EB.ASR32.EcuM110,1 */
  return EcuM_ASR40_SelectShutdownCause(target);
}

/* Deviation MISRA-2 */
FUNC(Std_ReturnType, ECUM_CODE) EcuM_Rte_GetShutdownCause
(
  P2VAR(EcuM_ShutdownCauseType, AUTOMATIC, ECUM_APPL_DATA) shutdownCause
)
{
  /* !LINKSTO EcuM.EB.ASR32.EcuM110,1 */
  return EcuM_ASR40_GetShutdownCause(shutdownCause);
}

FUNC(Std_ReturnType, ECUM_CODE) EcuM_Rte_GetMostRecentShutdown
(
  P2VAR(EcuM_StateType, AUTOMATIC, ECUM_APPL_DATA)         target,
  P2VAR(uint8, AUTOMATIC, ECUM_APPL_DATA)                  mode,
  P2VAR(EcuM_ShutdownCauseType, AUTOMATIC, ECUM_APPL_DATA) cause,
  P2VAR(uint32, AUTOMATIC, ECUM_APPL_DATA)                 time
)
{
  /* !LINKSTO EcuM.EB.ASR32.EcuM110,1 */
  return EcuM_ASR40_GetMostRecentShutdown(target, mode, cause, time);
}

FUNC(Std_ReturnType, ECUM_CODE) EcuM_Rte_GetNextRecentShutdown
(
  P2VAR(EcuM_StateType, AUTOMATIC, ECUM_APPL_DATA)         target,
  P2VAR(uint8, AUTOMATIC, ECUM_APPL_DATA)                  mode,
  P2VAR(EcuM_ShutdownCauseType, AUTOMATIC, ECUM_APPL_DATA) cause,
  P2VAR(uint32, AUTOMATIC, ECUM_APPL_DATA)                 time
)
{
  /* !LINKSTO EcuM.EB.ASR32.EcuM110,1 */
  return EcuM_ASR40_GetNextRecentShutdown(target, mode, cause, time);
}

FUNC(Std_ReturnType,ECUM_CODE) EcuM_Rte_SelectBootTarget
(
    EcuM_BootTargetType target
)
{
  /* !LINKSTO EcuM.EB.ASR32.EcuM110,1 */
  return EcuM_ASR40_SelectBootTarget(target);
}

FUNC(Std_ReturnType,ECUM_CODE) EcuM_Rte_GetBootTarget
(
    P2VAR(EcuM_BootTargetType, AUTOMATIC, RTE_APPL_DATA) target
)
{
  /* !LINKSTO EcuM.EB.ASR32.EcuM110,1 */
  return EcuM_ASR40_GetBootTarget(target);
}

#endif /* (ECUM_EB_DEFAULT_ASR_SERVICE_API == ECUM_EB_SERVICE_API_ASR32) */

#define ECUM_STOP_SEC_CODE
#include <MemMap.h>

#endif /* (ECUM_EB_DEFAULT_ASR_SERVICE_API != ECUM_EB_SERVICE_API_NONE) */
#endif /* (ECUM_INCLUDE_RTE == STD_ON) */

/*==================[internal function definitions]=========================*/

FUNC(void, ECUM_CODE) EcuM_SchM_Init(void)
{
  /* SchM function has no return value */
  SchM_Init();
}

FUNC(void, ECUM_CODE) EcuM_SchM_Deinit(void)
{
  /* SchM function has no return value */
  SchM_Deinit();
}

FUNC(void, ECUM_CODE) EcuM_Enter_SCHM_ECUM_EXCLUSIVE_AREA_0 (void)
{
  /* SchM function has no return value */
  SchM_Enter_EcuM_SCHM_ECUM_EXCLUSIVE_AREA_0();
}

FUNC(void, ECUM_CODE) EcuM_Exit_SCHM_ECUM_EXCLUSIVE_AREA_0 (void)
{
  /* SchM function has no return value */
  SchM_Exit_EcuM_SCHM_ECUM_EXCLUSIVE_AREA_0();
}

/*==================[end of file]===========================================*/

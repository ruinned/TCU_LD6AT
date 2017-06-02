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



/*
 * Misra-C:2004 Deviations:
 *
 * MISRA-1) Deviated Rule: 11.3 (advisory)
 * A cast should not be performed between a pointer type and an integral type.
 *
 * Reason:
 * In order to compare a pointer against an invalid value (NULL_PTR) a conversion of an integral
 * into an pointer is required.
 */

/*==================[inclusions]============================================*/
#include <TSAutosar.h>          /* EB specific standard types */
#include <ComStack_Types.h>     /* AUTOSAR Standard types */
#include <Com_Api.h>                /* module' public API */
#include <Com_Priv.h>           /* module' public API */
#include <Com_Version.h>        /* Module version declarations */


/*==================[macros]================================================*/

/*------------------[AUTOSAR vendor identification check]-------------------*/

#if (!defined COM_VENDOR_ID) /* configuration check */
#error COM_VENDOR_ID must be defined
#endif

#if (COM_VENDOR_ID != 1U) /* vendor check */
#error COM_VENDOR_ID has wrong vendor id
#endif

/*------------------[AUTOSAR release version identification check]----------*/

#if (!defined COM_AR_RELEASE_MAJOR_VERSION) /* configuration check */
#error COM_AR_RELEASE_MAJOR_VERSION must be defined
#endif

/* major version check */
#if (COM_AR_RELEASE_MAJOR_VERSION != 4U)
#error COM_AR_RELEASE_MAJOR_VERSION wrong (!= 4U)
#endif

#if (!defined COM_AR_RELEASE_MINOR_VERSION) /* configuration check */
#error COM_AR_RELEASE_MINOR_VERSION must be defined
#endif

/* minor version check */
#if (COM_AR_RELEASE_MINOR_VERSION != 0U )
#error COM_AR_RELEASE_MINOR_VERSION wrong (!= 0U)
#endif

#if (!defined COM_AR_RELEASE_REVISION_VERSION) /* configuration check */
#error COM_AR_RELEASE_REVISION_VERSION must be defined
#endif

/* revision version check */
#if (COM_AR_RELEASE_REVISION_VERSION != 3U )
#error COM_AR_RELEASE_REVISION_VERSION wrong (!= 3U)
#endif

/*------------------[AUTOSAR module version identification check]-----------*/

#if (!defined COM_SW_MAJOR_VERSION) /* configuration check */
#error COM_SW_MAJOR_VERSION must be defined
#endif

/* major version check */
#if (COM_SW_MAJOR_VERSION != 6U)
#error COM_SW_MAJOR_VERSION wrong (!= 6U)
#endif

#if (!defined COM_SW_MINOR_VERSION) /* configuration check */
#error COM_SW_MINOR_VERSION must be defined
#endif

/* minor version check */
#if (COM_SW_MINOR_VERSION < 3U)
#error COM_SW_MINOR_VERSION wrong (< 3U)
#endif

#if (!defined COM_SW_PATCH_VERSION) /* configuration check */
#error COM_SW_PATCH_VERSION must be defined
#endif

/* patch version check */
#if (COM_SW_PATCH_VERSION < 11U)
#error COM_SW_PATCH_VERSION wrong (< 11U)
#endif

/*==================[type definitions]======================================*/
/*==================[external function declarations]========================*/
/*==================[internal function declarations]========================*/
/*==================[external constants]====================================*/
/*==================[internal constants]====================================*/
/*==================[external data]=========================================*/
/*==================[internal data]=========================================*/
/*==================[external function definitions]=========================*/
#if (COM_VERSION_INFO_API == STD_ON)

#if (TS_MERGED_COMPILE == STD_OFF)
#define COM_START_SEC_CODE
#include <MemMap.h>
#endif

FUNC(void, COM_CODE) Com_GetVersionInfo
(
   P2VAR(Std_VersionInfoType, AUTOMATIC, COM_APPL_DATA) versionInfoPtr
)
{
/* check if development error detection is enabled */
#if (COM_DEV_ERROR_DETECT == STD_ON)

   /* check for an invalid pointer */
   /* Deviation MISRA-1 */
   if (versionInfoPtr == NULL_PTR)
   {
      COM_DET_REPORTERROR(COM_E_PARAM_POINTER, (COMServiceId_GetVersionInfo));
   }
   else
#endif /* COM_DEV_ERROR_DETECT */

   {
      versionInfoPtr->vendorID = COM_VENDOR_ID;
      versionInfoPtr->moduleID = COM_MODULE_ID;
      versionInfoPtr->sw_major_version = COM_SW_MAJOR_VERSION;
      versionInfoPtr->sw_minor_version = COM_SW_MINOR_VERSION;
      versionInfoPtr->sw_patch_version = COM_SW_PATCH_VERSION;
   }
}                               /* Com_GetVersionInfo */

#if (TS_MERGED_COMPILE == STD_OFF)
#define COM_STOP_SEC_CODE
#include <MemMap.h>
#endif

#endif /* COM_VERSION_INFO_API */

/*==================[internal function definitions]=========================*/

/*==================[end of file]===========================================*/

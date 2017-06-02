/**
 * \file
 *
 * \brief AUTOSAR Base
 *
 * This file contains the implementation of the AUTOSAR
 * module Base.
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2013 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */
/* !LINKSTO Base.ModuleInfo.HeaderFile,1 */

#if (!defined BASE_MODULES_H)
#define BASE_MODULES_H



/*==================[inclusions]=============================================*/

/*==================[macros]=================================================*/




/** \brief Enable status of the module Base (VariantPreCompile) */
#define BASE_BASE_ENABLED  STD_ON


/** \brief Enable status of the module BswM (VariantPreCompile) */
#define BASE_BSWM_ENABLED  STD_ON


/** \brief Enable status of the module Can (VariantPostBuildSelectable) */
#define BASE_CAN_ENABLED  STD_ON
#ifndef BASE_CAN_CONFIG_PTR
/** \brief Address of the first multiple configuration container for
 * Can */
#define BASE_CAN_CONFIG_PTR (&CanConfigSet)
#endif


/** \brief Enable status of the module CanIf (VariantPostBuild) */
#define BASE_CANIF_ENABLED  STD_ON
#ifndef BASE_CANIF_CONFIG_PTR
/** \brief Address of the first multiple configuration container for
 * CanIf */
#define BASE_CANIF_CONFIG_PTR (&CanIf_InitCfg_0)
#endif


/** \brief Enable status of the module CanTp (VariantPostBuild) */
#define BASE_CANTP_ENABLED  STD_ON
#ifndef BASE_CANTP_CONFIG_PTR
/** \brief Address of the first multiple configuration container for
 * CanTp */
#define BASE_CANTP_CONFIG_PTR (&CanTpConfig)
#endif


/** \brief Enable status of the module Com (VariantPostBuild) */
#define BASE_COM_ENABLED  STD_ON
#ifndef BASE_COM_CONFIG_PTR
/** \brief Address of the first multiple configuration container for
 * Com */
#define BASE_COM_CONFIG_PTR (&ComConfig)
#endif


/** \brief Enable status of the module ComM (VariantPreCompile) */
#define BASE_COMM_ENABLED  STD_ON
#ifndef BASE_COMM_CONFIG_PTR
/** \brief empty for ComM -> special handling for ComM (VariantPreCompile) */
#define BASE_COMM_CONFIG_PTR
#endif


/** \brief Enable status of the module Crc (VariantPreCompile) */
#define BASE_CRC_ENABLED  STD_ON


/** \brief Enable status of the module Dcm (VariantPreCompile) */
#define BASE_DCM_ENABLED  STD_ON
#ifndef BASE_DCM_CONFIG_PTR
/** \brief Address of the first multiple configuration container for
 * Dcm */
#define BASE_DCM_CONFIG_PTR (&DcmConfigSet_0)
#endif


/** \brief Enable status of the module Dem (VariantPreCompile) */
#define BASE_DEM_ENABLED  STD_ON
#ifndef BASE_DEM_CONFIG_PTR
/** \brief Address of the first multiple configuration container for
 * Dem */
#define BASE_DEM_CONFIG_PTR (&DemConfigSet_0)
#endif


/** \brief Enable status of the module Dio (VariantPostBuildSelectable) */
#define BASE_DIO_ENABLED  STD_ON
#ifndef BASE_DIO_CONFIG_PTR
/** \brief Address of the first multiple configuration container for
 * Dio */
#define BASE_DIO_CONFIG_PTR (&DioConfig_0)
#endif


/** \brief Enable status of the module EcuC (VariantPostBuild) */
#define BASE_ECUC_ENABLED  STD_ON


/** \brief Enable status of the module EcuM (VariantPostBuild) */
#define BASE_ECUM_ENABLED  STD_ON
#ifndef BASE_ECUM_CONFIG_PTR
/** \brief Address of the first multiple configuration container for
 * EcuM */
#define BASE_ECUM_CONFIG_PTR (&EcuM_Config_0)
#endif


/** \brief Enable status of the module Fee (VariantPreCompile) */
#define BASE_FEE_ENABLED  STD_ON


/** \brief Enable status of the module FiM (VariantPreCompile) */
#define BASE_FIM_ENABLED  STD_ON
#ifndef BASE_FIM_CONFIG_PTR
/** \brief Address of the first multiple configuration container for
 * FiM */
#define BASE_FIM_CONFIG_PTR (&FiM_Config_0)
#endif


/** \brief Enable status of the module Fls (VariantPostBuildSelectable) */
#define BASE_FLS_ENABLED  STD_ON
#ifndef BASE_FLS_CONFIG_PTR
/** \brief Address of the first multiple configuration container for
 * Fls */
#define BASE_FLS_CONFIG_PTR (&FlsConfigSet_0)
#endif


/** \brief Enable status of the module FlsLoader (VariantPreCompile) */
#define BASE_FLSLOADER_ENABLED  STD_ON


/** \brief Enable status of the module Gpt (VariantPostBuildSelectable) */
#define BASE_GPT_ENABLED  STD_ON
#ifndef BASE_GPT_CONFIG_PTR
/** \brief Address of the first multiple configuration container for
 * Gpt */
#define BASE_GPT_CONFIG_PTR (&GptChannelConfigSet_0)
#endif


/** \brief Enable status of the module Icu (VariantPostBuildSelectable) */
#define BASE_ICU_ENABLED  STD_ON
#ifndef BASE_ICU_CONFIG_PTR
/** \brief Address of the first multiple configuration container for
 * Icu */
#define BASE_ICU_CONFIG_PTR (&IcuConfigSet_0)
#endif


/** \brief Enable status of the module Mcu (VariantPostBuildSelectable) */
#define BASE_MCU_ENABLED  STD_ON
#ifndef BASE_MCU_CONFIG_PTR
/** \brief Address of the first multiple configuration container for
 * Mcu */
#define BASE_MCU_CONFIG_PTR (&McuModuleConfiguration_0)
#endif


/** \brief Enable status of the module MemIf (VariantPreCompile) */
#define BASE_MEMIF_ENABLED  STD_ON


/** \brief Enable status of the module NvM (VariantPreCompile) */
#define BASE_NVM_ENABLED  STD_ON


/** \brief Enable status of the module Os (VariantPreCompile) */
#define BASE_OS_ENABLED  STD_OFF


/** \brief Enable status of the module PduR (VariantPostBuild) */
#define BASE_PDUR_ENABLED  STD_ON
#ifndef BASE_PDUR_CONFIG_PTR
/** \brief Address of the first multiple configuration container for
 * PduR */
#define BASE_PDUR_CONFIG_PTR (&PduRRoutingTables)
#endif


/** \brief Enable status of the module Port (VariantPostBuildSelectable) */
#define BASE_PORT_ENABLED  STD_ON
#ifndef BASE_PORT_CONFIG_PTR
/** \brief Address of the first multiple configuration container for
 * Port */
#define BASE_PORT_CONFIG_PTR (&PortConfigSet_0)
#endif


/** \brief Enable status of the module Pwm (VariantPostBuildSelectable) */
#define BASE_PWM_ENABLED  STD_ON
#ifndef BASE_PWM_CONFIG_PTR
/** \brief Address of the first multiple configuration container for
 * Pwm */
#define BASE_PWM_CONFIG_PTR (&PwmChannelConfigSet_0)
#endif


/** \brief Enable status of the module Spi (VariantPostBuildSelectable) */
#define BASE_SPI_ENABLED  STD_ON
#ifndef BASE_SPI_CONFIG_PTR
/** \brief Address of the first multiple configuration container for
 * Spi */
#define BASE_SPI_CONFIG_PTR (&Spi_ConfigData)
#endif


/** \brief Enable status of the module Wdg (VariantPostBuildSelectable) */
#define BASE_WDG_ENABLED  STD_ON
#ifndef BASE_WDG_CONFIG_PTR
/** \brief Address of the first multiple configuration container for
 * Wdg */
#define BASE_WDG_CONFIG_PTR (&WdgSettingsConfig_0)
#endif

/*==================[type definitions]======================================*/

/*==================[external function declarations]=========================*/

/*==================[internal function declarations]=========================*/

/*==================[external constants]=====================================*/

/*==================[internal constants]=====================================*/

/*==================[external data]==========================================*/

/*==================[internal data]==========================================*/

/*==================[external function definitions]==========================*/

/*==================[internal function definitions]==========================*/

#endif /* if !defined( BASE_MODULES_H ) */
/*==================[end of file]============================================*/

/******************************************************************************
**                                                                           **
** Copyright (C) Infineon Technologies (2014)                                **
**                                                                           **
** All rights reserved.                                                      **
**                                                                           **
** This document contains proprietary information belonging to Infineon      **
** Technologies. Passing on and copying of this document, and communication  **
** of its contents is not permitted without prior written authorization.     **
**                                                                           **
*******************************************************************************
**                                                                           **
**  $FILENAME   : Gtm_Local.h $                                              **
**                                                                           **
**  $CC VERSION : \main\dev_tc23x\4 $                                        **
**                                                                           **
**  $DATE       : 2015-05-21 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION : This file contains                                         **
**                functionality of <> driver.                                **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                           **
******************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
  /* Include Standard Types */
#include "Std_Types.h"
#include "IfxGtm_regdef.h"

/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/
/* Bits to shift to get the mode information to LSB for a 8 bit variable */
#define GTM_SHIFT_TO_LSB_8 (6)
#define GTM_SHIFT_EIRQ_TO_LSB_8 (9U)

#define GTM_CLEAR_TIM_INTERRUPT (0x3FUL)

/* Get the IRQ Enable Information from a 8bit variable */
#define GTM_GET_IRQ_VAL_8 (0x3FUL)

/* Get the TIM EIRQ Enable Information from a 32 bit variable */
#define GTM_TIM_GET_EIRQ_VAL_32 (0x3FUL)

/* Get the TIM IN SRC register Information from a 32 bit variable */
#define GTM_TIM_GET_INSRC_VAL_32 (0xFFFFFFFFUL)

/* Get the TIM IN SRC register Information from a 32 bit variable */
#define GTM_TIM_GET_AUXIN_VAL_32 (0xFFUL)

#define GTM_TIM_GET_MODE (0xEUL)

#define GTM_TIM_MODE_TIPM  (3U)

#define GTM_TIM_ENABLE_MASK (1UL)

#define GTM_TIM_EXT_CAP_ENABLE_MASK (0x7UL)

#define GTM_BITS_IN_U8 (8U)


/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/
extern void Gtm_lAdcConnectionsConfig(void);
extern void Gtm_lTomComplexConfig(void);
extern void Gtm_lTomClockSetting(void);
extern void Gtm_lTimConfigure(void);

#if (GTM_DEINIT_API_ENABLE == STD_ON)

extern void Gtm_lResetGtmSRCReg(void);

#endif
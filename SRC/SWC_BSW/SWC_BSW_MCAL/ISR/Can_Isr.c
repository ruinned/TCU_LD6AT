/******************************************************************************/
/* !Layer           : MCAL                                                    */
/* !Component       : ISR                                                     */
/* !Description     : ISR Management                                          */
/*                                                                            */
/* !File            : Can_Isr.c                                               */
/* !Description     : ISR definition of Can component                         */
/*                                                                            */
/* !Reference       :                                                         */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT VALEO all rights reserved                                        */
/******************************************************************************/
/* Dimension Informations
 * %PCMS_HEADER_SUBSTITUTION_START:%
 * The PID has this format: <Product ID>:<Item ID>.<Variant>-<Item Type>;<Revision>
 * %PID:%
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#include "Std_Types.h"
#include "Can_17_MCanP.h"
//#include "INTBSL.h"
#include "Os.h"

/******************************************************************************/
/* !Comment: SRC_CAN_CAN0_INTx_ISR (x = 0..3) are reserved for CANx Bus Off   */
/*           SRC_CAN_CAN0_INTy_ISR (y = 2x) are reserved for CANx Rx / Wake up*/
/*           SRC_CAN_CAN0_INTz_ISR (z = 3x) are reserved for CANx Tx          */
/*           SRC_CAN_CAN0_INTt_ISR (t = 12..15) are not used                  */
/******************************************************************************/

#define ISR_START_SEC_CODE
#include "ISR_MemMap.h"

/******************************************************************************/
/* !FuncName    : ISR(SRC_CAN_CAN0_INT0_ISR)                                  */
/* !Description : Service for CAN Controller 0 Transmission event             */
/*                                                                            */
/* !LastAuthor  : M. Sabry                                                    */
/******************************************************************************/
#ifdef SRC_CAN_CAN0_INT0_ISR
ISR(SRC_CAN_CAN0_INT0_ISR)
{
#if (CAN_BO_PROCESSING_HWCONTROLLER0 == CAN_INTERRUPT)
   Can_17_MCanP_IsrTransmitHandler(CAN_HWCONTROLLER0);
#endif /* if (CAN_BO_PROCESSING_HWCONTROLLER0 == CAN_INTERRUPT) */
}
#endif /* if (SRC_CAN_CAN0_INT0_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : ISR(SRC_CAN_CAN0_INT1_ISR)                                  */
/* !Description : Service for CAN Controller 1 Transmission event             */
/*                                                                            */
/* !LastAuthor  : M. Sabry                                                    */
/******************************************************************************/
#ifdef SRC_CAN_CAN0_INT1_ISR
ISR(SRC_CAN_CAN0_INT1_ISR)
{
#if (CAN_BO_PROCESSING_HWCONTROLLER1 == CAN_INTERRUPT)
   Can_17_MCanP_IsrTransmitHandler(CAN_HWCONTROLLER1);
#endif /* if (CAN_BO_PROCESSING_HWCONTROLLER1 == CAN_INTERRUPT) */
}
#endif /* ifdef SRC_CAN_CAN0_INT1_ISR */


/******************************************************************************/
/* !FuncName    : ISR(SRC_CAN_CAN0_INT2_ISR)                                 */
/* !Description : Service for CAN Controller 2 Transmission event             */
/*                                                                            */
/* !LastAuthor  : M. Sabry                                                    */
/******************************************************************************/
#ifdef SRC_CAN_CAN0_INT2_ISR
ISR(SRC_CAN_CAN0_INT2_ISR)
{
#if (CAN_BO_PROCESSING_HWCONTROLLER2 == CAN_INTERRUPT)
   Can_17_MCanP_IsrTransmitHandler(CAN_HWCONTROLLER2);
#endif /* if (CAN_BO_PROCESSING_HWCONTROLLER2 == CAN_INTERRUPT) */
}
#endif /* if (SRC_CAN_CAN0_INT2_USED == STD_ON) */




/******************************************************************************/
/* !FuncName    : ISR(SRC_CAN_CAN0_INT3_ISR)                                  */
/* !Description : Service for CAN Controller 0 Reception/Wakeup event         */
/*                                                                            */
/* !LastAuthor  : M. Sabry                                                    */
/******************************************************************************/
#ifdef SRC_CAN_CAN0_INT3_ISR
ISR(SRC_CAN_CAN0_INT3_ISR)
{
#if (CAN_BO_PROCESSING_HWCONTROLLER0 == CAN_INTERRUPT)
   Can_17_MCanP_IsrReceiveHandler(CAN_HWCONTROLLER0);
#endif /* if (CAN_BO_PROCESSING_HWCONTROLLER0 == CAN_INTERRUPT) */
}
#endif /* if (SRC_CAN_CAN0_INT3_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : ISR(SRC_CAN_CAN0_INT4_ISR)                                  */
/* !Description : Service for CAN Controller 1 Reception/Wakeup event         */
/*                                                                            */
/* !LastAuthor  : M. Sabry                                                    */
/******************************************************************************/
#ifdef SRC_CAN_CAN0_INT4_ISR
ISR(SRC_CAN_CAN0_INT4_ISR)
{
#if (CAN_BO_PROCESSING_HWCONTROLLER1 == CAN_INTERRUPT)
   Can_17_MCanP_IsrReceiveHandler(CAN_HWCONTROLLER1);
#endif /* if (CAN_BO_PROCESSING_HWCONTROLLER1 == CAN_INTERRUPT) */
}
#endif /* if (SRC_CAN_CAN0_INT4_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : ISR(SRC_CAN_CAN0_INT5_ISR)                                  */
/* !Description : Service for CAN Controller 2 Reception/Wakeup event         */
/*                                                                            */
/* !LastAuthor  : M. Sabry                                                    */
/******************************************************************************/
#ifdef SRC_CAN_CAN0_INT5_ISR
ISR(SRC_CAN_CAN0_INT5_ISR)
{
#if (CAN_BO_PROCESSING_HWCONTROLLER2 == CAN_INTERRUPT)
   Can_17_MCanP_IsrReceiveHandler(CAN_HWCONTROLLER2);
#endif /* if (CAN_BO_PROCESSING_HWCONTROLLER2 == CAN_INTERRUPT) */
}
#endif /* if (SRC_CAN_CAN0_INT5_USED == STD_ON) */




/******************************************************************************/
/* !FuncName    : ISR(SRC_CAN_CAN0_INT6_ISR)                                  */
/* !Description : Service for CAN Controller 0 Busoff event                   */
/*                                                                            */
/* !LastAuthor  : A. Abohassan                                                */
/******************************************************************************/
#ifdef SRC_CAN_CAN0_INT6_ISR
ISR(SRC_CAN_CAN0_INT6_ISR)
{
#if (CAN_BO_PROCESSING_HWCONTROLLER0 == CAN_INTERRUPT)
   Can_17_MCanP_IsrBusOffHandler(CAN_HWCONTROLLER0);
#endif /* if (CAN_BO_PROCESSING_HWCONTROLLER0 == CAN_INTERRUPT) */
}
#endif /* if (SRC_CAN_CAN0_INT6_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : ISR(SRC_CAN_CAN0_INT7_ISR)                                  */
/* !Description : Service for CAN Controller 1 Reception/Wakeup event         */
/*                                                                            */
/* !LastAuthor  : M. Sabry                                                    */
/******************************************************************************/
#ifdef SRC_CAN_CAN0_INT7_ISR
ISR(SRC_CAN_CAN0_INT7_ISR)
{
#if (CAN_BO_PROCESSING_HWCONTROLLER1 == CAN_INTERRUPT)
   Can_17_MCanP_IsrBusOffHandler(CAN_HWCONTROLLER1);
#endif /* if (CAN_BO_PROCESSING_HWCONTROLLER1 == CAN_INTERRUPT) */
}
#endif /* if (SRC_CAN_CAN0_INT7_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : ISR(SRC_CAN_CAN0_INT8_ISR)                                 */
/* !Description : Service for CAN Controller 2 Busoff event                   */
/*                                                                            */
/* !LastAuthor  : M. Sabry                                                    */
/******************************************************************************/
#ifdef SRC_CAN_CAN0_INT8_ISR
ISR(SRC_CAN_CAN0_INT8_ISR)
{
#if (CAN_BO_PROCESSING_HWCONTROLLER2 == CAN_INTERRUPT)
   Can_17_MCanP_IsrBusOffHandler(CAN_HWCONTROLLER2);
#endif /* if (CAN_BO_PROCESSING_HWCONTROLLER2 == CAN_INTERRUPT) */
}
#endif /* if (SRC_CAN_CAN0_INT8_USED == STD_ON) */




#define ISR_STOP_SEC_CODE
#include "ISR_MemMap.h"

/*-------------------------------- END OF FILE -------------------------------*/


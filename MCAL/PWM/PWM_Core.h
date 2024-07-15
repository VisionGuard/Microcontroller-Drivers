/*
 * PWM_Core.h
 *
 * Created: 10/24/2023 8:49:58 PM
 *  Author: Osama
 */ 


#ifndef PWM_CORE_H_
#define PWM_CORE_H_


/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/MCU.h"


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define PWM_ENABLE    1U
#define PWM_DISABLE   0U

#define PWM_FAST            0U
#define PWM_PHASE_CORRECT   1U

#define PWM_INVERTED      0U
#define PWM_NONINVERTED   1U

#define PWM_PRESC8     8U
#define PWM_PRES32     32U
#define PWM_PRESC64    64U
#define PWM_PRESC128   128U
#define PWM_PRESC256   256U
#define PWM_PRESC1024  1024U

#define  PWM0_STATE  PWM_ENABLE
#define  PWM1_STATE  PWM_DISABLE
#define  PWM2_STATE  PWM_DISABLE

#define  PWM0_TYPE  PWM_FAST
#define  PWM1_TYPE  PWM_FAST
#define  PWM2_TYPE  PWM_FAST

#define  PWM0_MODE  PWM_NONINVERTED
#define  PWM1_MODE  PWM_NONINVERTED
#define  PWM2_MODE  PWM_INVERTED

#define  PWM0_PRESC  PWM_PRESC1024
#define  PWM1_PRESC  PWM_PRESC256
#define  PWM2_PRESC  PWM_PRESC8

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
void PWM_Init(void);

void PWM0_Generate(uint8 Duty_Cycle);

void PWM1_Generate(uint8 Frewquancy , uint8 Duty_Cycle);

#endif /* PWM_CORE_H_ */

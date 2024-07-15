/*


 * Timer_0Cfg.h
 *
 *  Created on: Sep 17, 2023
 *      Author: sheri
 */

#ifndef MCAL_TIMER_0_TIMER_0CFG_H_
#define MCAL_TIMER_0_TIMER_0CFG_H_



#define TIMER0_PRESCALER_VALUE   TIMER0_PRESCALER_1024
#define TIMER0_MODE              TIMER0_FAST_PWM_MODE
#define TIMER0_FAST_PWM          TIMER0_NON_INV
#define TIMER0_PHASE_CORRECT     TIMER0_Set_OC0_compare_match
#define TIMER0_OC0_FUNCTION			TIMER0_NON_INV


#define  PWM0_STATE  PWM_ENABLE
#define  PWM0_TYPE  PWM_FAST
#define  PWM0_MODE  PWM_NONINVERTED
#define  PWM0_PRESC  PWM_PRESC1024


#endif /* MCAL_TIMER_0_TIMER_0CFG_H_ */

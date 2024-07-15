/*



 * Timer_0Private.h
 *
 *  Created on: Sep 17, 2023
 *      Author: Omar
 */

#ifndef MCAL_TIMER_0_TIMER_0PRIVATE_H_
#define MCAL_TIMER_0_TIMER_0PRIVATE_H_

#define FCPU 16 // Replace with your microcontroller's clock frequency
/*
#define TCCR0         *((volatile u8*) 0x53)
#define TIFR          *((volatile u8*) 0x58)
#define TCNT0         *((volatile u8*) 0x52)
#define OCR0          *((volatile u8*) 0x5C)
#define TIMSK         *((volatile u8*) 0x59)
*/
#define TIMSK_TOIE0            0
#define TIMSK_OCIE0            1

#define TIFR_TOV0              0
#define TIFR_OCF0              1

#define TCCR0_FOC0             7
#define TCCR0_WGM00            6
#define TCCR0_COM01            5
#define TCCR0_COM00            4
#define TCCR0_WGM01            3
#define TCCR0_CS02             2
#define TCCR0_CS01             1
#define TCCR0_CS00             0

/************************* SELECT MODE **********************/
#define TIMER0_NORMAL_MODE               0
#define TIMER0_PHASECORRECT_MODE         1
#define TIMER0_CTC_MODE                  2
#define TIMER0_FAST_PWM_MODE             3

/************************* PRESCALER ***********************/

#define TIMER0_No_clock_source           0   //(Timer/Counter stopped)
#define TIMER0_No_prescaling             1
#define TIMER0_PRESCALER_8               2
#define TIMER0_PRESCALER_64              3
#define TIMER0_PRESCALER_256             4 // 100
#define TIMER0_PRESCALER_1024            5
#define TIMER0_PRESCALER_FALLING_EDGE    6
#define TIMER0_PRESCALER_RISING_EDGE     7
/************************ FAST PWM MODES *******************************/
#define TIMER0_NON_INV    2
#define TIMER0_INV        3
/************************ PHASE CORRECT MODES *******************************/
#define TIMER0_Set_OC0_compare_match     2
#define TIMER0_CLR_OC0_compare_match     3
/************************* OC0*****************************/
#define TIMER0_OC0_DISC				0
#define TIMER0_OC0_TOG				1
#define TIMER0_OC0_CLR				2
#define TIMER0_OC0_SET				3
/************************PWM*******************************/

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


#endif /* MCAL_TIMER_0_TIMER_0PRIVATE_H_ */

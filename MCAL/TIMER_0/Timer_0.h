/*

 * Timer_0.h
 *
 *  Created on: Sep 17, 2023
 *      Author: sherif
 */

#ifndef MCAL_TIMER_0_TIMER_0_H_
#define MCAL_TIMER_0_TIMER_0_H_

#include "../../LIB/STD.h"
#include "../../LIB/MCU.h"
/*****************************Functions_Prototypes**************************************************/
void Timer_Init(void);
void Timer_start(void);
void Timer_stop(void);
uint32 Timer_GetCounts(void);
void EnableInt(void);
void DisableInt(void);
void Timer_setDelayTimeMilliSec(uint32 millis);
void PWM0_Generate(uint8 Duty_Cycle);
void Timer_0_CallBackReceiver (void (* Arg_CallBack) (void) );
/*****************************/
#endif /* MCAL_TIMER_0_TIMER_0_H_ */

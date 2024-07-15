/*



 * Timer_0.c
 *
 *  Created on: Sep 17, 2023
 *      Author: sherif
 */
#include "../../MCAL/TIMER_0/Timer_0.h"
#include "../../MCAL/TIMER_0/Timer_0Cfg.h"
#include "../../MCAL/TIMER_0/Timer_0Private.h"
#include "../../LIB/STD.h"
#include <stddef.h>
#include "../../LIB/BIT_MATH.h"



volatile uint32 Timer0_Count_OVF =0;
volatile uint32 timer0_counts = 0;
volatile uint32 Rema_tick =0;

void (*GpTimer0_Normal_CallBack) (void) = NULL ;

void Timer_Init(void)
{

#if( TIMER0_MODE == TIMER0_NORMAL_MODE)
	CLR_BIT(TCCR0,TCCR0_WGM00);
	CLR_BIT(TCCR0,TCCR0_WGM01);
#elif(  TIMER0_MODE == TIMER0_PHASECORRECT_MODE )
	SET_BIT(TCCR0,TCCR0_WGM00);
	CLR_BIT(TCCR0,TCCR0_WGM01);
#if (TIMER0_PHASECORRECT_MODE==TIMER0_Set_OC0_compare_match)
	TCCR0 &= 0b11111100;
	TCCR0 |= TIMER0_Set_OC0_compare_match ;
#elif (TIMER0_PHASECORRECT_MODE==TIMER0_CLR_OC0_compare_match)
	TCCR0 &= 0b11111100;
	TCCR0 |= TIMER0_CLR_OC0_compare_match ;
#endif
#elif(  TIMER0_MODE == TIMER0_CTC_MODE )
	CLR_BIT(TCCR0,TCCR0_WGM00);
	SET_BIT(TCCR0,TCCR0_WGM01);
#elif(  TIMER0_MODE == TIMER0_FAST_PWM_MODE )
	SET_BIT(TCCR0,TCCR0_WGM00);
	SET_BIT(TCCR0,TCCR0_WGM01);
#if (TIMER0_FAST_PWM==TIMER0_NON_INV)
	CLR_BIT(TCCR0 , 4);
	SET_BIT(TCCR0 , 5);
#elif (TIMER0_FAST_PWM==TIMER0_INV)
	SET_BIT(TCCR0 , 4);
	SET_BIT(TCCR0 , 5);
#endif
#else
#error ("Out of Range")


#endif
}
void Timer_start(void)
{
#if	(TIMER0_PRESCALER_VALUE >=0 && TIMER0_PRESCALER_VALUE <= 7)
	TCCR0 &= 0b11111000;
	TCCR0 |= TIMER0_PRESCALER_VALUE ;
#else
#error ("Out of Range")


#endif

}
void Timer_stop(void)
{
	CLR_BIT(TCCR0,TCCR0_CS00);
	CLR_BIT(TCCR0,TCCR0_CS01);
	CLR_BIT(TCCR0,TCCR0_CS02);

}
uint32 Timer_GetCounts(void)
{
	timer0_counts =(Timer0_Count_OVF*256) +TCNT0;
	return timer0_counts;
}
void EnableInt(void)
{
	SET_BIT(TIMSK, TIMSK_TOIE0);
}
void DisableInt(void)
{
	CLR_BIT(TIMSK, TIMSK_TOIE0); // Disable Timer0 overflow interrupt
}
void Timer_setDelayTimeMilliSec(uint32 time)
{
	// Calculate the number of timer counts required for the delay
	uint16 arr[]={1,8,64,256,1024};
	sint32 ticktime = (sint32)arr[TIMER0_PRESCALER_VALUE-1]/FCPU;
	uint32 total_Num_Of_Ticks = (time * 1000)/ticktime;
	Timer0_Count_OVF=total_Num_Of_Ticks/256;
	Rema_tick = total_Num_Of_Ticks%256;
	if(Rema_tick!=0)
	{
		Timer0_Count_OVF++;
		TCNT0=256-Rema_tick;
	}

}

void PWM0_Generate(uint8 Duty_Cycle)
{
	#if (PWM0_STATE ==  PWM_ENABLE)
	#if (PWM0_TYPE  == PWM_FAST)

	#if (PWM0_MODE  == PWM_NONINVERTED)
	OCR0 = ((Duty_Cycle * 256)/100)-1;
	#elif (PWM0_MODE  == PWM_INVERTED)
	OCR0 = 255 - ((Duty_Cycle * 256)/100);
	#endif /*if (PWM0_MODE  == PWM_NONINVERTED)*/

	#elif (PWM0_TYPE  == PWM_PHASE_CORRECT)

	#if (PWM0_MODE  == PWM_NONINVERTED)
	OCR0 = ((Duty_Cycle * (256 - 1))/100)-1;
	#elif (PWM0_MODE  == PWM_INVERTED)
	OCR0 = 255 - ((Duty_Cycle * (256 - 1))/100);
	#endif /*if (PWM0_MODE  == PWM_NONINVERTED)*/

	#endif /*if (PWM0_TYPE  == PWM_FAST)*/

	#if (PWM0_PRESC ==  PWM_PRESC8)
	TCCR0 |= 0x02 ;
	#elif (PWM0_PRESC ==  PWM_PRESC64)
	TCCR0 |= 0x03 ;
	#elif (PWM0_PRESC ==  PWM_PRESC256)
	TCCR0 |= 0x04 ;
	#elif (PWM0_PRESC ==  PWM_PRESC1024)
	TCCR0 |= 0x05 ;
	#endif /*if (PWM0_PRESC ==  PWM_PRESC8)*/
	#endif /*if (PWM0_STATE ==  PWM_ENABLE)*/
}


void Timer_0_CallBackReceiver (void (* Arg_CallBack) (void) )
{
	GpTimer0_Normal_CallBack = Arg_CallBack ;
}

void __vector_11 (void) __attribute__ ((signal)) ;
void __vector_11 (void){

	static uint32 counter=0;
	counter++;
	if (counter == Timer0_Count_OVF)
	{

		GpTimer0_Normal_CallBack();
		counter=0;
		TCNT0=256-Rema_tick;
	}

}


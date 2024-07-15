/*
 * TIMER1.c
 *
 * Created: 4/18/2024 12:34:30 AM
 *  Author: mostafa younis
 */ 


#include "TIMER1.h"



static void (*TIMER1_OV_FPtr) (void) = NULL;
static void (*TIMER1_ICU_FPtr) (void) = NULL;



void Timer1_Init( Timer1Mode_type mode,Timer1Scaler_type scaler)
{
	switch (mode)
	{
		case TIMER1_NORMAL_MODE:
		CLR_BIT(TCCR1A,WGM10);
		CLR_BIT(TCCR1A,WGM11);
		CLR_BIT(TCCR1B,WGM12);
		CLR_BIT(TCCR1B,WGM13);
		break;
		case TIMER1_CTC_ICR_TOP_MODE:
		CLR_BIT(TCCR1A,WGM10);
		CLR_BIT(TCCR1A,WGM11);
		SET_BIT(TCCR1B,WGM12);
		SET_BIT(TCCR1B,WGM13);
		break;
		
		case TIMER1_CTC_OCRA_TOP_MODE:
		CLR_BIT(TCCR1A,WGM10);
		CLR_BIT(TCCR1A,WGM11);
		SET_BIT(TCCR1B,WGM12);
		CLR_BIT(TCCR1B,WGM13);
		break;
		
		case TIMER1_FASTPWM_ICR_TOP_MODE:
		CLR_BIT(TCCR1A,WGM10);
		SET_BIT(TCCR1A,WGM11);
		SET_BIT(TCCR1B,WGM12);
		SET_BIT(TCCR1B,WGM13);
		break;
		
		case TIMER1_FASTPWM_OCRA_TOP_MODE:
		SET_BIT(TCCR1A,WGM10);
		SET_BIT(TCCR1A,WGM11);
		SET_BIT(TCCR1B,WGM12);
		SET_BIT(TCCR1B,WGM13);
		break;
		case TIMER1_FASTPWM_8BIT_MODE:
		SET_BIT(TCCR1A,WGM10);
		CLR_BIT(TCCR1A,WGM11);
		SET_BIT(TCCR1B,WGM12);
		CLR_BIT(TCCR1B,WGM13);
		break;
		
		case TIMER1_FASTPWM_10BIT_MODE :
		SET_BIT(TCCR1A,WGM10);
		SET_BIT(TCCR1A,WGM11);
		SET_BIT(TCCR1B,WGM12);
		CLR_BIT(TCCR1B,WGM13);
		break;
	}
	TCCR1B&=0XF8;
	TCCR1B|=scaler;
}

void Timer1_OCRA1Mode(OC1A_Mode_type oc1a_mode)
{
	switch (oc1a_mode)
	{
		case OCRA_DISCONNECTED:
		CLR_BIT(TCCR1A,COM1A0);
		CLR_BIT(TCCR1A,COM1A1);
		break;
		case OCRA_TOGGLE:
		SET_BIT(TCCR1A,COM1A0);
		CLR_BIT(TCCR1A,COM1A1);
		break;
		case OCRA_NON_INVERTING:
		CLR_BIT(TCCR1A,COM1A0);
		SET_BIT(TCCR1A,COM1A1);
		break;
		case OCRA_INVERTING:
		SET_BIT(TCCR1A,COM1A0);
		SET_BIT(TCCR1A,COM1A1);
		break;
	}
}
void Timer1_OCRB1Mode(OC1B_Mode_type oc1b_mode)
{
	switch (oc1b_mode)
	{
		case OCRB_DISCONNECTED:
		CLR_BIT(TCCR1A,COM1B0);
		CLR_BIT(TCCR1A,COM1B1);
		break;
		case OCRB_TOGGLE:
		SET_BIT(TCCR1A,COM1B0);
		CLR_BIT(TCCR1A,COM1B1);
		break;
		case OCRB_NON_INVERTING:
		CLR_BIT(TCCR1A,COM1B0);
		SET_BIT(TCCR1A,COM1B1);
		break;
		case OCRB_INVERTING:
		SET_BIT(TCCR1A,COM1B0);
		SET_BIT(TCCR1A,COM1B1);
		break;
	}
}

void Timer1_InputCaptureEdge(ICU_Edge_type edge)
{
	if(edge==RISING)
	SET_BIT(TCCR1B,ICES1);
	
	else if(edge==FALLING)
	CLR_BIT(TCCR1B,ICES1);
	
}

void Timer1_ICU_InterruptEnable(void)
{
	SET_BIT(TIMSK,TICIE1);
}
void Timer1_ICU_InterruptDisable(void)
{
	CLR_BIT(TIMSK,TICIE1);
}

void Timer1_OVF_InterruptEnable(void)
{
	SET_BIT(TIMSK,TOIE1);
}
void Timer1_OVF_InterruptDisable(void)
{
	CLR_BIT(TIMSK,TOIE1);
}


void Timer1_OVF_SetCallBack(void(*LocalFptr)(void))
{
	TIMER1_OV_FPtr = LocalFptr;
}
void Timer1_ICU_SetCallBack(void(*LocalFptr)(void))
{
	TIMER1_ICU_FPtr = LocalFptr;
}



ISR(TIMER1_ICU_vect)
{
	if(TIMER1_ICU_FPtr!=NULL)
	{
		TIMER1_ICU_FPtr();
	}
}
ISR(TIMER1_OVF_vect)
{
	if(TIMER1_OV_FPtr!=NULL)
	{
		TIMER1_OV_FPtr();
	}
	

}


/***************************************PWM******************************************/

void PWM_Init(void)
{
	Timer1_Init(TIMER1_FASTPWM_10BIT_MODE,TIMER1_SCALER_8);
	Timer1_OCRB1Mode(OCRB_NON_INVERTING);
	Timer1_OCRA1Mode(OCRA_NON_INVERTING);
	
}



void PWM_Duty(uint8 duty){
	
	if(duty<=100)
	{
		uint16 Ton =  ((uint32)duty*1024)/100;
		if(Ton>1)
		{
			OCR1A_16BIT_ACCESS = Ton-1;
			OCR1B_16BIT_ACCESS = Ton-1;
		}
		else
		{
			OCR1A_16BIT_ACCESS = 0;
			OCR1B_16BIT_ACCESS = 0;
		}
	}
}


void PWM_Duty_A(uint8 duty)
{
	if(duty<=100)
	{
		uint16 Ton =  ((uint32)duty*1024)/100;
		if(Ton >1)
		{
			OCR1A_16BIT_ACCESS = Ton-1;
		}
		else
		{
			OCR1A_16BIT_ACCESS = 0;
		}
	}
}


void PWM_Duty_B(uint8 duty)
{
	if(duty<=100)
	{
		uint16 Ton =  ((uint32)duty*1024)/100;
		if(Ton >1)
		{
			OCR1B_16BIT_ACCESS = Ton-1;
		}
		else
		{
			OCR1B_16BIT_ACCESS = 0;
		}
	}
}

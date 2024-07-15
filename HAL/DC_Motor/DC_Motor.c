/*
 * DC_Motor.c
 *
 *  Created on: 27 Oct 2023
 *      Author: Omar
 */
#include "Dc_Motor.h"

/******************************* Functions **********************/
void DC_Motor_INIT(void){
	//PWM
	DIO_INIT(PORT_D,PORTD_PIN4,OUT);
	DIO_INIT(PORT_D,PORTD_PIN5,OUT);
	//Motor 1
	DIO_INIT(PORT_C ,PORTC_PIN4,OUT);
	DIO_INIT(PORT_C ,PORTC_PIN5,OUT);
	//Motor2
	DIO_INIT(PORT_C ,PORTC_PIN6,OUT);
	DIO_INIT(PORT_C ,PORTC_PIN7,OUT);

}
void DC_Motor1_SetSpeed(uint8 Speed){
	PWM_Duty_A(Speed);
}
void DC_Motor2_SetSpeed(uint8 Speed){
	PWM_Duty_B(Speed);
}
void Both_motors(uint8 Speed){
	PWM_Duty(Speed);
}
void DC_Motor_SetDir(uint8 Dir){
	switch(Dir){
	case CCW :
		DIO_Write(PORT_C,PORTC_PIN4 ,HIGH);
		DIO_Write(PORT_C,PORTC_PIN5 ,LOW);
		break;
	case CW :
		DIO_Write(PORT_C,PORTC_PIN4 ,LOW);
		DIO_Write(PORT_C,PORTC_PIN5 ,HIGH);
		break;
	default:
		break;
	}
}

void DC_Motor2_SetDir(uint8 Dir){
	switch(Dir){
	case CCW :
		DIO_Write(PORT_C,PORTC_PIN6 ,HIGH);
		DIO_Write(PORT_C,PORTC_PIN7 ,LOW);
		break;
	case CW :
		DIO_Write(PORT_C,PORTC_PIN6 ,LOW);
		DIO_Write(PORT_C,PORTC_PIN7 ,HIGH);
		break;
	default:
		break;
	}
}

void DC_Motor_Emergency_Stop(void){
	DIO_Write(PORT_C ,PORTC_PIN4 ,HIGH);
	DIO_Write(PORT_C ,PORTC_PIN5 ,HIGH);
}

void DC_Motor2_Emergency_Stop(void){
	DIO_Write(PORT_C ,PORTC_PIN6 ,HIGH);
	DIO_Write(PORT_C ,PORTC_PIN7 ,HIGH);
}

void DC_Motor_Stop(void){
	DIO_Write(PORT_C ,PORTC_PIN4 ,LOW);
	DIO_Write(PORT_C ,PORTC_PIN5 ,LOW);
}

void DC_Motor2_Stop(void){
	DIO_Write(PORT_C ,PORTC_PIN6 ,LOW);
	DIO_Write(PORT_C ,PORTC_PIN7 ,LOW);
}

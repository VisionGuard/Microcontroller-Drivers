/*
 * Stepper_Motor.c
 *
 *  Created on: 3 Nov 2023
 *      Author: Omar
 */
#include "Stepper_Motor.h"

void Stepper_Init(void){
	DIO_INIT(PORT_B ,PORTB_PIN0 ,OUT);
	DIO_INIT(PORT_B ,PORTB_PIN1 ,OUT);
	DIO_INIT(PORT_B ,PORTB_PIN2 ,OUT);
	DIO_INIT(PORT_B ,PORTB_PIN3 ,OUT);
}
void Stepper_Move(void){
	#if (Stepper_DIR == Stepper_CW)
	PORTB = 0x09;
	_delay_ms(1);
	PORTB =0x03;
	_delay_ms(1);
	PORTB =0x06;
	_delay_ms(1);
	PORTB =0x0c;
	_delay_ms(1);
	#endif

	#if (Stepper_DIR == Stepper_CCW)

	PORTB =0x0c;
	_delay_ms(1);
	PORTB =0x06;
	_delay_ms(1);
	PORTB =0x03;
	_delay_ms(1);
	PORTB = 0x09;
	_delay_ms(1);
	#endif
}

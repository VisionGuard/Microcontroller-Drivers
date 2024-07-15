/*
 * BTN.c
 *
 *  Created on: Sep 19, 2023
 *      Author: Elyabanya
 */

#include "BTN.h"

void BTN_INIT(uint8 BTN)
{
	switch(BTN){
	case BTN_1 :
		DIO_INIT(BTN1_PORT ,BTN1_PIN ,IN);
		break;
	case BTN_2 :
		DIO_INIT(BTN2_PORT ,BTN2_PIN ,IN);
		break;
	case BTN_3 :
		DIO_INIT(BTN3_PORT ,BTN3_PIN ,IN);
		break;
	}
}
uint8 BTN_Read(uint8 BTN)
{
	uint8 btn_status =0;
	switch(BTN){
		case BTN_1 :
			btn_status =DIO_READ(BTN1_PORT ,BTN1_PIN);
			break;
		case BTN_2 :
			btn_status =DIO_READ(BTN2_PORT ,BTN2_PIN);
			break;
		case BTN_3 :
			btn_status =DIO_READ(BTN3_PORT ,BTN3_PIN);
			break ;
		}
	_delay_ms(25);
	return btn_status ;
}


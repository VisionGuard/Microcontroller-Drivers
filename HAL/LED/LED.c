/*
 * LED.c
 *
 *  Created on: Sep 19, 2023
 *      Author: Elyabanya
 */
#include "LED.h"

void LED_INIT(uint8 led_num){
	switch(led_num){
	case LED_RED:
		DIO_INIT(LED_RED_PORT,LED_RED_PIN,OUT);
		break;
	case LED_GRN:
		DIO_INIT(LED_GRN_PORT,LED_GRN_PIN,OUT);
		break;
	case LED_BLU:
		DIO_INIT(LED_BLU_PORT,LED_BLU_PIN,OUT);
		break;
	}
}

void LED_ON(uint8 led_num){
	switch(led_num){
	case LED_RED:
		DIO_Write(LED_RED_PORT,LED_RED_PIN,HIGH);
		break;
	case LED_GRN:
		DIO_Write(LED_GRN_PORT,LED_GRN_PIN,HIGH);
		break;
	case LED_BLU:
		DIO_Write(LED_BLU_PORT,LED_BLU_PIN,HIGH);
		break;
	}
}

void LED_OFF(uint8 led_num){
	switch(led_num){
	case LED_RED:
		DIO_Write(LED_RED_PORT,LED_RED_PIN,LOW);
		break;
	case LED_GRN:
		DIO_Write(LED_GRN_PORT ,LED_GRN_PIN,LOW);
		break;
	case LED_BLU:
		DIO_Write(LED_BLU_PORT,LED_BLU_PIN ,LOW);
		break;
	}
}

void LED_TOGGLE(uint8 led_num){
	switch(led_num){
		case LED_RED:
			DIO_TOGGLE(LED_RED_PORT,LED_RED_PIN);
			break;
		case LED_GRN:
			DIO_TOGGLE(LED_GRN_PORT,LED_GRN_PIN);
			break;
		case LED_BLU:
			DIO_TOGGLE(LED_BLU_PORT,LED_BLU_PIN);
			break;
		}
}


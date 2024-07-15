/*
 * DIO.c
 *
 *  Created on: Sep 19, 2023
 *      Author: Omar Abdelaziz
 */

/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  DIO.c
 *        \brief  DIO source file
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "DIO.h"

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

void DIO_INIT(uint8 PORT_NUM ,uint8 PIN_NUM ,uint8 DIRECTION){
	switch(DIRECTION){
	case OUT :
		switch(PORT_NUM){
		case PORT_A :
			SET_BIT(DDRA ,PIN_NUM);
			break;
		case PORT_B :
			SET_BIT(DDRB, PIN_NUM);
			break;
		case PORT_C :
		    SET_BIT(DDRC, PIN_NUM);
			break;
		case PORT_D :
			SET_BIT(DDRD, PIN_NUM);
			break;
		default:
			break;
		}
		break;
		case IN :
			switch(PORT_NUM){
					case PORT_A :
						CLR_BIT(DDRA ,PIN_NUM);
						break;
					case PORT_B :
						CLR_BIT(DDRB, PIN_NUM);
						break;
					case PORT_C :
					    CLR_BIT(DDRC, PIN_NUM);
						break;
					case PORT_D :
						CLR_BIT(DDRD, PIN_NUM);
						break;
					default:
						break;
					}
			break;
			default:
				break;
	}
}

void DIO_Write(uint8 PORT_NUM ,uint8 PIN_NUM ,uint8 value){

	switch(value){
	case HIGH :
		switch(PORT_NUM){
		case PORT_A :
			SET_BIT(PORTA ,PIN_NUM);
			break;
		case PORT_B :
			SET_BIT(PORTB ,PIN_NUM);
			break;
		case PORT_C :
			SET_BIT(PORTC ,PIN_NUM);
			break;
		case PORT_D :
			SET_BIT(PORTD ,PIN_NUM);
			break;
		default:
			break;
		}
		break;
		case LOW :
			switch(PORT_NUM){
					case PORT_A :
						CLR_BIT(PORTA ,PIN_NUM);
						break;
					case PORT_B :
						CLR_BIT(PORTB ,PIN_NUM);
						break;
					case PORT_C :
						CLR_BIT(PORTC ,PIN_NUM);
						break;
					case PORT_D :
						CLR_BIT(PORTD ,PIN_NUM);
						break;
					default:
						break;
					}
			break;
		default:
			break;
	}
}

void DIO_TOGGLE(uint8 PORT_NUM ,uint8 PIN_NUM ){
	switch(PORT_NUM){
						case PORT_A :
							TOGGLE_BIT(PORTA ,PIN_NUM);
							break;
						case PORT_B :
							TOGGLE_BIT(PORTB ,PIN_NUM);
							break;
						case PORT_C :
							TOGGLE_BIT(PORTC ,PIN_NUM);
							break;
						case PORT_D :
							TOGGLE_BIT(PORTD ,PIN_NUM);
							break;
						default:
							break;
						}
}

uint8 DIO_READ(uint8 PORT_NUM ,uint8 PIN_NUM){
	uint8 btn_value =0;
	switch(PORT_NUM){
	case PORT_A :
		btn_value =GET_BIT(PINA ,PIN_NUM);
		break;
	case PORT_B :
		btn_value =GET_BIT(PINB,PIN_NUM);
		break;
	case PORT_C :
		btn_value =GET_BIT(PINC,PIN_NUM);
		break;
	case PORT_D :
		btn_value =GET_BIT(PIND,PIN_NUM);
		break;
	default:
		break;
	}
	return btn_value ;
}
void DIO_WritePort(uint8 PORT_NUM , uint8 value){
	switch(PORT_NUM){
	case PORT_A :
		PORTA = value ;
		break ;
	case PORT_B :
		PORTB =value ;
		break;
	case PORT_C :
		PORTC =value ;
		break;
	case PORT_D :
		PORTD =value;
		break;
	default:
		break;

	}
}
uint8 DIO_ReadPort(uint8 PORT_NUM){
	uint8 Value =0;
	switch(PORT_NUM){
		case PORT_A :
			Value = PINA ;
			break ;
		case PORT_B :
			Value = PINB ;
			break;
		case PORT_C :
			Value = PINC ;
			break;
		case PORT_D :
			Value = PIND ;
			break;
		default:
			break;

		}
	return Value ;
}

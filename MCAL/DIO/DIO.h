/*
 * DIO.h
 *
 *  Created on: Sep 19, 2023
 *      Author: Omar Abdelaziz
 */

/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File: DIO.h
 *       Module:  DIO
 *
 *  Description: DIO header file
 *
 *********************************************************************************************************************/
#ifndef MCAL_DIO_DIO_H_
#define MCAL_DIO_DIO_H_
/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/MCU.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

#define IN 0
#define OUT 1

#define LOW 0
#define HIGH 1

#define PORT_A 0
#define PORT_B 1
#define PORT_C 2
#define PORT_D 3

#define PORTA_PIN0  0
#define PORTA_PIN1  1
#define PORTA_PIN2  2
#define PORTA_PIN3  3
#define PORTA_PIN4  4
#define PORTA_PIN5  5
#define PORTA_PIN6  6
#define PORTA_PIN7  7


#define PORTB_PIN0  0
#define PORTB_PIN1  1
#define PORTB_PIN2  2
#define PORTB_PIN3  3
#define PORTB_PIN4  4
#define PORTB_PIN5  5
#define PORTB_PIN6  6
#define PORTB_PIN7  7

#define PORTC_PIN0  0
#define PORTC_PIN1  1
#define PORTC_PIN2  2
#define PORTC_PIN3  3
#define PORTC_PIN4  4
#define PORTC_PIN5  5
#define PORTC_PIN6  6
#define PORTC_PIN7  7

#define PORTD_PIN0  0
#define PORTD_PIN1  1
#define PORTD_PIN2  2
#define PORTD_PIN3  3
#define PORTD_PIN4  4
#define PORTD_PIN5  5
#define PORTD_PIN6  6
#define PORTD_PIN7  7




/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

void DIO_INIT(uint8  ,uint8  ,uint8 );
void DIO_Write(uint8 ,uint8 ,uint8);
void DIO_TOGGLE(uint8 ,uint8 );
uint8 DIO_READ(uint8,uint8);
void DIO_WritePort(uint8 ,uint8);
uint8 DIO_ReadPort(uint8);
#endif /* MCAL_DIO_DIO_H_ */

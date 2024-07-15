/*
 * Uart.c
 *
 *  Created on: Sep 23, 2023
 *      Author: sherif
 */

#include "../../MCAL/UART/Uart.h"
#include "../../MCAL/UART/Uart_Private.h"
#include "../../MCAL/DIO/DIO.h"
#include "../../LIB/STD.h"
#include "../../LIB/BIT_MATH.h"
#include <stddef.h>

void (*receiveCallback)(uint8)=NULL;

void UART_Init(void)
{
	//u32 BR_Value = 0;

	DIO_INIT(PORT_D ,PORTD_PIN0, IN); //RX
	DIO_INIT(PORT_D ,PORTD_PIN1, OUT); //TX

	UCSRB |= 0b10011000 ;// initialize  interrupt for receiver
	UCSRC |= 0b10000110 ;

	//BR_Value = ((16000000) / (16 * (38400))) - 1;


	UBRRL = 25;//BR_Value ;

}

void UART_SendByte(uint8 data)
{

	UDR = data;

	while(GET_BIT(UCSRA , 5) == 0);

}

void UART_SendString(uint8* str)
{

 uint8 i = 0;

 while(str[i] != '\0')
 {
	 UART_SendByte(str[i]);
	 i++;
 }

}

uint8 UART_ReceiveByte(void)
{

  while(GET_BIT(UCSRA , 7) == 0);
  return UDR;
}

void UART_receiveByteAsynchCallBack(void (*callback)(uint8)) {

    receiveCallback = callback;

}

void __vector_13 (void) __attribute__ ((signal)) ;
void __vector_13 (void) {


    if (receiveCallback != NULL) {
        receiveCallback(UDR);
    }
}

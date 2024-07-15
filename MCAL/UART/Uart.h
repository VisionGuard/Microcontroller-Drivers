/*
 * Uart.h
 *
 *  Created on: Sep 23, 2023
 *      Author: sherif
 */

#ifndef MCAL_UART_UART_H_
#define MCAL_UART_UART_H_

#include"../../LIB/STD.h"

void UART_Init(void);
void UART_SendByte(uint8 );
void UART_SendString(uint8* str);
uint8 UART_ReceiveByte(void);
uint8* UART_ReceiveString(void);
void UART_receiveByteAsynchCallBack(void (*callback)(uint8));

#endif /* MCAL_UART_UART_H_ */

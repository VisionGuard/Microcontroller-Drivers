/*
 * Uart_Private.h
 *
 *  Created on: Sep 23, 2023
 *      Author: sherif
 */

#ifndef MCAL_UART_UART_PRIVATE_H_
#define MCAL_UART_UART_PRIVATE_H_
#include "../../LIB/STD.h"
#define UBRRH   (*((volatile uint8*)0x40))
#define UBRRL   (*((volatile uint8*)0x29))
#define UCSRA   (*((volatile uint8*)0x2B))
#define UCSRB   (*((volatile uint8*)0x2A))
#define UCSRC   (*((volatile uint8*)0x40))
#define UDR     (*((volatile uint8*)0x2C))



#endif /* MCAL_UART_UART_PRIVATE_H_ */

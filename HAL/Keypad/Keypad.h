/*
 * Keypad.h
 *
 *  Created on: Oct 3, 2023
 *      Author: Elyabanya
 */

#ifndef HAL_KEYPAD_KEYPAD_H_
#define HAL_KEYPAD_KEYPAD_H_

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/MCU.h"
#include "../../MCAL/DIO/DIO.h"
#define F_CPU    16000000
#include <util/delay.h>




#define row_port  PORT_B

#define row_1  PORTB_PIN4
#define row_2  PORTB_PIN5
#define row_3  PORTB_PIN6
#define row_4  PORTB_PIN7

#define col_port  PORT_D

#define col_1  PORTD_PIN2
#define col_2  PORTD_PIN3
#define col_3  PORTD_PIN4
#define col_4  PORTD_PIN5

#define KEYPAD_ROW_START   row_1
#define KEYPAD_ROW_END     row_4

#define KEYPAD_COL_START   col_1
#define KEYPAD_COL_END     col_4

void keypad_init(void);
uint8 keypad_read(void);
#endif /* HAL_KEYPAD_KEYPAD_H_ */

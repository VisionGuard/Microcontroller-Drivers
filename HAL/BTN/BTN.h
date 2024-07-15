/*
 * BTN.h
 *
 *  Created on: Sep 19, 2023
 *      Author: Elyabanya
 */

#ifndef HAL_BTN_BTN_H_
#define HAL_BTN_BTN_H_
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD.h"
#include "../../LIB/MCU.h"
#include "../../MCAL/DIO/DIO.h"
#define F_CPU 16000000U
#include <util/delay.h>


#define BTN1_PORT PORT_D
#define BTN1_PIN  PORTD_PIN2

#define BTN2_PORT PORT_D
#define BTN2_PIN  PORTD_PIN3

#define BTN3_PORT PORT_D
#define BTN3_PIN  PORTD_PIN4

#define BTN_1  0
#define BTN_2  1
#define BTN_3  2

void BTN_INIT(uint8);
uint8 BTN_Read(uint8);


#endif /* HAL_BTN_BTN_H_ */

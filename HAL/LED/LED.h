/*
 * LED.h
 *
 *  Created on: Sep 19, 2023
 *      Author: Elyabanya
 */

#ifndef HAL_LED_LED_H_
#define HAL_LED_LED_H_
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD.h"
#include "../../LIB/MCU.h"
#include "../../MCAL/DIO/DIO.h"

#define LED_BLU 3
#define LED_GRN 1
#define LED_RED 0

#define LED_BLU_PORT PORT_C
#define LED_GRN_PORT PORT_C
#define LED_RED_PORT PORT_C

#define LED_BLU_PIN PORTC_PIN3
#define LED_GRN_PIN PORTC_PIN1
#define LED_RED_PIN PORTC_PIN0

void LED_INIT(uint8);
void LED_ON(uint8);
void LED_OFF(uint8);
void LED_TOGGLE(uint8);

#endif /* HAL_LED_LED_H_ */

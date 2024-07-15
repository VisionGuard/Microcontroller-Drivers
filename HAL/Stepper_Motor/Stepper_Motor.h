/*
 * STepper_Motor.h
 *
 *  Created on: 3 Nov 2023
 *      Author: ch
 */

#ifndef HAL_STEPPER_MOTOR_STEPPER_MOTOR_H_
#define HAL_STEPPER_MOTOR_STEPPER_MOTOR_H_

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD.h"
#include "../../LIB/MCU.h"
#include "../../MCAL/DIO/DIO.h"
#define F_CPU    16000000
#include <util/delay.h>

#define Stepper_CW 		0
#define Stepper_CCW 	1

#define Stepper_DIR  	Stepper_CCW

void Stepper_Init(void);
void Stepper_Move(void);
#endif /* HAL_STEPPER_MOTOR_STEPPER_MOTOR_H_ */

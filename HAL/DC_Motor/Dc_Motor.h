/*
 * Dc_Motor.h
 *
 *  Created on: 27 Oct 2023
 *      Author: Omar
 */

#ifndef HAL_DC_MOTOR_DC_MOTOR_H_
#define HAL_DC_MOTOR_DC_MOTOR_H_
//****************************INCLUDES*************************//
#include "../../LIB/MCU.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO/DIO.h"
#include "../../MCAL/TIMER1/TIMER1.h"
//***************************MACROS***************************//
#define CW 1
#define CCW 0
//****************************FUNCTIONS************************//
void DC_Motor_INIT(void);
void DC_Motor1_SetSpeed(uint8 Speed);
void DC_Motor2_SetSpeed(uint8 Speed);
void Both_motors(uint8 Speed);
void DC_Motor_SetDir(uint8 Dir);
void DC_Motor2_SetDir(uint8 Dir);
void DC_Motor_Emergency_Stop(void);
void DC_Motor2_Emergency_Stop(void);
void DC_Motor_Stop(void);
void DC_Motor2_Stop(void);
#endif /* HAL_DC_MOTOR_DC_MOTOR_H_ */

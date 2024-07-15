/*
 * Ultrasonic.h
 *
 *  
 *      Author: mostafa younis
 */

#ifndef HAL_ULTRASONIC_ULTRASONIC_H_
#define HAL_ULTRASONIC_ULTRASONIC_H_
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/MCU.h"
#include "../../LIB/STD.h"
#include "../../MCAL/DIO/DIO.h"
#include "../../MCAL/TIMER1/TIMER1.h"
#include "../../HAL/Ultrasonic/Ultrasonic_Cfg.h"
#define F_CPU    16000000
#include <util/delay.h>


void Ultrasonic_Init(void);
uint16 Ultreasonic_GetDistance(Ultrasonic_type ultra);
#endif /* HAL_ULTRASONIC_ULTRASONIC_H_ */

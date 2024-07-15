/*
 * buz.h
 *
 *  Created on: Sep 19, 2023
 *      Author: Elyabanya
 */

#ifndef HAL_BUZZER_BUZ_H_
#define HAL_BUZZER_BUZ_H_
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD.h"
#include "../../LIB/MCU.h"
#include "../../MCAL/DIO/DIO.h"

#define BUZ_Port PORT_C
#define BUZ_Pin  PORTC_PIN5

void Buzzer_INIT(void);
void Buzzer_ON(void);
void Buzzer_OFF(void);
void Buzzer_Toggle(void);


#endif /* HAL_BUZZER_BUZ_H_ */

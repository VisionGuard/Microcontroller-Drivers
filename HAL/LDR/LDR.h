/*
 * LDR.h
 *
 *  Created on: 30 Jun 2024
 *      Author: ch
 */

#ifndef HAL_LDR_LDR_H_
#define HAL_LDR_LDR_H_

#include "../../MCAL/ADC/ADC.h"
#include "../../MCAL/DIO/DIO.h"

#define FLASH_THRESHOLD  200

void LDR_INIT();
uint16 LDR_READ();

#endif /* HAL_LDR_LDR_H_ */

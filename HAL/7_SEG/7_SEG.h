/*
 * 7_SEG.h
 *
 *  Created on: Sep 19, 2023
 *      Author: Elyabanya
 */

#ifndef HAL_7_SEG_7_SEG_H_
#define HAL_7_SEG_7_SEG_H_
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD.h"
#include "../../LIB/MCU.h"
#include "../../MCAL/DIO/DIO.h"
#include <util/delay.h>
#define Sev_Seg_1 1
#define Sev_Seg_2 2

void Sev_Seg_INIT(uint8);
void Sev_Seg_ON(uint8 , uint8 );
void Sev_Seg_loop(uint8);

#endif /* HAL_7_SEG_7_SEG_H_ */

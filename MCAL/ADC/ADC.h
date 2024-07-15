/*
 * ADC.h
 *
 *  Created on: Oct 14, 2023
 *      Author: omara
 */

#ifndef MCAL_ADC_ADC_H_
#define MCAL_ADC_ADC_H_

#include "../../LIB/MCU.h"
#include "../../LIB/BIT_MATH.h"
#include "ADC_Cfg.h"
#include "ADC_Private.h"
/*ADC Initialization*/
void MADC_VidInit(void);
/*ADC Start Conversion-->Polling , Return ADC Value*/
uint16 MADC_u16ADC_StartConversion(uint8 Copy_u8Channel);
uint16 MADC_u16ADCRead(void);
void ADC_EXTI_voidSetCallBack(void (*funcPtrADC) (void));
void ADC_voidADC_StartConversion_interrupt(uint8 Copy_u8Channel , uint16* result);
#endif /* MCAL_ADC_MADC_H_ */

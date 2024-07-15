/*
 * LDR.c
 *
 *  Created on: 30 Jun 2024
 *      Author: Omar
 */
#include "LDR.h"

void LDR_INIT(){
	MADC_VidInit();
}

uint16 LDR_READ(){
	uint16 LDR_value=0;
	LDR_value = MADC_u16ADC_StartConversion(CHANNEL_0);
	return LDR_value ;
}


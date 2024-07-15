/*
 * Watch_Dog.c
 *
 *  Created on: 3 Nov 2023
 *      Author: Omar
 */
#include "Watch_Dog.h"

void WDT_ON(void){
	SET_BIT(WDTCR ,3);
	CLR_BIT(WDTCR ,0);
	SET_BIT(WDTCR ,1);
	SET_BIT(WDTCR ,2);
}
void WDT_OFF(void){
	WDTCR =0x18;
	WDTCR|=0x00;
}
void WDT_Refresh(){
	WDT_OFF();
	WDT_ON();
}


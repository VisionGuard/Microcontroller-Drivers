/*
 * buz.c

 *
 *  Created on: Sep 19, 2023
 *      Author: Elyabanya
 */

#include "buz.h"

void Buzzer_INIT(void){
	DIO_INIT(BUZ_Port ,BUZ_Pin, OUT);
}
void Buzzer_ON(void){
	DIO_Write(BUZ_Port,BUZ_Pin,HIGH);
}
void Buzzer_OFF(void){
	DIO_Write(BUZ_Port ,BUZ_Pin ,LOW);
}
void Buzzer_Toggle(void){
	DIO_TOGGLE(BUZ_Port ,BUZ_Pin);
}

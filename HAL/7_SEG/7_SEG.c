/*
 * 7_SEG.c

 *
 *  Created on: Sep 19, 2023
 *      Author: Elyabanya
 */
#include "7_SEG.h"
static const uint8 Seven_Segment_Values_g[10] = { 0x7E , 0x0C , 0xB6 , 0x9E , 0xCC , 0xDA , 0xFA , 0x0E , 0xFE , 0xCE};

void Sev_Seg_INIT(uint8 Sev_Seg){
	DDRA =0xFF ;
	switch(Sev_Seg){
	case Sev_Seg_1 :
		DIO_INIT(PORT_C ,6 ,OUT);
		break;
	case Sev_Seg_2 :
		DIO_INIT(PORT_C ,7, OUT);
		break;
	default:
		break;
	}

}
void Sev_Seg_ON(uint8 Sev_Seg , uint8 value){
	switch(Sev_Seg){
	case Sev_Seg_1 :
		DIO_Write(PORT_C ,6 ,HIGH);
		//PORTA = Seven_Segment_Values_g[value];
		DIO_WritePort(PORT_A,Seven_Segment_Values_g[value]);
		_delay_ms(1);
		break;
	case Sev_Seg_2 :
		DIO_Write(PORT_C ,7 ,HIGH);
		DIO_WritePort(PORT_A,Seven_Segment_Values_g[value]);
		_delay_ms(1);
		break;
	default:
		break;
	}
}
void Sev_Seg_loop(uint8 Sev_Seg){
	switch(Sev_Seg){
		case Sev_Seg_1 :
			DIO_Write(PORT_C ,6 ,HIGH);
			for(int i=0; i<10;i++){
				PORTA = Seven_Segment_Values_g[i];
				_delay_ms(1500);
			}
			break;
		case Sev_Seg_2 :
			DIO_Write(PORT_C ,7 ,HIGH);
			for(int i=0; i<10;i++){
				DIO_WritePort(PORT_A,Seven_Segment_Values_g[i]);
				_delay_ms(1500);
			}
			break;
		default:
			break;
		}
}

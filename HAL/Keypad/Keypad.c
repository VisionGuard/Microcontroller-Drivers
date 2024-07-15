/*
 * Keypad.c
 *
 *  Created on: Oct 3, 2023
 *      Author: Elyabanya
 */
#include "Keypad.h"

uint8 keypad[4][4] =
		{
				{ '1' ,'2' ,'3' ,'+'}
				,{'4' ,'5' ,'6' ,'*'}
				,{'7', '8', '9' ,'/'}
				,{'c' ,'0' ,'-' ,'='}
		};

void keypad_init(void){
	DIO_INIT(row_port ,row_1 ,OUT);
	DIO_INIT(row_port ,row_2 ,OUT);
	DIO_INIT(row_port ,row_3 ,OUT);
	DIO_INIT(row_port ,row_4 ,OUT);
	DIO_INIT(col_port ,col_1 ,IN);
	DIO_INIT(col_port ,col_2 ,IN);
	DIO_INIT(col_port ,col_3 ,IN);
	DIO_INIT(col_port ,col_4 ,IN);
	DIO_Write(row_port ,row_1 ,HIGH);
	DIO_Write(row_port ,row_2 ,HIGH);
	DIO_Write(row_port ,row_3 ,HIGH);
	DIO_Write(row_port ,row_4 ,HIGH);
}

uint8 keypad_read(void){
	uint8 ROW =0 , COL =0 , val=0 , btn =0;

	for(ROW=KEYPAD_ROW_START ;ROW <=KEYPAD_ROW_END ;ROW++){
		DIO_Write(row_port ,ROW , LOW);
		for(COL =KEYPAD_COL_START; COL <=KEYPAD_COL_END; COL++){

			val =DIO_READ(col_port,COL);

			if(val ==0){
				btn = keypad[ROW-KEYPAD_ROW_START][COL-KEYPAD_COL_START];
				while(val ==0){
								val =DIO_READ(col_port ,COL);
							}
							_delay_ms(10);
			}
		}
		DIO_Write(row_port ,ROW , HIGH);
	}
	return btn ;
}

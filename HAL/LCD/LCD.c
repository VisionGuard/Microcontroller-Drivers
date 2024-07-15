/*
 * LCD.c
 *
 *  Created on: Sep 23, 2023
 *      Author: OMAR ABAZIZ
 */
/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  FileName.c
 *        \brief
 *
 *      \details
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "LCD.h"
/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
uint8 LCD_CUSTOM_CHARACTERS_g[8][8] = {
			{0x0A,0x1F,0x1F,0x1F,0x1F,0x0E,0x04,0x00},	/* Heart symbol	 */
			{0x04,0x1F,0x11,0x11,0x11,0x11,0x11,0x1F},	/* Empty battery */
			{0x04,0x1F,0x11,0x11,0x11,0x11,0x1F,0x1F},	/*	20% battery  */
			{0x04,0x1F,0x11,0x11,0x11,0x1F,0x1F,0x1F},  /*	40% battery  */
			{0x04,0x1F,0x11,0x11,0x1F,0x1F,0x1F,0x1F},	/*	60% battery  */
			{0x04,0x1F,0x11,0x1F,0x1F,0x1F,0x1F,0x1F},	/*	80% battery  */
			{0x04,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F},	/*	100% battery */
			{0x00,0x00,0x01,0x01,0x05,0x05,0x15,0x15},	/*	Mobile Signal*/
			};
/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
/******************************************************************************
* \Syntax          :void LCD_INIT(void)
* \Description     : LCD Intialization
*******************************************************************************/

void LCD_INIT(void){
	DIO_INIT(LCD_PORT ,RS ,OUT);
	DIO_INIT(LCD_PORT ,EN ,OUT);
	DIO_INIT(LCD_PORT ,D4 ,OUT);
	DIO_INIT(LCD_PORT ,D5 ,OUT);
	DIO_INIT(LCD_PORT ,D6 ,OUT);
	DIO_INIT(LCD_PORT ,D7 ,OUT);

	#if (LCD_MODE == 4)

	/******** LCD 4 BIT MODE COMMANDS ********/

	LCD_WriteCommand(0x33);
	LCD_WriteCommand(0x32);
	LCD_WriteCommand(0x28);

	/****************************************/

	LCD_WriteCommand(0x0C);
	LCD_WriteCommand(0x01);
	LCD_WriteCommand(0x06);
	LCD_WriteCommand(0x02);

	#elif (LCD_MODE ==8)

	#endif
}

/******************************************************************************
* \Syntax          : LCD Write Command
* \Description     : COMMANDS
*******************************************************************************/

void LCD_WriteCommand(uint8 cmd){
	DIO_Write(LCD_PORT , RS ,LOW);
	DIO_Write(LCD_PORT ,EN ,LOW);

	DIO_Write(LCD_PORT,D4 ,GET_BIT(cmd ,4));
	DIO_Write(LCD_PORT,D5,GET_BIT(cmd ,5));
	DIO_Write(LCD_PORT,D6,GET_BIT(cmd ,6));
	DIO_Write(LCD_PORT,D7,GET_BIT(cmd ,7));

	DIO_Write(LCD_PORT , EN ,HIGH);
	_delay_ms(1);
	DIO_Write(LCD_PORT , EN ,LOW);

	DIO_Write(LCD_PORT,D4 ,GET_BIT(cmd ,0));
	DIO_Write(LCD_PORT,D5 ,GET_BIT(cmd ,1));
	DIO_Write(LCD_PORT,D6 ,GET_BIT(cmd ,2));
	DIO_Write(LCD_PORT,D7 ,GET_BIT(cmd ,3));

	DIO_Write(LCD_PORT , EN ,HIGH);
	_delay_ms(1);
	DIO_Write(LCD_PORT , EN ,LOW);
	_delay_ms(5);
}

/******************************************************************************
* \Syntax          : LCD WRITE DATA
* \Description     : DATA "CHARACTERS"
*******************************************************************************/

void LCD_WriteData(uint8 data){

		DIO_Write(LCD_PORT , RS ,HIGH);
		DIO_Write(LCD_PORT ,EN ,LOW);

		DIO_Write(LCD_PORT,D4 ,GET_BIT(data ,4));
		DIO_Write(LCD_PORT,D5 ,GET_BIT(data ,5));
		DIO_Write(LCD_PORT,D6 ,GET_BIT(data ,6));
		DIO_Write(LCD_PORT,D7 ,GET_BIT(data ,7));

		DIO_Write(LCD_PORT , EN ,HIGH);
		_delay_ms(1);
		DIO_Write(LCD_PORT , EN ,LOW);

		DIO_Write(LCD_PORT,D4 ,GET_BIT(data ,0));
		DIO_Write(LCD_PORT,D5 ,GET_BIT(data ,1));
		DIO_Write(LCD_PORT,D6 ,GET_BIT(data ,2));
		DIO_Write(LCD_PORT,D7 ,GET_BIT(data ,3));

		DIO_Write(LCD_PORT , EN ,HIGH);
		_delay_ms(1);
		DIO_Write(LCD_PORT , EN ,LOW);
		_delay_ms(5);
}

/******************************************************************************
* \Syntax          : LCD WRITE STRING
* \Description     : WORDS
*******************************************************************************/

void LCD_WriteString(uint8 * str){
	uint8 i =0;

	while(str[i] != '\0'){

		LCD_WriteData(str[i]);
		i++;
	}
}

/******************************************************************************
* \Syntax          : LCD WRITE INTEGERS
* \Description     : NUMBERS
*******************************************************************************/

void LCD_WriteInteger(sint32 num ){

	uint32 temp =1;
	if(num <0){
		num *=-1 ;
		LCD_WriteData('-');
	}else if(num==0){
		LCD_WriteData('0');
	}
	while(num!=0){
		temp =(temp*10) +(num %10);
		num /=10 ;
	}
	while(temp !=1){
		LCD_WriteData((temp %10)+48);
		temp /=10 ;
	}
}

/******************************************************************************
* \Syntax          : LCD Write Custom Char
* \Description     : Custom Char
*******************************************************************************/
void LCD_WriteCustomChar(void){
	LCD_WriteCommand(0x40);
	uint8 row =0;
	uint8 col =0;

	for(row=0; row<8 ;row++){

		for(col=0; col<8 ; col++){
			LCD_WriteData(LCD_CUSTOM_CHARACTERS_g[row][col]);
		}
	}
}



/******************************************************************************
* \Syntax          :LCD GO TO
* \Description     : ACCESSING COLUMNS AND ROWS
*******************************************************************************/

void LCD_GoTo(uint8 Row,uint8 Col){
	/* 0x80 address or Row zero Col zero, 0x80 address or Row 1 Col zero    */
		uint8 LCD_Loc[2] = {0x80, 0xc0};

		/*	To Go The Destination Location	*/
		LCD_WriteCommand(LCD_Loc[Row]+Col);

}

/******************************************************************************
* \Syntax          : LCD CLEAR
* \Description     : CLEAR
*******************************************************************************/

void LCD_Clear(void){
	LCD_WriteCommand(0x01);
}



/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/




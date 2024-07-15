/*
 * SPI.c
 *
 *  Created on: Jan 14, 2018
 *      Author: Omar
 */

#include "SPI.h"

void SPI_master_init(){
	DIO_INIT(PORT_B ,PORTB_PIN4 ,OUT); //SS
	DIO_INIT(PORT_B ,PORTB_PIN5 ,OUT); //MOSI
	DIO_INIT(PORT_B ,PORTB_PIN6 ,IN);  //MISO
	DIO_INIT(PORT_B ,PORTB_PIN7 ,OUT); //SCK
	SPI_REGS->SPCR.SPR0 =1;
	SPI_REGS->SPCR.SPR1 =1; //Set PRESCALER  "1 , 1" FOSC/128
	SPI_REGS->SPCR.MSTR =1;	//Set as Master
	SPI_REGS->SPCR.SPE =1; //Enable SPI

}
void SPI_slave_init(){
		DIO_INIT(PORT_B ,PORTB_PIN4 ,IN); //SS
		DIO_INIT(PORT_B ,PORTB_PIN5 ,IN); //MOSI
		DIO_INIT(PORT_B ,PORTB_PIN6 ,OUT);  //MISO
		DIO_INIT(PORT_B ,PORTB_PIN7 ,IN); //SCK

		SPI_REGS->SPCR.MSTR =0; //set as slave
		SPI_REGS->SPCR.SPE =1; //enable SPI
		SPI_REGS->SPCR.CPHA =0; //clock phase
		SPI_REGS->SPCR.CPOL =0; //clock polarity
}
uint8 SPI_transceive(uint8 data){
	uint8 recv_data =0;
	SPI_REGS->SPDR =data;
	while(GET_BIT(SPI_REGS->SPSR ,7) == 0); //polling on the SPI flag

	recv_data=SPI_REGS->SPDR ;
	return recv_data;
}
void SPI_send(uint8 data) {
    SPI_REGS->SPDR = data;
    while (GET_BIT(SPI_REGS->SPSR, 7) == 0); // polling on the SPI flag
    // Data has been sent, SPIF flag is set
}
uint8 SPI_receive(void) {
    while (GET_BIT(SPI_REGS->SPSR, 7) == 0); // polling on the SPI flag
    return SPI_REGS->SPDR; // Return received data
}
void SPI_init_trans(){
	DIO_Write(PORT_B ,PORTB_PIN4 ,LOW);
}
void SPI_terminate_trans(){
	DIO_Write(PORT_B ,PORTB_PIN4 ,HIGH);
}
uint8 SPI_FLAG_Check(){
	uint8 FLAG =0;
	if(GET_BIT(SPI_REGS->SPSR ,7) ==1){
		FLAG =1;
	}
	return FLAG ;
}


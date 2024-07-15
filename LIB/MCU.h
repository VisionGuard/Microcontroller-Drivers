/*
 * MCU.h
 *
 * Created: 9/25/2023 11:53:05 AM
 *  Author: Osama
 *	Description:  This file includes macros of DIO REGISTERS of all PORTS (A, B, C, D) to access them 
 */ 


#ifndef MCU_H_
#define MCU_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

#include "STD.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


/* *******************************************	DIO REGISTERS	********************************************/

#define  PINA   *(volatile uint8*)(0x39 )      /*  uint8* is a pointer to uint8  , volatile use to prvent compiler make optimization  */
#define  DDRA   *(volatile uint8*)(0x3A )
#define  PORTA  *(volatile uint8*)(0x3B )

#define  PINB   *(volatile uint8*)(0x36 )
#define  DDRB   *(volatile uint8*)(0x37 )
#define  PORTB  *(volatile uint8*)(0x38 )

#define  PINC   *(volatile uint8*)(0x33 )
#define  DDRC   *(volatile uint8*)(0x34 )
#define  PORTC  *(volatile uint8*)(0x35 )

#define  PIND   *(volatile uint8*)(0x30 )
#define  DDRD   *(volatile uint8*)(0x31 )
#define  PORTD  *(volatile uint8*)(0x32 )

#define SREG    *(volatile uint8*)(0x5F)
#define GICR    *(volatile uint8*)(0x5B)
#define MCUCR   *(volatile uint8*)(0x55)
#define MCUCSR  *(volatile uint8*)(0x54)

/*************************************** ADC Registers ************************************************/#define ADMUX                      (*(volatile uint8 *)(0x27))#define ADCSRA                     (*(volatile uint8 *)(0x26))#define ADCH                       (*(volatile uint8 *)(0x25))#define ADCL                       (*(volatile uint8 *)(0x24))#define ADC_Adjust    (*(volatile uint16*)(0x24))#define SFIOR                      (*(volatile uint8 *)(0x50))/*******************************************************************************************************/
/**************************************** Timers *****************************************************/
#define TCNT0               (*(volatile uint8*)(0x52))
#define TCCR0               (*(volatile uint8*)(0x53))
#define OCR0                (*(volatile uint8*)(0x5C))
#define TIMSK               (*(volatile uint8*)(0x59))
#define TCCR1A              (*(volatile uint8* )(0x4F))#define TCCR1B              (*(volatile uint8* )(0x4E))#define TCNT1H              (*(volatile uint8* )(0x4D))#define TCNT1L              (*(volatile uint8* )(0x4C))#define TCNT1_16BIT_ACCESS  (*(volatile uint16*)(0x4C))#define OCR1AH              (*(volatile uint8*)(0x4B))#define OCR1AL              (*(volatile uint8*)(0x4A))#define OCR1A_16BIT_ACCESS  (*(volatile uint16*)(0x4A))#define OCR1BH              (*(volatile uint8*)(0x49))#define OCR1BL              (*(volatile uint8*)(0x48))#define OCR1B_16BIT_ACCESS  (*(volatile uint16*)(0x48))#define ICR1H               (*(volatile uint8*)(0x47))#define ICR1L               (*(volatile uint8*)(0x46))#define ICR1_16BIT_ACCESS   (*(volatile uint16*)(0x46))


/* TIMSK */
#define OCIE2   7
#define TOIE2   6
#define TICIE1  5
#define OCIE1A  4
#define OCIE1B  3
#define TOIE1   2
#define OCIE0   1
#define TOIE0   0

/* TCCR1A */
#define COM1A1  7
#define COM1A0  6
#define COM1B1  5
#define COM1B0  4
#define FOC1A   3
#define FOC1B   2
#define WGM11   1
#define WGM10   0

/* TCCR1B */
#define ICNC1   7
#define ICES1   6
/* bit 5 reserved */
#define WGM13   4
#define WGM12   3
#define CS12    2
#define CS11    1
#define CS10    0

/**************************************SPI***********************************************************/

typedef struct
{ //bit field
	uint8 SPR0 :1;
	uint8 SPR1 :1;
	uint8 CPHA: 1;
	uint8 CPOL: 1;
	uint8 MSTR: 1;
	uint8 DORD: 1;
	uint8 SPE : 1;
	uint8 SPIE: 1;
}SPCR_BITS;

typedef struct
{
	SPCR_BITS SPCR;
	uint8     SPSR;
	uint8     SPDR;
}SPI_Type;


#define SPI_REGS ((volatile SPI_Type*)(0X2D))
/****************************************************************************************************/

/*******************************************************************************************************/
/**************************************** WDT *****************************************************/

#define WDTCR              (*(volatile uint16*)(0x41))


/* Timer/Counter1 Capture Event */
#define TIMER1_ICU_vect		__vector_6
/* Timer/Counter1 Overflow */
#define TIMER1_OVF_vect			__vector_9


# define sei()  __asm__ __volatile__ ("sei" ::)

#  define ISR(vector,...)            \
void vector (void) __attribute__ ((signal))__VA_ARGS__ ; \
void vector (void)

#define  GLOBAL_ENABLE   sei
#endif /* MCU_H_ */

/**********************************************************************************************************************
 *  END OF FILE: MCU.h
 *********************************************************************************************************************/

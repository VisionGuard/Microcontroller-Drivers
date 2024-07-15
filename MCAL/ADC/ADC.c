/*
 * ADC.c

 *
 *  Created on: Oct 14, 2023
 *      Author: omar abdelaziz
 */
#include "ADC.h"



/*ADC Initialization*/
void MADC_VidInit(void)
{
	/*Select Reference Voltage*/

	/*Set Prescaler*/

	/*Enable To ADC*/
	#if  ADC_VOLTAGE_REFRENCE   ==    ADC_VREF_AVCC

	CLR_BIT(ADMUX , 7);
	SET_BIT(ADMUX, 6 );


	#endif

	#if ADC_ADJUST              ==    ADC_RIGHT_ADJUST

	CLR_BIT(ADMUX , 5); // put in ADMUX reg on pin 5 "0" --->to make right adjust and "1" ---->to make left adjust


	#endif

	#if ADC_CHANNEL             ==    ADC_CHANNEL_1

	SET_BIT(ADMUX, 0 );

	#endif


	#if  ADC_CONVERSION_TRIGGER  ==    ADC_AUTO_TRIGGER

	SET_BIT(ADCSRA, 5 );

	#endif

	#if ADC_PRESCALER           ==    ADC_PRESC_128

	SET_BIT(ADCSRA, 0 );
	SET_BIT(ADCSRA, 1 );
	SET_BIT(ADCSRA, 2 );


	#endif

	#if ADC_INTERRUPT_STATE     ==    ADC_INTERRUPT_DISABLE

	CLR_BIT( ADCSRA , 3 );

	#endif

	// ADC_ENABLE
	SET_BIT(ADCSRA , 7 );
}

/*ADC Start Conversion-->Polling , Return ADC Value*/
uint16 MADC_u16ADC_StartConversion(uint8 Copy_u8Channel)
{
	/*Select Channel*/
	ADMUX = (ADMUX & 0xF8) | (Copy_u8Channel & 0x07);
	/*send Start Conversion*/
	SET_BIT(ADCSRA, 6); // Set bit 6 to start conversion
	/*Wait On ADC Conversion Completed Flag is set to one */
	while (!(ADCSRA & (1 << 4)));

	return ADC_Adjust;
}

uint16 MADC_u16ADCRead(void)
{
	return ADC_Adjust;
}
/****************************************************************************************************/
uint16* temp ;
void (*Callback_Int4) (void) = NULL;
void __vector_17 (void) __attribute__ ((signal)) ;
void __vector_17 (void)
{
	*temp = ADCL;
	*temp = *temp | (ADCH<<8);
	if (NULL != Callback_Int4) {
		Callback_Int4();
	}
}



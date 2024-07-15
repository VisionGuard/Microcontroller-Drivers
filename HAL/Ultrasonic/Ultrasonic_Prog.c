/*
 * Ultrasonic.c
 *
 *  
 *      Author: mostafa younis
 */
#include "Ultrasonic_Int.h"


volatile static uint16 t1 =0,t2=0,d=0;
volatile static uint8 flag =0,count=0;

static struct Ultrasonic_Trigger_pin{
	uint8 trigger;
	};
		
static struct Ultrasonic_Trigger_pin  ultra_Pin;

 		


static void f1 (void){
	if(flag == 0)
	{
		count=0;
		Timer1_InputCaptureEdge(FALLING);
		t1 = ICR1_16BIT_ACCESS;
		flag =1;
	}
	else if(flag ==1)
	{
		Timer1_OVF_InterruptDisable();
		t2 = ICR1_16BIT_ACCESS;
		flag=2;
	}
}

static void f2 (void)
{
	count++;
}

void Ultrasonic_Init(void)
{
	Timer1_ICU_SetCallBack(f1);
	Timer1_OVF_SetCallBack(f2);
	Timer1_ICU_InterruptEnable();
	DIO_INIT(PORT_C,Trigger_Pin1,OUT);
	DIO_INIT(PORT_C,Trigger_Pin2,OUT);
	DIO_INIT(PORT_C,Trigger_Pin3,OUT);
	DIO_INIT(PORT_D,PORTD_PIN6,IN);	
}





uint16 Ultreasonic_GetDistance(Ultrasonic_type ultra)
{
	uint16 time=0,temp=0;
	flag=0;
	uint32 c=0;
	ultra_Pin.trigger=Trigger_Pin1;
	Timer1_InputCaptureEdge(RISING);
	DIO_Write(PORT_C,(ultra_Pin.trigger)+ultra,HIGH);
	_delay_us(10);
	DIO_Write(PORT_C,(ultra_Pin.trigger)+ultra,LOW);
	Timer1_OVF_InterruptEnable();
	while(flag<2)
	{
		c++;
		if(c>=10000)
		{
			_delay_ms(100);
			Timer1_OVF_InterruptDisable();
			flag=3;
			d=999;
		}
	}
	if(flag==2)
	{
		temp = (t2-t1);
		time =	temp + ((uint32)1023*count);
		d = time/116;
	}
	return d;
}


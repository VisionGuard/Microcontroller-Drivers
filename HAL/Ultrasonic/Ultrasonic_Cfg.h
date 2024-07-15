/*
 * Ultrasonic_Cfg.h
 *
 * 
 *  Author: mostafa younis
 */ 


#ifndef ULTRASONIC_CFG_H_
#define ULTRASONIC_CFG_H_



typedef enum{
	ultrasonic_1=0,
	ultrasonic_2,
	ultrasonic_3
}Ultrasonic_type;


#define Trigger_Pin1    PORTC_PIN0    /*first trigger pin */
#define Trigger_Pin2    PORTC_PIN1	
#define Trigger_Pin3    PORTC_PIN3 



#endif /* ULTRASONIC_CFG_H_ */
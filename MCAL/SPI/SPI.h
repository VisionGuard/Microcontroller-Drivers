/*
 * SPI.h
 *
 *  Created on: Jan 14, 2018
 *      Author: Omar
 */

#ifndef SPI_H_
#define SPI_H_

#include "../../LIB/MCU.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD.h"
#include "../../MCAL/DIO/DIO.h"

/************ OPTIONS **********/
#define GLOVE_CONTROL 200
#define AI_CONTROL 201
#define MOBILE_CONTROL 202

#define confirm_msg   'k'
/************ MOTOR1 SPEED **********/
#define Speed1_MIN  0
#define Speed1_MAX  99

/************ MOTOR2 SPEED **********/
#define Speed2_MIN  100
#define Speed2_MAX  199

void SPI_master_init();
void SPI_slave_init();
uint8 SPI_transceive(uint8 data);
void SPI_init_trans();
void SPI_terminate_trans();
uint8 SPI_FLAG_Check();
void SPI_send(uint8 );
uint8 SPI_receive(void);
#endif /* SPI_H_ */



#include "main.h"

uint8 map_value(uint8 x, uint8 in_min, uint8 in_max, uint8 out_min, uint8 out_max) {
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

int main(void)
{
	/************ Initialization of components ************/

		LED_INIT(LED_BLU); //LED for Testing
		LCD_INIT();		//LCD for ULTRASONIC Testing
		PWM_Init();		//PWM used to set speed for DC motors and initialize the timer
		Ultrasonic_Init(); //Get distance
		UART_Init();	//Connect with ARDUINO
		SPI_slave_init(); //Connect with Raspberry pi --> Raspberry "Master"  , AVR "Slave"
		DC_Motor_INIT(); // Turning on the motors
		LDR_INIT();      //Turning on ADC
		 /********************************************************/

		/******************** Variables declaration********************/

	   uint16 dis1=0 ,dis2 =0; //Both ULTRASONIC distances
	   uint8 value=0 ,value1 =0; // FLEX sensors values "in case of using UART"
	   uint8 spi_rcv_data =0;	//The first byte received for SPI which declares whether glove or raspberry will be used
	   sint8 raspbi1_speed =0 ,raspbi2_speed =0; // Speed of DC Motors "when controlling with raspberry"
	   uint8 ultra1_flag =1 ,ultra2_flag =1; // ULTRASONIC distances flags for raspberry
	   uint8 SPI_CHK_1 =0,SPI_CHK_2=0,SPI_CHK_3 =0; // SPI Check Variables
	   uint16 LDR_VAL =0;                  //LDR Value
	   /********************************************************/
	    while (1)
	    {
	    	/*********LDR PART*********************/
	    	LDR_VAL = LDR_READ();  // Read from LDR
	    	if(LDR_VAL >FLASH_THRESHOLD){
	    		LED_OFF(LED_BLU);	// Turn off the flash
	    	}else {
	    		LED_ON(LED_BLU);	// Turn on the flash
	    	}
	    	/*************************************/
	    	//ULTRASONIC Part:
	    	 GLOBAL_ENABLE(); // Enabling global interrupt "needed for ULTRASONIC"
	    	dis1 =Ultreasonic_GetDistance(ultrasonic_1); // Front part
	    	dis2 =Ultreasonic_GetDistance(ultrasonic_2); //Back part
	    	CLR_BIT(SREG, 7); //Disabling global interrupt

	    	/*************************************/
	    	/* Set ULTRASONIC flags to send to Raspberry..*/
	    	if(dis1 <=30){
	    		ultra1_flag ='0';  // 0 false 1 true
	    		ultra2_flag ='3';  // 2 false 3 true
	    	}else {
	    		ultra1_flag ='1';
	    	}
	    	if(dis2 <=30){
	    	    ultra2_flag ='2';
	    	    ultra1_flag ='1';
	    	   }else {
	    	    ultra2_flag ='3';
	    	    }
	    	/*************************************/

	    	if(SPI_FLAG_Check()==1){
	    	SPI_CHK_1=SPI_transceive(confirm_msg);  // Option
	    	SPI_CHK_2=SPI_transceive(ultra1_flag); // '0' or '1'
	    	SPI_CHK_3=SPI_transceive(ultra2_flag);// '2' or '3'

	    	}


	    	if((SPI_CHK_1 ==GLOVE_CONTROL||SPI_CHK_1 ==AI_CONTROL||SPI_CHK_1 ==MOBILE_CONTROL) // Check the Selected option
	    	&& (SPI_CHK_2 >=Speed1_MIN && SPI_CHK_2 <=Speed1_MAX )			// if 1st motor speed ranges from 0 ->99
	    	&& (SPI_CHK_3 >=Speed2_MIN && SPI_CHK_3 <=Speed2_MAX)){		// if 2nd motor speed ranges from 100 ->199

	    		spi_rcv_data =SPI_CHK_1;

	    	if(SPI_CHK_2 >=0 && SPI_CHK_2 <50){ // Backward DIR for 1st Motor

	    		raspbi1_speed =map_value(SPI_CHK_2 ,0,49 ,0,100); // mapping the 1st Motor speed into range 0-100


	    	}else { //Forward DIR for 1st Motor
	    		raspbi1_speed =map_value(SPI_CHK_2 ,50,99 ,0,100); // mapping the 1st Motor speed into range 0-100


	    	}
	    	if(SPI_CHK_3 >=100 && SPI_CHK_3 <150){	// Backward DIR for 2nd Motor
	    		raspbi2_speed =map_value(SPI_CHK_3 ,100,149 ,0,100);	// mapping the 2nd Motor speed into range 0-100


	    	}else {		// Forward DIR for 2nd Motor
	    		raspbi2_speed =map_value(SPI_CHK_3 ,150,199 ,0,100); 	// mapping the 2nd Motor speed into range 0-100


	    	}

	    	}


	    	/*****************RASPBERRY PI part***********************/
	    	if(spi_rcv_data ==AI_CONTROL || spi_rcv_data ==MOBILE_CONTROL ){ //if RASPBERRY sent 'r' or 'm' to AVR

	    		if(ultra1_flag =='0' && SPI_CHK_2 >50  && SPI_CHK_3 >150 ){
	    			raspbi1_speed =0;
	    			raspbi2_speed =0;
	    		}

	    		if(ultra2_flag =='2' && SPI_CHK_2 <50 && SPI_CHK_3 <150 ){
	    			raspbi1_speed =0;
	    			raspbi2_speed =0;
	    		}

				if(SPI_CHK_2>=0 && SPI_CHK_2 <50){ // 1st Motor DIR is Backward
					DC_Motor_SetDir(CCW);
				}else {					 // 1st Motor DIR is Forward
					DC_Motor_SetDir(CW);

				}

				if(SPI_CHK_3 >=100 && SPI_CHK_3 <150){	// 2nd Motor DIR is Backward

					DC_Motor2_SetDir(CCW);

				}else {		// 2nd Motor DIR is Forward

					DC_Motor2_SetDir(CW);
				}

				DC_Motor1_SetSpeed(raspbi1_speed ); //Set speed of the first motor..
				DC_Motor2_SetSpeed(raspbi2_speed );	//Set speed of the second motor..

	    	}

	    	/****************************************************************************/

	    	/************************* GLOVE PART *************************/
	    	if(spi_rcv_data ==GLOVE_CONTROL){
	    		value=UART_ReceiveByte();  // Read the first byte from ARDUINO
	    		value1=UART_ReceiveByte();	// Read the second byte from ARDUINO
	    		LED_ON(LED_BLU);

	    						/******************** MOVING FORWARD *************************/
	    						if((value =='2' || value =='3' || value =='4' || value =='5') &&(value1 =='0')){ //FLEX 1 values

	    										DC_Motor_SetDir(CW); //Set direction as CW
	    										DC_Motor2_SetDir(CW);	//Set direction as CW
	    										if(value =='2'){

	    											Both_motors(85); //Set PWM Duty
	    											}else if(value =='3'){

	    											Both_motors(85);	//Set PWM Duty
	    											}else if(value =='4'){

	    											Both_motors(95);	//Set PWM Duty
	    											}else {

	    											Both_motors(95);	//Set PWM Duty
	    										}
	    									}

	    					/******************** MOVING BACKWARD *************************/
	    					if((value1 =='2' || value1 =='3' || value1 =='4' || value1 =='5')&& (value=='0')) //FLEX 2 values
	    					{

	    						DC_Motor_SetDir(CCW);	//Set direction as CCW
	    						DC_Motor2_SetDir(CCW);	//Set direction as CCW
	    						if(value1 =='2'){

	    						    			Both_motors(85);	//Set PWM Duty
	    						    			}else if(value1 =='3'){

	    						    			Both_motors(85);	//Set PWM Duty
	    						    			}else if(value1 =='4'){

	    						    			Both_motors(95);	//Set PWM Duty
	    						    			}else {
	    						    			Both_motors(95);	//Set PWM Duty
	    						    			}
	    						    					}

	    						  /****************************************************************************/

	    						 /******************** ROTATION *************************/
	    						  if((value!='0' && value!='1') && (value1!='0' && value1!='1')){

	    						    		DC_Motor2_SetDir(CW);	//Set direction as CW
	    						    		DC_Motor_SetDir(CCW);	//Set direction as CCW
	    						    			if(value =='2'){
	    						    				Both_motors(80);	//Set PWM Duty
	    						    				}else if(value =='3'){
	    						    				Both_motors(80);	//Set PWM Duty
	    						    				}else if(value =='4'){
	    						    				Both_motors(95);	//Set PWM Duty
	    						    				}else {
	    						    				Both_motors(95);	//Set PWM Duty
	    						    						}
	    						    					}
	    						/****************************************************************************/

	    						/************************* STOPPING THE CAR **********************************/
	    						if((value =='0' || value =='1') && (value1 =='0' || value1 =='1') ){ // If Both FLEXs are not binded..
	    						    						Both_motors(0);	// Stop the motors...
	    						    					}
	    						/****************************************************************************/
	    						    	}


	    						    }
   	return 0;
   }



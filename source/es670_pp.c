/* ***************************************************************** */
/* File name:		 es670_pp.c					*/
/* File description: Main file for the ES670 Practical Project		*/
/* Author name:      dloubach						*/
/* Creation date:    20jan2015						*/
/* Revision date:    22mai2015						*/
/* ***************************************************************** */

#include "es670_pp.h"
#include "mclab2.h"
#include "ledswi.h"
#include "util.h"
#include "lcd.h"
#include "cooler.h"
#include "sevenseg.h"
#include "serialcom.h"
#include "cmdMachine.h"
#include "buzzer.h"
#include "pwm.h"
#include "adc.h"
#include "pid.h"
#include <stdio.h>

/* uC init configurations */

/* uC @ 48 MHz */
/*#pragma config PLLDIV = 5 			//Divide by 5 (20 MHz oscillator input)
#pragma config CPUDIV = OSC1_PLL2 	//96 MHz PLL Src: /2
#pragma config FOSC   = XTPLL_XT	//XT oscillator, PLL enabled
#pragma config IESO   = OFF			//Oscillator Switchover mode disabled
#pragma config PWRT   = ON			//Power-up Timer enabled
#pragma config BOR    = ON			//Brown-out Reset enabled
#pragma config BORV   = 0			//Brown-out Reset to maximum setting
#pragma config WDT    = OFF			//Watchdog timer disabled
#pragma config LVP    = OFF			//Single-Supply ICSP disabled
*/

/* globals */
volatile unsigned int uiFlagNextPeriod = 0;	// cyclic executive flag
//static int speed;
//static int speedSamples[UTIL_1S_ITERATION_NUM]; // speed samples for cooler
//static int speedIndex = 0; // index in the speedSamples vector
//static unsigned int uiTemperature;
//static int iTempCelsius;
//int iRefTemperature = 30;

unsigned int uiHeaterDutyCicle = 50;

//PID pid;
//unsigned int uiControlEffort;

/* transfer equation for AD to Temperature
 * f(y) = ax + b
 * the parameters apply only in the range
 * ~28oC to ~89oC
 * ADC_TRANSF_EQ_LOW_LIM to ADC_TRANSF_EQ_HIG_LIM
 * which could be obtained when heater is in 50% duty cycle PWM
 */
//#define ADC_TRANSF_EQ_LOW_LIM		350
//#define ADC_TRANSF_EQ_HIG_LIM		500
//#define ADC_TRANSF_EQ_PARAM_A		0.4073
//#define ADC_TRANSF_EQ_PARAM_B		-123.75

/* Constants used on PID controller */
//#define KP	50
//#define KI	0.5
//#define KD	0

/* setup the interruption */
void isr_CyclicExecutive();
#pragma code high_vector=0x08
void isr_HighVector(void)
{
  _asm GOTO isr_CyclicExecutive _endasm
}
#pragma code

/* setup the isr */
#pragma interrupt isr_CyclicExecutive
void isr_CyclicExecutive(void) {
	if (INTCONbits.TMR0IF) {
		/* set the cyclic executive flag */
		uiFlagNextPeriod = 1;

		/* reset the cyclic executive counting */
		util_resetCyclicExecutive();

		/* acknowledge the interrupt */
		INTCONbits.TMR0IF = 0;
	}
}

/* ************************************************ */
/* Method name: 	   es670_runInitialization		*/
/* Method description: takes care of uC intial      */
/*					   configurations				*/
/* Input params:	   n/a 							*/
/* Outpu params:	   n/a 							*/
/* ************************************************ */
void es670_runInitialization(void) {


	/* clean all ports */
	PORTA = CLEAN_DATA;
	PORTB = CLEAN_DATA;
	PORTC = CLEAN_DATA;
	PORTD = CLEAN_DATA;
	PORTE = CLEAN_DATA;

	/* init ADC */
	adc_initAdc();

	/* init leds and switches */

	ledswi_initLedSwitch();
	
	/* init MT */
	cooler_initMT();

	/* init TIMER1 as counter,
	 * used for counting the number of pulses
	 * originated from the cooler
	 */
//	util_initTimer1AsCounter();

	/* init PWM module for MT1 */
	pwm_initPwm(PWM_MT1);

	/* init PWM module for MT2 */
	pwm_initPwm(PWM_MT2);

	/* set DC for MT1 PWM in 50% */
	pwm_setDutyCycle(PWM_DC_100, PWM_MT1);
	/* set DC for MT2 PWM in 50% */
	pwm_setDutyCycle(PWM_DC_100, PWM_MT2);
	
//	pid = pid_init(KP, KI, KD);
}

/* ************************************************ */
/* Method name: 	   es670_prepare			    */
/* Method description: prepare things before execute*/
/*					   the main program loop 		*/
/* Input params:	   n/a 							*/
/* Outpu params:	   n/a 							*/
/* ************************************************ */
void es670_prepare(void) {

}

/* ************************************************ */
/* Method name: 	   es670_commandMachineTask	    */
/* Method description: this task (method) plays with*/
/*					   the command machine and serial com*/
/* Input params:	   n/a 							*/
/* Outpu params:	   n/a 							*/
/* ************************************************ */
void es670_commandMachineTask(void) {

}

/* ************************************************ */
/* Method name: 	   es670_computeCoolerVelocity  */
/* Method description: compute the cooler speed in  */
/*					   RPS (revolutions per second) */
/*													*/
/*                     Period = 1 s                 */
/*													*/
/* Input params:	   n/a 							*/
/* Outpu params:	   n/a 							*/
/* ************************************************ */
/*void es670_computeCoolerVelocity(void) {
	int i;
	char text[10];
//Save the current speed sample and reset the counter 
	speedSamples[speedIndex++] = util_getTimer1Count();
	speedIndex %= UTIL_1S_ITERATION_NUM;
	util_resetTimer1Counter();

//	 Compute the current speed in RPS 
	for (i=0; i<UTIL_1S_ITERATION_NUM; i++) {
		speed += speedSamples[i];
	}
	speed /= COOLER_BLADES_NUM;
}*/

/* ************************************************ */
/* Method name:        es670_computeTemperatureTask */
/* Method description: compute the temperature based*/
/*						in the target sensor D1     */
/*													*/
/*                     Period = 500 ms              */
/*													*/
/* Input params:          n/a						*/
/* Outpu params:          n/a						*/
/* ************************************************ */
/*void es670_computeTemperatureTask(void) {

	adc_startConvertion();
	while (!adc_isAdcDone());

	uiTemperature = adc_getValue();
	iTempCelsius = ADC_TRANSF_EQ_PARAM_A * uiTemperature + ADC_TRANSF_EQ_PARAM_B;
}*/

/* ************************************************ */
/* Method name:        es670_controlTask			*/
/* Method description: Update PID and control the 	*/
/*					   cooler						*/
/* Input params:          n/a						*/
/* Outpu params:          n/a						*/
/* ************************************************ */
/*void es670_controlTask(void) {
	double dControlEffort;
	
	dControlEffort = -pid_update(&pid, iRefTemperature, iTempCelsius);
	dControlEffort = dControlEffort > 1023 ? 1023 : dControlEffort;
	dControlEffort = dControlEffort < 0 ? 0 : dControlEffort;
	uiControlEffort = (unsigned int)dControlEffort;
	pwm_setDutyCycle(uiControlEffort, PWM_COOLER);
	
}*/


/* ************************************************ */
/* Method name: 	   main						    */
/* Method description: main program function        */
/* Input params:	   n/a 							*/
/* Outpu params:	   n/a 							*/
/* ************************************************ */
void main(void) {

	char i;


	/* run uC init configs */
	es670_runInitialization();


	/* encoders configs */ 
	ENCODER1_DIR = INPUT; 
	ENCODER2_DIR = INPUT;


	/* prepare something before entering the main loop */
	es670_prepare();

	/* config and start the cyclic executive */
	util_configCyclicExecutive();

	/* main system loop, runs forever */
	while(TRUE) {
		/* compute cooler velocity task */
//		es670_computeCoolerVelocity();

		/* cooler task */
//		es670_coolerTask();

//		es670_commandMachineTask();
		
//		es670_computeTemperatureTask();
		

//		es670_controlTask();


		ENABLE_12 =1; 
		ENABLE_34 =1; 

		if(ENCODER1)
			ledswi_setLed(1);
		else 
			ledswi_clearLed(1);

		if(ENCODER2)
			ledswi_setLed(2);
		else 
			ledswi_clearLed(2);


		/* WAIT FOR CYCLIC EXECUTIVE PERIOD */
		while(!uiFlagNextPeriod);
		uiFlagNextPeriod = 0;

	} /* while(TRUE) */
}
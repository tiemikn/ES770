/* ***************************************************************** */
/* File name:		 ledswi.c                 						 */
/* File description: This file has a couple of useful functions to   */
/*					 control LEDs and Switches from MCLAB2 dev kit   */
/* Author name:      dloubach										 */
/* Creation date:    20jan2015										 */
/* Revision date:    20jan2015										 */
/* ***************************************************************** */

#include "ledswi.h"
#include "mclab2.h"

/* ************************************************ */
/* Method name: 	   ledswi_initLedSwitch			*/
/* Method description: As the hardware board was    */
/*					   designed with LEDs, this  	*/
/*					   method configures LEDS		*/
/* Input params:	   n/a							*/
/* Outpu params:	   n/a 							*/
/* ************************************************ */
void ledswi_initLedSwitch(void)
{
	IRLED_01_DIR	=	OUTPUT;
	IRLED_02_DIR	=	OUTPUT;
	IRLED_03_DIR	=	OUTPUT;
	IRLED_04_DIR	=	OUTPUT;
	IRLED_05_DIR	=	OUTPUT;
	IRLED_06_DIR	=	OUTPUT;
	GLED_01_DIR		=	OUTPUT;
	GLED_02_DIR		=	OUTPUT;
	GLED_03_DIR		=	OUTPUT;
	GLED_04_DIR		=	OUTPUT;
}


/* ************************************************ */
/* Method name: 	   ledswi_setLed         		*/
/* Method description: set the led ON               */
/* Input params:	   cLedNum  = which LED{1..10}  */
/* Outpu params:	   n/a 							*/
/* ************************************************ */
void ledswi_setLed(char cLedNum)
{
		switch(cLedNum)
		{
			case 1:
				GLED_01 = LED_ON;
				break;
			case 2:
				GLED_02 = LED_ON;
				break;
			case 3:
				GLED_03 = LED_ON;
				break;
			case 4:
				GLED_04 = LED_ON;
				break;
			case 5:
				IRLED_01 = LED_ON;
				break;
			case 6:
				IRLED_02 = LED_ON;
				break;
			case 7:
				IRLED_03 = LED_ON;
				break;
			case 8:
				IRLED_04 = LED_ON;
				break;
			case 9:
				IRLED_05 = LED_ON;
				break;
			case 10:
				IRLED_06 = LED_ON;
				break;
		} /* switch(cLedNum) */
}


/* ************************************************ */
/* Method name: 	   ledswi_clearLed         		*/
/* Method description: set the led OFF              */
/* Input params:	   cLedNum   = which LED {1..10}*/
/* Outpu params:	   n/a 							*/
/* ************************************************ */
void ledswi_clearLed(char cLedNum)
{
	switch(cLedNum)
		{
			case 1:
				GLED_01 = LED_OFF;
				break;
			case 2:
				GLED_02 = LED_OFF;
				break;
			case 3:
				GLED_03 = LED_OFF;
				break;
			case 4:
				GLED_04 = LED_OFF;
				break;
			case 5:
				IRLED_01 = LED_OFF;
				break;
			case 6:
				IRLED_02 = LED_OFF;
				break;
			case 7:
				IRLED_03 = LED_OFF;
				break;
			case 8:
				IRLED_04 = LED_OFF;
				break;
			case 9:
				IRLED_05 = LED_OFF;
				break;
			case 10:
				IRLED_06 = LED_OFF;
				break;
	} 
}
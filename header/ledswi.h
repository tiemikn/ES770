/* ***************************************************************** */
/* File name:		 ledswi.h            							 */
/* File description: Header file containing the function/methods     */
/*					 prototypes of ledswi.c       					 */
/* Author name:      dloubach										 */
/* Creation date:    09jan2015										 */
/* Revision date:    09jan2015										 */
/* ***************************************************************** */

#ifndef LEDSWI_H
#define LEDSWI_H

/* ************************************************ */
/* Method name: 	   ledswi_initLedSwitch   		*/
/* Method description: As the hardware board was    */
/*					   designed with LEDs/Switches  */
/*					   sharing the same pins, this  */
/*					   method configures how many   */
/*					   LEDS and switches will be    */
/*					   available for the application*/
/* Input params:	   n/a							*/
/* Outpu params:	   n/a 							*/
/* ************************************************ */
void ledswi_initLedSwitch(void);


/* ************************************************ */
/* Method name: 	   ledswi_setLed         		*/
/* Method description: set the led ON               */
/* Input params:	   cLedNum    = which LED {1..4}*/
/* Outpu params:	   n/a 							*/
/* ************************************************ */
void ledswi_setLed(char cLedNum);


/* ************************************************ */
/* Method name: 	   ledswi_clearLed         		*/
/* Method description: set the led OFF              */
/* Input params:	   cLedNum    = which LED {1..4}*/
/* Outpu params:	   n/a 							*/
/* ************************************************ */
void ledswi_clearLed(char cLedNum);


#endif /* LEDSWI_H */

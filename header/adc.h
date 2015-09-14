/* ***************************************************************** */
/* File name:		 adc.h							 			 	 */
/* File description: Header file containing the functions/methods    */
/*					 interfaces for handling the ADC module from uC  */
/* Author name:      dloubach										 */
/* Creation date:    21mai2015										 */
/* Revision date:    22mai2015										 */
/* ***************************************************************** */

#ifndef ADC_H
#define ADC_H

#define ADC_CONVERTION_DONE			1
#define ADC_CONVERTION_PROCESSING	0


/* ************************************************ */
/* Method name: 	   adc_initAdc					*/
/* Method description: initialize the ADC configs   */
/* Input params:	   n/a                          */
/* Outpu params:	   n/a 							*/
/* ************************************************ */
void adc_initAdc(void);


/* ************************************************ */
/* Method name: 	   adc_isAdcDone				*/
/* Method description: verify if the AD convertion  */
/*                     is done                      */
/* Input params:	   cChannel                     */
/* Outpu params:	   n/a 							*/
/* ************************************************ */
char adc_isAdcDone(char cChannel);


/* ************************************************ */
/* Method name: 	   adc_startConvertion			*/
/* Method description: start the AD convertion      */
/* Input params:	   cChannel                     */
/* Outpu params:	   n/a 							*/
/* ************************************************ */
void adc_startConvertion(char cChannel);


/* ************************************************ */
/* Method name: 	   adc_getValue					*/
/* Method description: return the value after the   */
/*                     AD convertion is done		*/
/* Input params:	   cChannel                     */
/* Outpu params:	   uiValue						*/
/* ************************************************ */
unsigned int adc_getValue(char cChannel);


#endif /* ADC_H */

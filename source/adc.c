/* ***************************************************************** */
/* File name:		 adc.c							 			 	 */
/* File description: File dedicated to the function implementation   */
/*                   related to ADC module from the uC target        */
/* Author name:      dloubach										 */
/* Creation date:    21mai2015										 */
/* Revision date:    22mai2015										 */
/* ***************************************************************** */

#include "adc.h"
#include "mclab2.h"

/* ************************************************ */
/* Method name: 	   adc_initAdc					*/
/* Method description: initialize the ADC configs   */
/* Input params:	   void	                    */
/* Outpu params:	   n/a 							*/
/* ************************************************ */
void adc_initAdc(void)
{
	/* config the reference voltage */
	ADCON1bits.VCFG1 = 0; //VSS
	ADCON1bits.VCFG0 = 0; //VDD
	/* AD port configuration, for AN0-5 going to ANALOG INPUT */
	ADCON1bits.PCFG = 0b1001;

	/* right justfied */
	ADCON2bits.ADFM = 1;
	/* acquistion time */
	ADCON2bits.ACQT = 0b101;  // 12 TAD

	/* converstion clock */
	ADCON2bits.ADCS = 0b110;  // 64 TOSC

	/* ADC module ON */
	ADCON0bits.ADON = 1;
}



/* ************************************************ */
/* Method name: 	   adc_isAdcDone				*/
/* Method description: verify if the AD convertion  */
/*                     is done                      */
/* Input params:	   cChannel                     */
/* Outpu params:	   cDone 						*/
/* ************************************************ */
char adc_isAdcDone(char cChannel)
{
	unsigned char ucAdcStatus;
	int iReturn;

	/* let's select the CHANNEL in cChannel */
	ADCON0bits.CHS = cChannel;

	/* get the ADC convertion status */
	ucAdcStatus = ADCON0bits.GO_DONE;

	/* check it */
	if(ucAdcStatus)
		iReturn = ADC_CONVERTION_PROCESSING;
	else
		iReturn = ADC_CONVERTION_DONE;

	/* return the result */
	return (iReturn);
}



/* ************************************************ */
/* Method name: 	   adc_startConvertion			*/
/* Method description: start the AD convertion      */
/* Input params:	   cChannel                     */
/* Outpu params:	   n/a 							*/
/* ************************************************ */
void adc_startConvertion(char cChannel)
{
	/* let's select the CHANNEL in cChannel */
	ADCON0bits.CHS = cChannel;

	ADCON0bits.GO_DONE = 1;
}



/* ************************************************ */
/* Method name: 	   adc_getValue					*/
/* Method description: return the value after the   */
/*                     AD convertion is done		*/
/* Input params:	   cChannel                     */
/* Outpu params:	   uiValue 						*/
/* ************************************************ */
unsigned int adc_getValue(char cChannel)
{
	unsigned int uiAdcLowValue;
	unsigned int uiAdcValue;

	/* let's select the CHANNEL in cChannel */
	ADCON0bits.CHS = cChannel;

	/* return the MSB + LSB parts */
	uiAdcLowValue = ADRESL;
	uiAdcValue = (((unsigned int)ADRESH & 0x03) << 8) + uiAdcLowValue;

	return(uiAdcValue);
}

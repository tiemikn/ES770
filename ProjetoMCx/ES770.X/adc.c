/* 
 * File name:           adc.c
 * File description:    Source file for dealing with ADC
 * Author name:         Tiemi e Yuri
 * Creation date:       12 de Setembro de 2015
 * Revision date:       12 de Setembro de 2015
 */

#include "adc.h"
#include "map.h"

/* Method name:         adc_initAdc   
 * Method description:  initializes the ADC AN0-AN5
 * Input params:        n/a
 * Output params:       n/a
 */
void adc_initAdc(void)
{
    /* let's select the CHANNEL 0 */
    ADCON0bits.CHS = 0;

    /* config the reference voltage */
    ADCON1bits.VCFG1 = 0; //VSS
    ADCON1bits.VCFG0 = 0; //VDD
    /* AD port configuration, for AN0-AN5 going to ANALOG INPUT */
    ADCON1bits.PCFG = 0x9;

    /* right justfied */
    ADCON2bits.ADFM = 1;
    /* acquistion time */
    ADCON2bits.ACQT = 0b101; // 12 TAD

    /* converstion clock */
    ADCON2bits.ADCS = 0b110; // 64 TOSC

    /* ADC module ON */
    ADCON0bits.ADON = 1;
}

/* Method name:         adc_isAdcDone
 * Method description:  Verifies ADC status
 * Input params:        n/a
 * Output params:       cIsAdcDone
 */
char adc_isAdcDone(void)
{
    char cAdcStatus;
    char cIsAdcDone;

    /* get the ADC convertion status */
    cAdcStatus = ADCON0bits.GO_DONE;

    /* check it */
    if (cAdcStatus)
        cIsAdcDone = ADC_CONVERTION_PROCESSING;
    else
        cIsAdcDone = ADC_CONVERTION_DONE;

    /* return the result */
    return (cIsAdcDone);
}

/* Method name:         adc_startConvertion
 * Method description:  Starts ADC convertion
 * Input params:        n/a
 * Output params:       n/a
 */
void adc_startConvertion(void)
{
    ADCON0bits.GO_DONE = 1;
}

/* Method name:         adc_getValue
 * Method description:  Gets ADC value
 * Input params:        n/a
 * Output params:       uiValue
 */
unsigned int adc_getValue(void)
{
    unsigned int uiAdcLowValue;
    unsigned int uiAdcValue;

    /* return the MSB + LSB parts */
    uiAdcLowValue = ADRESL;
    uiAdcValue = (((unsigned int) ADRESH & 0x03) << 8) + uiAdcLowValue;

    return (uiAdcValue);
}
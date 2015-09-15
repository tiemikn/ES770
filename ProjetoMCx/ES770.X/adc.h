/* 
 * File name:           adc.h
 * File description:    Header file for dealing with ADC
 * Author name:         Tiemi e Yuri
 * Creation date:       12 de Setembro de 2015
 * Revision date:       12 de Setembro de 2015
 */

#ifndef ADC_H
#define	ADC_H

#define ADC_CONVERTION_DONE			1
#define ADC_CONVERTION_PROCESSING	0

/* Method name:         adc_initAdc   
 * Method description:  initializes the ADC AN0-AN5
 * Input params:        n/a
 * Output params:       n/a
 */
void adc_initAdc(void);

/* Method name:         adc_isAdcDone
 * Method description:  Verifies ADC status
 * Input params:        n/a
 * Output params:       cIsAdcDone
 */
char adc_isAdcDone(void);

/* Method name:         adc_startConvertion
 * Method description:  Starts ADC convertion
 * Input params:        n/a
 * Output params:       n/a
 */
void adc_startConvertion(void);

/* Method name:         adc_getValue
 * Method description:  Gets ADC value
 * Input params:        n/a
 * Output params:       uiValue
 */
unsigned int adc_getValue(void);

#endif	/* ADC_H */

/* 
 * File name:           sensor.c
 * File description:    Source file 
 * Author name:         Tiemi e Yuri
 * Creation date:       12 de Setembro de 2015
 * Revision date:       12 de Setembro de 2015
 */

#include "sensor.h"
#include "map.h"
#include "adc.h"

/* Method name:         sensor_initSensor
 * Method description:  Initialization of ADCs AN0-AN5
 * Input params:        n/a
 * Output params:       n/a
 */
void sensor_initSensor(void)
{
    adc_initAdc();
}

/* Method name:         sensor_getSensorValue
 * Method description:  Gets the value read from ADC
 * Input params:        n/a
 * Output params:       uiSensorValue
 */
unsigned int sensor_getSensorValue(void)
{
    adc_getValue();
}

/* Method name:         sensor_getSensorArray
 * Method description:  Gets the resulting array of values read from ADC
 * Input params:        n/a
 * Output params:       uiSensorArray
 */
unsigned int sensor_getSensorArray(void)
{
    char cChannel;
    unsigned int uiSensorArray[6];
    for (cChannel = 0; cChannel < 6; cChannel++)
    {
        ADCON0bits.CHS = cChannel;
        adc_startConvertion();
        while (!adc_isAdcDone());
        uiSensorArray[cChannel] = adc_getValue();
    }
    return uiSensorArray;
}

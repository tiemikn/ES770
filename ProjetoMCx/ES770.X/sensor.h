/* 
 * File name:           sensor.h
 * File description:    Header file for dealing with sensor values
 * Author name:         Tiemi e Yuri
 * Creation date:       12 de Setembro de 2015
 * Revision date:       12 de Setembro de 2015
 */

#ifndef SENSOR_H
#define	SENSOR_H

/* Method name:         sensor_initSensor
 * Method description:  Initialization of ADCs AN0-AN5
 * Input params:        n/a
 * Output params:       n/a
 */
void sensor_initSensor(void);

/* Method name:         sensor_getSensorValue
 * Method description:  Gets the value read from ADC
 * Input params:        n/a
 * Output params:       uiSensorValue
 */
unsigned int sensor_getSensorValue(void);

/* Method name:         sensor_getSensorArray
 * Method description:  Gets the resulting array of values read from ADC
 * Input params:        n/a
 * Output params:       uiSensorArray
 */
unsigned int sensor_getSensorArray(void);

#endif	/* SENSOR_H */

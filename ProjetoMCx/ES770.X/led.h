/* 
 * File name:           led.h
 * File description:    Header file for dealing with LEDs
 * Author name:         Tiemi e Yuri
 * Creation date:       12 de Setembro de 2015
 * Revision date:       12 de Setembro de 2015
 */

#ifndef LED_H
#define	LED_H

/* Method name:         led_initLed
 * Method description:  Initializes IR and green LEDs
 * Input params:        n/a
 * Output params:       n/a
 */
void led_initLed();

/* Method name:         led_setLed
 * Method description:  Sets IR and green LEDs ON
 * Input params:        cLedID
 * Output params:       n/a
 */
void led_setLed(char cLedID);

/* Method name:         led_clearLed
 * Method description:  Sets IR and green LEDs OFF
 * Input params:        cLedID
 * Output params:       n/a
 */
void led_clearLed(char cLedID);

#endif	/* LED_H */

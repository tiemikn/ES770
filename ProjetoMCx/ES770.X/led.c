/* 
 * File name:           led.c
 * File description:    Source file for dealing with LEDs
 * Author name:         Tiemi e Yuri
 * Creation date:       12 de Setembro de 2015
 * Revision date:       12 de Setembro de 2015
 */

#include "led.h"
#include "map.h"

/* Method name:         led_initLed
 * Method description:  Initializes IR and green LEDs
 * Input params:        n/a
 * Output params:       n/a
 */
void led_initLed()
{
    /* IR & green LEDs */
    IRLED_01_DIR = OUTPUT;
    IRLED_02_DIR = OUTPUT;
    IRLED_03_DIR = OUTPUT;
    IRLED_04_DIR = OUTPUT;
    IRLED_05_DIR = OUTPUT;
    IRLED_06_DIR = OUTPUT;
    GLED_01_DIR = OUTPUT;
    GLED_02_DIR = OUTPUT;
    GLED_03_DIR = OUTPUT;
    GLED_04_DIR = OUTPUT;
}

/* Method name:         led_setLed
 * Method description:  Sets IR and green LEDs ON
 * Input params:        cLedID
 * Output params:       n/a
 */
void led_setLed(char cLedID)
{
    switch (cLedID)
    {
    case 1:
        GLED_01 = ON;
        break;
    case 2:
        GLED_02 = ON;
        break;
    case 3:
        GLED_03 = ON;
        break;
    case 4:
        GLED_04 = ON;
        break;
    case 5:
        IRLED_01 = ON;
        break;
    case 6:
        IRLED_02 = ON;
        break;
    case 7:
        IRLED_03 = ON;
        break;
    case 8:
        IRLED_04 = ON;
        break;
    case 9:
        IRLED_05 = ON;
        break;
    case 10:
        IRLED_06 = ON;
        break;
    }
}

/* Method name:         led_clearLed
 * Method description:  Sets IR and green LEDs OFF
 * Input params:        cLedID
 * Output params:       n/a
 */
void led_clearLed(char cLedID)
{
    switch (cLedID)
    {
    case 1:
        GLED_01 = OFF;
        break;
    case 2:
        GLED_02 = OFF;
        break;
    case 3:
        GLED_03 = OFF;
        break;
    case 4:
        GLED_04 = OFF;
        break;
    case 5:
        IRLED_01 = OFF;
        break;
    case 6:
        IRLED_02 = OFF;
        break;
    case 7:
        IRLED_03 = OFF;
        break;
    case 8:
        IRLED_04 = OFF;
        break;
    case 9:
        IRLED_05 = OFF;
        break;
    case 10:
        IRLED_06 = OFF;
        break;
    }
}

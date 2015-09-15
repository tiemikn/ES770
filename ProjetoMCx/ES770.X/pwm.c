/* 
 * File name:           pwm.c
 * File description:    Source file for dealing with PWM
 * Author name:         Tiemi e Yuri
 * Creation date:       15 de Setembro de 2015
 * Revision date:       15 de Setembro de 2015
 */

#include "pwm.h"
#include "map.h"

/* constant for PWM module activation */
#define PWM_MODE_MASK 	0x0C

/* duty cycle shift and maks definitions */
#define PWM_DC_SHIFT 	0x02
#define PWM_DC_MASK 	0x3FF

/* Method name:         pwm_initPwm
 * Method description:  Initializes PWM configs
 * Input params:        cDevice
 * Output params:       n/a
 */
void pwm_initPwm(char cDevice)
{
    /* configure PWM frequency for 46.875 kHz*/
    /* when 2 PWM are used, the frequency is the same for both */
    PR2 = 0xFF; // TMR2 counter
    T2CON &= 0xFC; // TMR2 prescaler configuration = 1

    /*
     * Target is built to use CCP2 PWM module to
     * activate the cooler
     */
    if (MT1 == cDevice)
    {
        /* configure initial duty cycle */
        pwm_setDutyCycle(PWM_INIT_DC, cDevice);

        /* configure the MT1 ENABLE direction */
        ENABLE_12 = 0x0;
        ENABLE_12_DIR = OUTPUT;

        /* CCPxM3:CCPxM2 = 11 => PWM mode */
        CCP2CON |= PWM_MODE_MASK;
    }

    /*
     * Target is built to use CCP1 PWM module to
     * activate the heater
     */
    if (MT2 == cDevice)
    {
        /* configure initial duty cycle */
        pwm_setDutyCycle(PWM_INIT_DC, cDevice);

        /* configure the MT2 ENABLE direction */
        ENABLE_34 = 0x0;
        ENABLE_34_DIR = OUTPUT;

        /* CCPxM3:CCPxM2 = 11 => PWM mode */
        CCP1CON |= PWM_MODE_MASK;
    }

    /* enable TMR2 */
    T2CONbits.TMR2ON = 1;
}

/* Method name:         pwm_setDutyCycle
 * Method description:  Sets PWM duty cycle
 * Input params:        uiDutyCycle, cDevice
 * Output params:       n/a
 */
void pwm_setDutyCycle(unsigned int uiDutyCycle, char cDevice)
{
    /* MT1 Selected */
    if (MT1 == cDevice)
    {
        CCPR2L = ((uiDutyCycle & PWM_DC_MASK) >> PWM_DC_SHIFT);
        CCP2CONbits.DC2B = (uiDutyCycle & PWM_DC_SHIFT);
    }

    /* MT2 Selected */
    if (MT2 == cDevice)
    {
        CCPR1L = ((uiDutyCycle & PWM_DC_MASK) >> PWM_DC_SHIFT);
        CCP1CONbits.DC1B = (uiDutyCycle & PWM_DC_SHIFT);
    }
}
/* 
 * File name:           motor.c
 * File description:    Source file for dealing with motors
 * Author name:         Tiemi e Yuri
 * Creation date:       15 de Setembro de 2015
 * Revision date:       15 de Setembro de 2015
 */

#include "led.h"
#include "map.h"
#include "pwm.h"

/* Method name:         motor_initMotor
 * Method description:  Initializes PIC outputs for MT1 & MT2
 * Input params:        n/a
 * Output params:       n/a
 */
void motor_initMotor()
{
    /* Motors definition */

    MT1_CW_DIR = OUTPUT;
    MT1_CCW_DIR = OUTPUT;
    MT2_CW_DIR = OUTPUT;
    MT2_CCW_DIR = OUTPUT;
    MT1_CW = 0;
    MT1_CCW = 1;
    MT2_CW = 1;
    MT2_CCW = 0;

    pwm_initPwm(MT1);
    pwm_initPwm(MT2);
}

/* Method name:         motor_setMotorPwm
 * Method description:  Sets PWM outputs for MT1 & MT2
 * Input params:        cMotor, uiPwm
 * Output params:       n/a
 */
void motor_setMotorPwm(char cMotor, unsigned int uiPwm){
    pwm_setDutyCycle(cMotor,uiPwm);
}

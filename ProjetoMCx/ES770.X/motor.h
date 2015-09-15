/* 
 * File name:           motor.h
 * File description:    Hearder file for dealing with motors
 * Author name:         Tiemi e Yuri
 * Creation date:       15 de Setembro de 2015
 * Revision date:       15 de Setembro de 2015
 */

#ifndef MOTOR_H
#define	MOTOR_H

/* Method name:         motor_initMotor
 * Method description:  Initializes PIC outputs for MT1 & MT2
 * Input params:        n/a
 * Output params:       n/a
 */
void motor_initMotor();

/* Method name:         motor_setMotorPwm
 * Method description:  Sets PWM outputs for MT1 & MT2
 * Input params:        cMotor, uiPwm
 * Output params:       n/a
 */
void motor_setMotorPwm(char cMotor, unsigned int uiPwm);

#endif	/* MOTOR_H */

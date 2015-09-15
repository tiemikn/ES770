/* 
 * File name:           pwm.h
 * File description:    Header file for dealing with PWM
 * Author name:         Tiemi e Yuri
 * Creation date:       15 de Setembro de 2015
 * Revision date:       15 de Setembro de 2015
 */

#ifndef PWM_H
#define	PWM_H

#define MT1         0
#define MT2         1

#define PWM_0       0
#define PWM_25      255
#define PWM_50      511
#define PWM_75      767
#define PWM_100     1023
#define PWM_INIT_DC PWM_0

/* Method name:         pwm_initPwm
 * Method description:  Initializes PWM configs
 * Input params:        cDevice
 * Output params:       n/a
 */
void pwm_initPwm(char cDevice);

/* Method name:         pwm_setDutyCycle
 * Method description:  Sets PWM duty cycle
 * Input params:        uiDutyCycle, cDevice
 * Output params:       n/a
 */
void pwm_setDutyCycle(unsigned int uiDutyCycle,char cDevice);

#endif	/* PWM_H */

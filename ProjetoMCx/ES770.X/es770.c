/* 
 * File name:           es770.c
 * File description:    Main file for the ES670 Practical Project
 * Author name:         Tiemi e Yuri
 * Creation date:       12 de Setembro de 2015
 * Revision date:       12 de Setembro de 2015
 */

#include "map.h"
#include "led.h"
#include "sensor.h"
#include "adc.h"
#include "motor.h"
#include "pwm.h"
#include "util.h"

/* Not used with bootloader
//uC @ 48 MHz
#pragma config PLLDIV = 5 		//Divide by 5 (20 MHz oscillator input)
#pragma config CPUDIV = OSC1_PLL2 	//96 MHz PLL Src: /2
#pragma config FOSC   = XTPLL_XT	//XT oscillator, PLL enabled
#pragma config IESO   = OFF		//Oscillator Switchover mode disabled
#pragma config PWRT   = ON		//Power-up Timer enabled
#pragma config BOR    = ON		//Brown-out Reset enabled
#pragma config BORV   = 0		//Brown-out Reset to maximum setting
#pragma config WDT    = OFF		//Watchdog timer disabled
#pragma config LVP    = OFF		//Single-Supply ICSP disabled
 */

/* globals */
volatile unsigned int uiFlagNextPeriod = 0; // cyclic executive flag

/* setup the interruption */
void isr_CyclicExecutive();
#pragma code high_vector=0x08

void isr_HighVector(void)
{
    _asm GOTO isr_CyclicExecutive _endasm
}
#pragma code

/* setup the isr */
#pragma interrupt isr_CyclicExecutive

void isr_CyclicExecutive(void)
{
    if (INTCONbits.TMR0IF)
    {
        /* set the cyclic executive flag */
        uiFlagNextPeriod = 1;

        /* reset the cyclic executive counting */
        util_resetCyclicExecutive();

        /* acknowledge the interrupt */
        INTCONbits.TMR0IF = 0;
    }
}

/* Method name:         es770_init
 * Method description:  initialization method
 * Input params:        n/a
 * Output params:       n/a
 */
void es770_init(void)
{
    /* clean all ports */
    PORTA = CLEAN_DATA;
    PORTB = CLEAN_DATA;
    PORTC = CLEAN_DATA;
    PORTD = CLEAN_DATA;
    PORTE = CLEAN_DATA;

    led_initLed();
    sensor_initSensor;
    motor_initMotor;
}

/* Method name:         main
 * Method description:  ES770 main function
 * Input params:        n/a
 * Output params:       n/a
 */
void main(void)
{
    es770_init;

    /* config and start the cyclic executive */
    util_configCyclicExecutive();

    led_setLed(1);
    led_setLed(2);
    led_setLed(3);
    led_setLed(4);
    led_setLed(5);
    led_setLed(6);
    led_setLed(7);
    led_setLed(8);
    led_setLed(9);
    led_setLed(10);

    motor_setMotorPwm(MT1, PWM_100);
    motor_setMotorPwm(MT2, PWM_75);
    while (1)
    {
        if (ENCODER1)
            led_setLed(2);
        else
            led_clearLed(2);
        if (ENCODER2)
            led_setLed(1);
        else
            led_clearLed(1);
        
        /* WAIT FOR CYCLIC EXECUTIVE PERIOD */
        while (!uiFlagNextPeriod);
        uiFlagNextPeriod = 0;
    }
}

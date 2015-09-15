/* 
 * File name:           util.c
 * File description:    Source file with useful functions
 * Author name:         Tiemi e Yuri
 * Creation date:       15 de Setembro de 2015
 * Revision date:       15 de Setembro de 2015
 */

#include "map.h"
#include "util.h"

/*
FOSC = 48 MHz
tick = 1 / (FOSC/4)
count = time [ms] / tick
timer = 65536 - (Count/prescale)

OR
timer = 65536 - ( (tempo/ (1 / (FOSC/4))) / ps)
 */

/* timer config for 100ms */
#define UTIL_TIMER0_TEMPO 				1000
#define UTIL_TIMER0_FOSC				48000
#define UTIL_TIMER0_PS					256
#define UTIL_TIMER0_RESET_VALUE 		60849
#define UTIL_TIMER0_RESET_VALUE_HIGH    ((UTIL_TIMER0_RESET_VALUE & 0xff00) >> 8)
#define UTIL_TIMER0_RESET_VALUE_LOW 	( UTIL_TIMER0_RESET_VALUE & 0x00ff)

/* Method name:         util_resetCyclicExecutive
 * Method description:  Resets CE interruption counter
 * Input params:        n/a
 * Output params:       n/a
 */
void util_resetCyclicExecutive(void)
{
    TMR0H = UTIL_TIMER0_RESET_VALUE_HIGH;
    TMR0L = UTIL_TIMER0_RESET_VALUE_HIGH;
}

/* Method name:         util_configCyclicExecutive
 * Method description:  Sets CE configs
 * Input params:        n/a
 * Output params:       n/a
 */
void util_configCyclicExecutive(void)
{
    INTCONbits.GIE = 1; // enables all unmasked interrupts
    INTCONbits.PEIE = 1; // enables all unmasked peripheral interrupts
    INTCONbits.TMR0IE = 1; // enables TMR0 overflow interrup

    T0CONbits.T08BIT = 0; // 16-bit timer
    T0CONbits.T0CS = 0; // internal clock (FOSC/4)
    T0CONbits.PSA = 0; // prescaler assigned
    T0CONbits.T0PS = 0b111; // 1:256 prescale

    util_resetCyclicExecutive();

    T0CONbits.TMR0ON = 1; // enables TMR0
}
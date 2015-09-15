/* 
 * File name:           map.h
 * File description:    Port map for ES770-PIC
 * Author name:         Tiemi e Yuri
 * Creation date:       12 de Setembro de 2015
 * Revision date:       12 de Setembro de 2015
 */

#ifndef MAP_H
#define	MAP_H

/* uC registers definition */
#include <p18F4550.h>

#define CLEAN_DATA  0

/* port directions */
#define INPUT       1
#define OUTPUT      0

/* ON/OFF definition */
#define ON          1
#define OFF         0

/* Encoders definition */
#define ENCODER1        PORTBbits.RB1
#define ENCODER1_DIR    TRISBbits.RB1

#define ENCODER2        PORTBbits.RB2
#define ENCODER1_DIR    TRISBbits.RB1

/* Motors definition */
#define MT1_CW          PORTBbits.RB4
#define MT1_CW_DIR      TRISBbits.RB4

#define MT1_CCW         PORTBbits.RB5
#define MT1_CCW_DIR     TRISBbits.RB5

#define MT2_CW          PORTBbits.RB7
#define MT2_CW_DIR      TRISBbits.RB7

#define MT2_CCW         PORTBbits.RB6
#define MT2_CCW_DIR     TRISBbits.RB6

#define ENABLE_12       PORTCbits.RC2
#define ENABLE_12_DIR   TRISCbits.RC2

#define ENABLE_34       PORTCbits.RC1
#define ENABLE_34_DIR   TRISCbits.RC1

/* IR & green LEDs definition */
#define IRLED_01        PORTDbits.RD2
#define IRLED_01_DIR    TRISDbits.RD2

#define IRLED_02        PORTDbits.RD3
#define IRLED_02_DIR    TRISDbits.RD3

#define IRLED_03        PORTDbits.RD4
#define IRLED_03_DIR    TRISDbits.RD4

#define IRLED_04        PORTDbits.RD5
#define IRLED_04_DIR    TRISDbits.RD5

#define IRLED_05        PORTDbits.RD6
#define IRLED_05_DIR    TRISDbits.RD6

#define IRLED_06        PORTDbits.RD7
#define IRLED_06_DIR    TRISDbits.RD7

#define GLED_01         PORTDbits.RD0
#define GLED_01_DIR     TRISDbits.RD0

#define GLED_02         PORTDbits.RD1
#define GLED_02_DIR     TRISDbits.RD1

#define GLED_03         PORTCbits.RC6
#define GLED_03_DIR     TRISCbits.RC6

#define GLED_04         PORTCbits.RC7
#define GLED_04_DIR     TRISCbits.RC7

/* Sensors definition */
#define AN0_TO_AN5      0x09

#define IRREC_01        PORTAbits.RA0
#define IRREC_01_DIR    TRISCbits.RA0

#define IRREC_02        PORTAbits.RA1
#define IRREC_02_DIR    TRISCbits.RA1

#define IRREC_03        PORTAbits.RA2
#define IRREC_03_DIR    TRISCbits.RA2

#define IRREC_04        PORTAbits.RA3
#define IRREC_04_DIR    TRISCbits.RA3

#define IRREC_05        PORTAbits.RA5
#define IRREC_05_DIR    TRISCbits.RA5

#define IRREC_06        PORTEbits.RE0
#define IRREC_06_DIR    TRISCbits.RE0

#endif	/* MAP_H */

/***************************************************************/
/* File name:		SeguidorMap.h					*/
/* File description: Header file containing the peripherals	*/
/* mapping  of the target seguidor de linha used in ES770	*/
/* Author name:      tiemi_yuri						*/
/* Creation date:    31ago2015						*/
/* Revision date:    31ago2015						*/
/************************************************************/

#ifndef SEGUIDORMAP_H
#define SEGUIDORMAP_H

/* uC registers definition */
#include <p18F4550.h>

/* port directions */
#define INPUT			1
#define OUTPUT			0

/* encoders definition */
#define ENCODER1 		    PORTBbits.RB1
#define ENCODER1_DIR		TRISBbits.RB1

#define ENCODER2			PORTBbits.RB2
#define ENCODER2_DIR		TRISBbits.RB2

/* motors definition */
#define MT1_CW			PORTBbits.RB4
#define MT1_CW_DIR		TRISBbits.RB4

#define MT1_CCW			PORTBbits.RB5
#define MT1_CCW_DIR		TRISBbits.RB5

#define MT2_CW			PORTBbits.RB6
#define MT2_CW_DIR		TRISBbits.RB6

#define MT2_CCW			PORTBbits.RB7
#define MT2_CCW_DIR		TRISBbits.RB7

#define ENABLE_12		PORTCbits.RC2
#define ENABLE_12_DIR	TRISCbits.RC2

#define ENABLE_34		PORTCbits.RC1
#define ENABLE_34_DIR	TRISCbits.RC1

#define MT_ON		1
#define MT_OFF		0


/* IR and LED definition */
#define LED_ON			1
#define LED_OFF			0

#define IRLED_01			PORTDbits.RD2
#define IRLED_01_DIR		TRISDbits.RD2

#define IRLED_02			PORTDbits.RD3
#define IRLED_02_DIR		TRISDbits.RD3

#define IRLED_03			PORTDbits.RD4
#define IRLED_03_DIR		TRISDbits.RD4

#define IRLED_04			PORTDbits.RD5
#define IRLED_04_DIR		TRISDbits.RD5

#define IRLED_05			PORTDbits.RD6
#define IRLED_05_DIR		TRISDbits.RD6

#define IRLED_06			PORTDbits.RD7
#define IRLED_06_DIR		TRISDbits.RD7

#define GLED_01				PORTDbits.RD0
#define GLED_01_DIR			TRISDbits.RD0

#define GLED_02				PORTDbits.RD1
#define GLED_02_DIR			TRISDbits.RD1

#define GLED_03				PORTCbits.RC6
#define GLED_03_DIR			TRISCbits.RC6

#define GLED_04				PORTCbits.RC7
#define GLED_04_DIR			TRISCbits.RC7



/* IR REC definition */

#define IRREC_01				PORTEbits.RE0	
#define IRREC_01_DIR			TRISEbits.RE0

#define IRREC_02				PORTAbits.RA5
#define IRREC_02_DIR			TRISAbits.RA5

#define IRREC_03				PORTAbits.RA3
#define IRREC_03_DIR			TRISAbits.RA3

#define IRREC_04				PORTAbits.RA2
#define IRREC_04_DIR			TRISAbits.RA2

#define IRREC_05				PORTAbits.RA1
#define IRREC_05_DIR			TRISAbits.RA1

#define IRREC_06				PORTAbits.RA0
#define IRREC_06_DIR			TRISAbits.RA0


#endif /* MCLAB2_H */

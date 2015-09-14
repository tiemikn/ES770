/* ***************************************************************** */
/* File name:		 pwm.c							 			 	 */
/* File description: File dedicated to the function implementation   */
/*                   related to PWM module from the uC target        */
/* Author name:      dloubach										 */
/* Creation date:    14mai2015										 */
/* Revision date:    22mai2015										 */
/* ***************************************************************** */

#include "pwm.h"
#include "mclab2.h"

/* constant for PWM module activation */
#define PWM_MODE_MASK 	0x0C

/* duty cycle shift and maks definitions */
#define PWM_DC_SHIFT 	0x02
#define PWM_DC_MASK 	0x3FF


/* ************************************************ */
/* Method name: 	   pwm_initPwm					*/
/* Method description: initialize the PWM configs   */
/* Input params:	   ucDevice => PWM_MT1          */
/*                              => PWM_MT2          */
/* Outpu params:	   n/a 							*/
/* ************************************************ */
void pwm_initPwm(unsigned char ucDevice)
{
	/* configure PWM frequency for 46.875 kHz*/
	/* when 2 PWM are used, the frequency is the same for both */
	PR2 = 0xFF;		// TMR2 counter
	T2CON &= 0xFC;	// TMR2 prescaler configuration = 1
	
  	/*
	 * Target is built to use CCP2 PWM module to
	 * activate the cooler
	 */
	if(PWM_MT1 == ucDevice)
	{
		/* configure initial duty cycle */
  		pwm_setDutyCycle(PWM_INIT_DC, ucDevice);
	
		/* configure the MT1 direction */ 
		ENABLE_12 = 0x0;
		ENABLE_12_DIR = OUTPUT;
	
		/* CCPxM3:CCPxM2 = 11 => PWM mode */
		CCP2CON |= PWM_MODE_MASK;
	}
	
	/*
	 * Target is built to use CCP1 PWM module to
	 * activate the heater
	 */
	if(PWM_MT2 == ucDevice)
	{
		/* configure initial duty cycle */
  		pwm_setDutyCycle(PWM_INIT_DC, ucDevice);
	
		/* configure the MT2 direction */ 
		ENABLE_34 = 0x0;
		ENABLE_34_DIR = OUTPUT;
	
		/* CCPxM3:CCPxM2 = 11 => PWM mode */
		CCP1CON |= PWM_MODE_MASK;
	}	
	 
	/* enable TMR2 */
	T2CONbits.TMR2ON = 1;
}



/* ************************************************ */
/* Method name: 	   pwm_setDutyCycle				*/
/* Method description: configure PWM duty cycle     */
/* Input params:	   uiDutyCycle =>duty cyle value*/
/*                     from 0 to 2^10 -1			*/
/*              	   ucDevice => PWM_MT1          */
/*                              => PWM_MT2          */
/* Outpu params:	   n/a 							*/
/* ************************************************ */
void pwm_setDutyCycle(const unsigned int uiDutyCycle,
					  unsigned char ucDevice)
{
	/* MT1 */
	if(PWM_MT1 == ucDevice)
	{
		CCPR2L = ((uiDutyCycle & PWM_DC_MASK) >> PWM_DC_SHIFT);
  		CCP2CONbits.DC2B = (uiDutyCycle & PWM_DC_SHIFT);
 	}
 	
 	/* MT2 */
	if(PWM_MT2 == ucDevice)
	{
		CCPR1L = ((uiDutyCycle & PWM_DC_MASK) >> PWM_DC_SHIFT);
  		CCP1CONbits.DC1B = (uiDutyCycle & PWM_DC_SHIFT);
 	}
//COOLER -> MT1 	HEATER -> MT2 	
}


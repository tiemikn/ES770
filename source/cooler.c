/* ***************************************************************** */
/* File name:		 cooler.c							 			 */
/* File description: File dedicated to the function implementation   */
/*                   related to the COOLER installed in the target   */
/* Author name:      dloubach										 */
/* Creation date:    04mai2015										 */
/* Revision date:    04mai2015										 */
/* ***************************************************************** */

#include "cooler.h"
#include "mclab2.h"


/* ************************************************ */
/* Method name: 	   cooler_initMT			*/
/* Method description: initialize the MT1 & MT2 configs*/
/* Input params:	   n/a                          */
/* Outpu params:	   n/a 							*/
/* ************************************************ */
void cooler_initMT(void)
{
/* motors definition */
/* MT1 CW = 0 & MT2 CW = 1 => BW */
/* MT1 CW = 1 & MT2 CW = 0 => FW */

// obs: a ponte H nao estava funcionando entao trocamos os motores 
// assim q concertar a ponte H lembrar de reinverter os motores !!! 

// verde gira do branco pro verde

MT1_CW			=0;
MT1_CW_DIR		=OUTPUT;
MT1_CCW			=1;
MT1_CCW_DIR		=OUTPUT;

MT2_CW			=1;
MT2_CW_DIR		=OUTPUT;
MT2_CCW			=0;
MT2_CCW_DIR		=OUTPUT;

ENABLE_12		=MT_ON;
ENABLE_12_DIR	=OUTPUT;

ENABLE_34		=MT_ON;
ENABLE_34_DIR	=OUTPUT;
}

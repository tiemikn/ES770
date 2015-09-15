/* 
 * File name:           util.h
 * File description:    Header file with useful functions 
 * Author name:         Tiemi e Yuri
 * Creation date:       15 de Setembro de 2015
 * Revision date:       15 de Setembro de 2015
 */

#ifndef UTIL_H
#define	UTIL_H

/* number of iterations to get 1 second
 * based on cyclic executive period
 */
#define UTIL_1S_ITERATION_NUM			10 

/* Method name:         util_configCyclicExecutive
 * Method description:  Sets CE configs
 * Input params:        n/a
 * Output params:       n/a
 */
void util_configCyclicExecutive(void);

/* Method name:         util_resetCyclicExecutive
 * Method description:  Resets CE interruption counter
 * Input params:        n/a
 * Output params:       n/a
 */
void util_resetCyclicExecutive(void);

#endif	/* UTIL_H */

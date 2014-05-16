/* 
 * File:   main.h
 * Author: Sandor
 *
 * Created on 17. Mai 2014, 00:55
 */

#ifndef MAIN_H
#define	MAIN_H

#ifdef	__cplusplus
extern "C" {
#endif

typedef unsigned int uint;
typedef struct _Matrix {
    uint row;
    uint column;
    uint length;    
} matrix;

void multiplyMatrix(int **, matrix *);
void createMatrix();

#ifdef	__cplusplus
}
#endif

#endif	/* MAIN_H */


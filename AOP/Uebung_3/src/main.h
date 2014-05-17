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
typedef struct Coord {
    uint dimX;
    uint dimY;    
} coord;

void printMatrix(int **, coord *);
void useMatrix(int **, int **, coord *);
int getValues();

#ifdef	__cplusplus
}
#endif

#endif	/* MAIN_H */


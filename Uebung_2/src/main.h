#ifndef __MAIN_H
#define __MAIN_H

/* Benoetigte lib´s */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

/* Neu-Definitionen von Datentypen */
typedef unsigned int u_int;							
typedef unsigned char u_char;										

/* Aufzaehlung der Logarithmen */
typedef enum log_state {	
	LG,
	LN,
	LD
} mylog;

/* Datenstruktur fuer Zahl in Reihenfolge */
struct element {
	double num;
	double res;
};

/* Prototypen */
int round_f(float);
void operate(u_int , u_int , float, u_int);
void print_tbl(u_int, struct element *);	

#endif
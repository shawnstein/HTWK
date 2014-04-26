#ifndef __MAIN_H
#define __MAIN_H

/* Benoetigte lib´s */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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
void operate(u_int , u_int , double, u_int);
void print_tbl(u_int, struct element *);	

#endif
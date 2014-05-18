/* 
 * File:   main.c
 * Author: Sandor
 *
 * Created on 17. Mai 2014, 10:59
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "main.h"

/*Ausgabe der Matrix, die das Ergebnis speichert*/
void printMatrix(int **matrix, coord *ptr) {
    int i, j; /* Schleifenvariablen */
    printf("Drucke Matrix... \n");
    printf("\nErgebnis Matrix C: \n");
/* Schleife solange, wie der X Wert der 2.Matrix erreicht wird */
    for(i = 0; i < ptr[1].dimX; i++) { 
        /* Schleife solange, wie der Y Wert der 2.Matrix erreicht wird */
        for(j = 0; j < ptr[1].dimY; j++) { printf(" %d \t", matrix[i][j]); } 
        printf("\n");
    }
}

/* eigentliche berechnung beider matrizen */
void multiplyMatrix(int **matrixA, int **matrixB, coord *ptr) {
    int **matrixC, i, j, k;
    
    matrixC = (int **) calloc(ptr[1].dimX, sizeof(int *));
    assert(*matrixC == NULL);    
    for(i = 0; i < ptr[1].dimX; i++) matrixC[i] = (int *) calloc(ptr[1].dimY, sizeof(int));
    
    for(i = 0; i < ptr[1].dimX; i++) {
        for(j = 0; j < ptr[1].dimY; j++) {
            for(k = 0; k < ptr[1].dimX; k++) {
                matrixC[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    } printMatrix(matrixC, ptr);
}

/* Einlesen der Werte für die matrizen */
int getValues(uint m) {
    int value = 0;
    m == 0 ? printf("\nWert der Matrix A: ") : printf("\nWert der Matrix B: ");
    scanf("%d", &value);
    
    return value;
}

/* Erstellen der beiden Matrizen */
void createMatrix() {
    /* 2 Zeiger auf je eine Matrix (2 dimensionales Feld!)*/
    int **matrixA, **matrixB, i = 0, j = 0;
    /* zeiger auf struktur coord für die eigenschaften der matrizen */
    coord *ptr = (coord *) calloc(2, sizeof(coord));
    if(ptr != NULL) {
        /*Erstellen Matrix A*/
        printf("X-Groesse fuer A: ");
        scanf("%i", &ptr[0].dimX);
        printf("Y-Groesse fuer A: ");
        scanf("%i", &ptr[0].dimY);
        
        /* allokieren des ersten teil des feldes*/
        matrixA = (int **) calloc(ptr[0].dimX, sizeof(int *));
        assert(*matrixA == NULL);
        /* allokieren des zweiten teil des feldes*/
        for(i = 0; i < ptr[0].dimY; i++) matrixA[i] = (int *) calloc(ptr[0].dimY, sizeof(int));
        /* Matrix A fertig*/
        
        /*Erstellen Matrix B*/
        printf("X-Groesse fuer B: ");
        scanf("%i", &ptr[1].dimX);
        printf("Y-Groesse fuer B: ");
        scanf("%i", &ptr[1].dimY);

        matrixB = (int **) calloc(ptr[1].dimX, sizeof(int *));
        assert(*matrixB == NULL);
        for(i = 0; i < ptr[1].dimX; i++) matrixB[i] = (int *) calloc(ptr[1].dimY, sizeof(int));
        assert(**matrixB == NULL);
        /* Matrix B fertig*/
        
        /* befüllen mit werten für beide felder*/
        for(i = 0; i < ptr[0].dimX; i++) {
            for(j = 0; j < ptr[0].dimY; j++) { matrixA[i][j] = getValues(0); }    
        }
        for(i = 0; i < ptr[1].dimX; i++) {
            for(j = 0; j < ptr[1].dimY; j++) { matrixB[i][j] = getValues(1); }    
        }
        /* beide matrizen und die eigenschaften davon zur berechnung schicken */
        multiplyMatrix(matrixA, matrixB, ptr);
    }
}

int main(int argc, char** argv) {
    createMatrix();
    
    return (EXIT_SUCCESS);
}


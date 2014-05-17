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

void printMatrix(int **matrix, coord *ptr) {
    int i, j;

    for(i = 0; i < ptr[0].dimX; i++) {
        for(j = 0; j < ptr[0].dimY; j++) {
            printf("Wert: %d ", matrix[i][j]);
        } printf("\n");
    }
}

void useMatrix(int **matrixA, int **matrixB, coord *ptr) {
    int i, j;
    
    for(i = 0; i < ptr[0].dimX; i++) {
        for(j = 0; j < ptr[0].dimY; j++) {
            matrixA[i][j] = 2;
        }
    }

    printf("Drucke Matrix... \n");
    printMatrix(matrixA, ptr);
}

int getValues() {
    int value = 0;
    printf("\nWert der Matrix: ");
    scanf("%d", &value);
    
    return value;
}

int main(int argc, char** argv) {
    int **matrixA, **matrixB, i = 0;
   
    coord *ptr = (coord *) calloc(2, sizeof(coord));
    if(ptr != NULL) {
        /*Erstellen Matrix A*/
        printf("X-Groesse fuer A: ");
        scanf("%i", &ptr[0].dimX);
        printf("Y-Groesse fuer A: ");
        scanf("%i", &ptr[0].dimY);

        matrixA = (int **) calloc(ptr[0].dimX, sizeof(int *));
        assert(*matrixA == NULL);
        for(i; i < ptr[0].dimX; i++) matrixA[i] = (int *) calloc(ptr[0].dimY, sizeof(int));
        /* Matrix A fertig*/
        
        /*Erstellen Matrix B*/
        printf("X-Groesse fuer B: ");
        scanf("%i", &ptr[1].dimX);
        printf("Y-Groesse fuer B: ");
        scanf("%i", &ptr[1].dimY);

        matrixB = (int **) calloc(ptr[1].dimX, sizeof(int *));
        assert(*matrixB == NULL);
        for(i; i < ptr[1].dimX; i++) matrixB[i] = (int *) calloc(ptr[1].dimY, sizeof(int));
        /* Matrix B fertig*/
    }
    useMatrix(matrixA, matrixB, ptr);

    return (EXIT_SUCCESS);
}


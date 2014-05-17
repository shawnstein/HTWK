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
    printf("\nErgebnis Matrix C: \n");
    for(i = 0; i < ptr[1].dimX; i++) {
        for(j = 0; j < ptr[1].dimY; j++) { printf(" %d \t", matrix[i][j]); } 
        printf("\n");
    }
}

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
    }  
    printf("Drucke Matrix... \n");
    printMatrix(matrixC, ptr);
}

int getValues(uint m) {
    int value = 0;
    m == 0 ? printf("\nWert der Matrix A: ") : printf("\nWert der Matrix B: ");
    scanf("%d", &value);
    
    return value;
}

void createMatrix() {
    int **matrixA, **matrixB, i = 0, j = 0;
   
    coord *ptr = (coord *) calloc(2, sizeof(coord));
    if(ptr != NULL) {
        /*Erstellen Matrix A*/
        printf("X-Groesse fuer A: ");
        scanf("%i", &ptr[0].dimX);
        printf("Y-Groesse fuer A: ");
        scanf("%i", &ptr[0].dimY);

        matrixA = (int **) calloc(ptr[0].dimX, sizeof(int *));
        assert(*matrixA == NULL);
        for(i = 0; i < ptr[0].dimX; i++) matrixA[i] = (int *) calloc(ptr[0].dimY, sizeof(int));
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
        
        for(i = 0; i < ptr[0].dimX; i++) {
            for(j = 0; j < ptr[0].dimY; j++) { matrixA[i][j] = getValues(0); }    
        }
        for(i = 0; i < ptr[1].dimX; i++) {
            for(j = 0; j < ptr[1].dimY; j++) { matrixB[i][j] = getValues(1); }    
        }
        multiplyMatrix(matrixA, matrixB, ptr);
    }
}

int main(int argc, char** argv) {
    createMatrix();
    
    return (EXIT_SUCCESS);
}


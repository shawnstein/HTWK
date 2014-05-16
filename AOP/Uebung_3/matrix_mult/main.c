/* 
 * File:   main.c
 * Author: Sandor
 *
 * Created on 16. Mai 2014, 16:20
 */

#include <stdio.h>
#include <stdlib.h>

typedef unsigned int uint;
typedef struct _Matrix {
    uint row;
    uint column;
    uint length;    
} matrix;

void multiplyMatrix(int **matrixA, matrix *ptr) {

    uint row = 0, column = 0;
    matrixA[0][0] = 1;
    printf("%d", matrixA[0][0]);
    for(row; row < ptr[0].row; row++) {
        for(column; column < ptr[0].column; column++) {    
            matrixA[1][1] = 1;
        }
    }
}

void createMatrix() {
    matrix *ptr = (matrix *) calloc(2, sizeof(matrix));
    if(ptr != NULL) {    
        printf("Spaltenanzahl der Matrix A >> ");
        scanf("%d", &ptr[0].column);
        printf("Zeilenanzahl der Matrix A >> ");
        scanf("%d", &ptr[0].row);
        printf("Spaltenanzahl der Matrix B >> ");
        scanf("%d", &ptr[1].column);
        printf("Zeilenanzahl der Matrix B >> ");
        scanf("%d", &ptr[1].row);   

        int **dynArray = (int**) calloc(ptr[0].row, ptr[0].column);
        if(dynArray != NULL) {
            printf("test");
            multiplyMatrix(dynArray, ptr);

            free((void*)dynArray);
        }
    }   
}

int main() {
    createMatrix();
    
    return 0;
}
/*
#include <stdio.h>
#include <math.h>
#include <ctype.h>
int main() {

    int A[2][2] = {1, 2, 3, 4};
    int B[2][2] = {1, 2, 3, 4};
    int C[2][2];
    int i, j, k;


    printf("\nProdukt beider Matrizen A*B: ");
    for (i = 0; i < 2; i++) {
	printf("\n");
	for (j = 0; j < 2; j++) { 
            for(k = 0; k < 2; k++ )
                C[i][j] += A[k][j] * B[i][k];
	}
    }
    printf("test [%d]", C[1][1]);
    
    for (i = 0; i < 2; i++) {
        printf("\n");
        for (j = 0; j < 2; j++) {
                printf("[%d]", C[i][j]); 
        }
    }
    
    return 0;
}
 * */
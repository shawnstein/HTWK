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
*/
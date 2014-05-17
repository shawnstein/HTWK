/* 
 * File:   main.c
 * Author: Sandor
 *
 * Created on 17. Mai 2014, 10:59
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
/*
 * 
 */
int main(int argc, char** argv) {
    int **dynArray = (int **) calloc(2, 2);
    assert(dynArray == NULL);
    dynArray[0][0] = 1;
    printf("%d", dynArray[0][0]);
    
    
    return (EXIT_SUCCESS);
}


/*
 * File:   newsimpletest.c
 * Author: Sandor
 *
 * Created on 21.05.2014, 12:19:03
 */

#include <stdio.h>
#include <stdlib.h>
#include "src/main.h"

/*
 * Simple C Test Suite
 */

void testGetValues() {
    int result = getValues();
    if (1 /*check result*/) {
        printf("%%TEST_FAILED%% time=0 testname=testGetValues (newsimpletest) message=error message sample\n");
    }
}

void testMultiplyMatrix() {
    int** p0;
    int** p1;
    coord* p2;
    multiplyMatrix(p0, p1, p2);
    if (1 /*check result*/) {
        printf("%%TEST_FAILED%% time=0 testname=testMultiplyMatrix (newsimpletest) message=error message sample\n");
    }
}

void testPrintMatrix() {
    int** p0;
    coord* p1;
    printMatrix(p0, p1);
    if (1 /*check result*/) {
        printf("%%TEST_FAILED%% time=0 testname=testPrintMatrix (newsimpletest) message=error message sample\n");
    }
}

void createMatrix();

void testCreateMatrix() {
    createMatrix();
    if (1 /*check result*/) {
        printf("%%TEST_FAILED%% time=0 testname=testCreateMatrix (newsimpletest) message=error message sample\n");
    }
}

int main(int argc, char** argv) {
    printf("%%SUITE_STARTING%% newsimpletest\n");
    printf("%%SUITE_STARTED%%\n");

    printf("%%TEST_STARTED%%  testGetValues (newsimpletest)\n");
    testGetValues();
    printf("%%TEST_FINISHED%% time=0 testGetValues (newsimpletest)\n");

    printf("%%TEST_STARTED%%  testMultiplyMatrix (newsimpletest)\n");
    testMultiplyMatrix();
    printf("%%TEST_FINISHED%% time=0 testMultiplyMatrix (newsimpletest)\n");

    printf("%%TEST_STARTED%%  testPrintMatrix (newsimpletest)\n");
    testPrintMatrix();
    printf("%%TEST_FINISHED%% time=0 testPrintMatrix (newsimpletest)\n");

    printf("%%TEST_STARTED%%  testCreateMatrix (newsimpletest)\n");
    testCreateMatrix();
    printf("%%TEST_FINISHED%% time=0 testCreateMatrix (newsimpletest)\n");

    printf("%%SUITE_FINISHED%% time=0\n");

    return (EXIT_SUCCESS);
}

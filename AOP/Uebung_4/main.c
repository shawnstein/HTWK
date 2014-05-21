/* 
 * File:   main.c
 * Author: Sandor
 *
 * Created on 21. Mai 2014, 20:05
 */

#include <stdio.h>
#include <stdlib.h>

#define IN 1
#define OUT 0

int main(int argc, char** argv) {
    int c, n1, nw, nc, state;
    
    state = OUT;
    n1 = nw = nc = 0;
    while((c = getchar()) != EOF) {
        ++nc;
        if(c == '\n') ++n1;
        if(c == '\n' || c == ' ') --nc;
        if(c == ' ' || c == '\t' || c == '\n') state = OUT;
        else if(state == OUT) {
            state = IN;
            ++nw;
        }
    }
    printf("%d Zeile(n) %d Woerter %d Zeichen\n", n1, nw, nc);

    return (EXIT_SUCCESS);
}


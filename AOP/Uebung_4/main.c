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
    int c, n1, nw, nc, state;                               // Var Definition
    
    state = OUT;                                            // setze state auf 0
    n1 = nw = nc = 0;                                       // Var Deklaration
    while((c = getchar()) != EOF) {                         // Hole Zeichen bis EOF (Strg + d)
        ++nc;                                               // Zaehle jedes eingegebene Zeichen
        if(c == '\n') ++n1;                                 // Zaehle Zeilenumbrueche als Zeilenanzahl dazu
        if(c == '\n' || c == ' ') --nc;                     // Ziehe Zeilenumbrueche und Leerzeichen von Anzahl der Zeichen ab
        if(c == ' ' || c == '\t' || c == '\n') state = OUT; // setze state auf 1
        else if(state == OUT) {
            state = IN;                                     // setze state auf 0
            ++nw;                                           // zaehle Wort dazu
        }
    }
    printf("%d Zeile(n) %d Woerter %d Zeichen\n", n1, nw, nc);

    return (EXIT_SUCCESS);
}


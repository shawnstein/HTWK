// Compilen: cc main.c -o uebung -lm
// ausfuehren: ./uebung
// By Sandor Farbas

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef unsigned int u_int;																			// Weniger zum schreiben
typedef unsigned char u_char;																		// weniger zum schreiben

struct element {																					// Struktur zum Speicher der Orginalzahl und Ergebnis
	double  num;
	double res;
};

void operate(u_int, u_int, double, u_int);															// Prototyp
void print_tbl(u_int, struct element *);															// Prototyp


void operate(u_int from, u_int to, double steps, u_int operation) {									// Funktion zur eigentlichen Berechnung
	struct element *elem = (struct element *) malloc(((to - from)/steps) * sizeof(struct element));	// Array von 'element' 
	u_int index = 0;

	for(double i = 0; i < (to - from); i += steps) {		
		elem[index].num = (i) + (double)from;														// Speichern von 'i' + der Startzahl inklusive typecast (int->double)
		switch(operation) {
			case 1: elem[index].res = log(elem[index].num); break;									// Erste Rechenart
			case 2: elem[index].res = log10(elem[index].num); break;								// Zweite Rechenart
			case 3: elem[index].res = log2(elem[index].num); break;									// Dritte Rechenart
		} index++;
	} 
	print_tbl(index-1, elem);																		// Ausgabe der erstellten Tbl
	free(elem);																						// Freigabe des Zeigers
}	

void print_tbl(u_int index, struct element *elem) {													// Aussgabe der zuvor erstellten Tbl
	char c;																							// Var fuer spaeteres ENTER abfangen
	u_int fast_index = 1;
	printf("\n#INFO# - Zeige Ergebnisse... \n");													// Kurze Info per Konsole
	for(u_int i = 0; i < index; i++) {						
		printf("\n%d - %f", fast_index, elem[i].res); 												// Ausgabe des Index und des Ergebnisses
		if(!(fast_index % 10) && (fast_index != 0)) {												// Pruefung auf modulo 10 des Index
			c = getchar();																			// Speichern des Tastatur-Interupts			
			if(c == '\n') printf("\n-------------\n");												// Pruefung auf erwartete Eingabe und ggf. Ausgabe einer Trennlinie
		} fast_index++;
	} printf("\n=============\n");																	// Abschluss mit Trennlinie
}

int main() {

	u_int opt = -1;																					// Var zum spaeteren Schleifeneinstieg
	u_int from, to;																					// Var zu spaeteren Festlegung des Intervals
	u_char loop;																					// Weiterer Schleifeneinstieg und Syntaxpruefung
	double steps = 0;																				// Baustelle

	system("clear");																				// Sys-Befehl zum Bildschirm loeschen
	printf("\nlog-Funktionen by Sandor Farbas\n");													// Credits
	while(opt) {	
		loop = 0;																					// Standardbelegung zur Eingabepruefung
		printf("\n#INFO# - Bitte Option waehlen: \n[1] lg(x)\n[2] ln(x) \n[3] ld(x)\n[0] Exit\n\n"); 
		printf(">> ");
		scanf("%u", &opt);
		while(loop != 3) {
			printf("\n#INFO# - Bitte Start-Interval angeben: ");
			scanf("%d", &from);
			(from == 0) ? printf("\n#ERROR# -  Ein Problem wurde festgestellt. Start-Interval = %d", from) : (loop += 1);
			
			if(loop == 1) {
				printf("\n#INFO# - Bitte Ziel-Intervall angeben: ");
				scanf("%d", &to);
				(to < from) ? printf("\n#ERROR# - Ein Problem wurde festgestellt. Ziel-Interval kleiner als Start-Interval.") : (loop += 1);
			}
			if(loop == 2) {
				printf("\n#INFO# - Bitte Schrittfolge angeben: ");
				scanf("%lf", &steps);
				(steps == 0) ? printf("\n#ERROR# - Ein Problem wurde festgestellt. Schrittfolge ist 0.") : (loop += 1);
			}
		}

		switch(opt) {
			case 1: operate(from, to, steps, 1); break;
			case 2: operate(from, to, steps, 2); break;
			case 3: operate(from, to, steps, 3); break;
			case 0: printf("#INFO# - Beende Programm..."); break;
			default: printf("#ERROR' - Unbekannter Befehl!");
		}
	}
	return 1;
}

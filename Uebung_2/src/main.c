// Compilen: cc main.c -o uebung -lm
// ausfuehren: ./uebung
// cc /usr/home/sandor/Dokumente/GitHub/HTWK/Uebung_2/src/main.c -o /usr/home/sandor/Dokumente/GitHub/HTWK/Uebung_2/bin/a.out -lm

/* Bindung zu Definitionen & weiteren Includes */
#include "main.h"

/* Einmal Runden bitte!*/
int round_f(float x) { 
	if(x > 0) return (int)(x + 0.5);
	else return (int)(x - 0.5);
}

/* Speichern der Zahlen im Interval nach Schritten und Berechnung der log-Funktionen aus diesen */
void operate(u_int from, u_int to, float steps, u_int operation) {	
	u_int index = 0;												/* Indexierung */
	float loop;													/* Init der Schleifevar nach C89-Standard */

	/* Anlegen mehrer Zeiger-Arrays aus der Groesse des Intervals */
	struct element *ptr = (struct element *) malloc(round_f((round_f(to - from) / steps)) * sizeof(struct element));
	
	for(loop = 0; loop < (to - from); loop += steps) {				/* Schleife in Dezimalschritten*/	
		ptr[index].num = (loop) + (float)from; 					/* Addition des Startintervals zum aktuellen Schleifenindex */					
		switch(operation) {
			case LG: ptr[index].res = log(ptr[index].num); break; 	/* Berechnung */			
			case LN: ptr[index].res = log10(ptr[index].num); break;	/* Berechnung */		
			case LD: ptr[index].res = log2(ptr[index].num); break; 	/* Berechnung */					
		} index++;													/* Indexierung um 1 erhoehen */	
	} 
	print_tbl(index-1, ptr);										/* Ausgabe der Datensturktur inklusive der Indexierung */							
	free(ptr);														/* Freigabe des beanspruchten Speichers */								
}	

/* Ausgabe der Datensturktur inklusive der Indexierung */
void print_tbl(u_int index, struct element *elem) {					
	char c;															/* Var zur Speicherung des Tastatur-Interrupts */
	u_int fast_index = 1; 											/* Neuordnung des Indexes, beginnend mit 1 (nicht 0) */
	
	printf("\n#INFO# - Zeige Ergebnisse... \n");						
	for(u_int i = 0; i < index; i++) {						
		printf("%d. %f - %f\t|", fast_index, elem[i].num, elem[i].res); 						
		if(!(fast_index % 10) && (fast_index != 0)) {								
			c = getchar(); 											/* Speichern des Tastaturinterrupts */
			if(c == '\n') printf("\n-------------\n");				/* Vergleich der Tastatureingabe */			
		} fast_index++; 											/* Indexierung um 1 erhoehen */
	} printf("\n=============\n");								
}

int main() {
	u_int opt = -1, from, to;										/* Option, Interval-Start, Interval-Ziel */																	
	u_char loop;													/* Init Schleifen-Var */									
	float steps;												/* Schrittfolge */				

	
	system("clear");												/* Saeubern der Konsole */								
	printf("\nlog-Funktionen by Sandor Farbas\n");						
	while(opt) {	
		loop = 0;									
		printf("\n#INFO# - Bitte Option waehlen: \n[1] lg(x)\n[2] ln(x) \n[3] ld(x)\n[4] Exit\n\n"); 
		printf(">> ");
		scanf("%u", &opt);
		while(loop != 3) {
			printf("\n#INFO# - Bitte Start-Intervall angeben: ");
			scanf("%u", &from);
			(from == 0) ? printf("\n#ERROR# -  Ein Problem wurde festgestellt."
								 "Start-Intervall = %d", 
								 from) : (loop += 1);
			
			if(loop == 1) {
				printf("\n#INFO# - Bitte Ziel-Intervall angeben: "); 
				scanf("%u", &to);
				(to < from) ? printf("\n#ERROR# - Ein Problem wurde festgestellt. "
									 "Ziel-Interval kleiner als Start-Intervall."
									 ) : (loop += 1);
			}
			if(loop == 2) {
				printf("\n#INFO# - Bitte Schrittfolge angeben: ");
				scanf("%f", &steps);			 /* segfault nach scanf */				
				(steps == 0) ? printf("\n#ERROR# - Ein Problem wurde festgestellt. "
									  "Schrittfolge ist 0."
									  ) : (loop += 1); 
			}
		}
		switch(opt) {
			case LG: operate(to, from, steps, LG); break;
			case LN: operate(to, from, steps, LN); break;
			case LD: operate(to, from, steps, LD); break;
			case 4: printf("#INFO# - Beende Programm..."); break;
			default: printf("#ERROR' - Unbekannter Befehl!");
		}
	} return 1;
}

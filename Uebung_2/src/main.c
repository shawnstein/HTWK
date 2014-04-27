// Compilen: cc main.c -o uebung -lm
// ausfuehren: ./uebung
// cc /usr/home/sandor/Dokumente/GitHub/HTWK/Uebung_2/src/main.c -o /usr/home/sandor/Dokumente/GitHub/HTWK/Uebung_2/bin/a.out -lm -g -std=c89
// run with gbd -> gdb ./a.out

/* Bindung zu Definitionen & weiteren Includes */
#include "main.h"

/* Einmal Runden bitte!*/
int round_f(float x) { 
	if(x > 0) return (int)(x + 0.5);
	else return (int)(x - 0.5);
}

/* Speichern der Zahlen im Interval nach Schritten und Berechnung der log-Funktionen aus diesen */
void operate(u_int from, u_int to, float steps, u_int operation) {	
	u_int index = 0;								/* Indexierung */
	float loop;									/* Init der Schleifevar nach C89-Standard */

	/* Anlegen mehrer Zeiger-Arrays aus der Groesse des Intervals */
	struct element *ptr = (struct element *) calloc(round_f((to - from) / steps) , sizeof(struct element));
	if(!ptr){
		fprintf(stderr, "%s Fehler im calloc bei Line %d\n", __TIME__, __LINE__);
		exit(1);
    }
	else {
		for(loop = 0; loop < (to - from); loop += steps) {			/* Schleife in Dezimalschritten*/	
			ptr[index].num = (loop) + (float)from; 				/* Addition des Startintervals zum aktuellen Schleifenindex */					
			switch(operation) {
				case LG: ptr[index].res = log(ptr[index].num); break; 	/* Berechnung */			
				case LN: ptr[index].res = log10(ptr[index].num); break;	/* Berechnung */		
				case LD: ptr[index].res = log2(ptr[index].num); break; 	/* Berechnung */					
			} index++;							/* Indexierung um 1 erhoehen */	
		} 
		print_tbl(index-1, ptr);						/* Ausgabe der Datensturktur inklusive der Indexierung */							
		free(ptr);								/* Freigabe des beanspruchten Speichers */		
	}
}	

/* Ausgabe der Datensturktur inklusive der Indexierung */
void print_tbl(u_int index, struct element *elem) {					
	char c;										/* Var zur Speicherung des Tastatur-Interrupts */
	u_int fast_index = 1; 								/* Neuordnung des Indexes, beginnend mit 1 (nicht 0) */
	
<<<<<<< HEAD
	if(getchar() == '\n') printf("%s #INFO# - Ignoriere letztes [ENTER]... \n", __TIME__);
	printf("%s #INFO# - Zeige Ergebnisse... \n", __TIME__);	
	printf("\n\tIndex\tZahl\t\t-\tErgebnis");
	printf("\n\t----------------------------------------\n");	
	for(u_int i = 0; i <= index; i++) {						
		printf("\n\t%d.\t%.2f\t\t-\t%f\t", fast_index, elem[i].num, elem[i].res); 						
		if(((fast_index % 10) == 0) || (fast_index == 10)) {
			printf("Weiter mit [ENTER]...");
			if(getchar() == '\n') printf("\n\t----------------------------------------\n");				/* Vergleich der Tastatureingabe */			
		} fast_index++; 											/* Indexierung um 1 erhoehen */
	} printf("\n\t\t -END OF STREAM-\n\t========================================\n");								
=======
	printf("\n#INFO# - Zeige Ergebnisse... \n");						
	for(u_int i = 0; i < index; i++) {						
		printf("%d. %f - %f\t|", fast_index, elem[i].num, elem[i].res); 						
		if(!(fast_index % 10) && (fast_index != 0)) {								
			c = getchar(); 							/* Speichern des Tastaturinterrupts */
			if(c == '\n') printf("\n-------------\n");			/* Vergleich der Tastatureingabe */			
		} fast_index++; 							/* Indexierung um 1 erhoehen */
	} printf("\n=============\n");								
>>>>>>> 144f7cc1884244d7a3b490ac509af640b3750d2e
}

int main() {
	u_int opt = -1, from, to;							/* Option, Interval-Start, Interval-Ziel */																	
	u_char loop;									/* Init Schleifen-Var */									
	float steps;									/* Schrittfolge */				

	system("clear");								/* Saeubern der Konsole */								
	printf("\nlog-Funktionen by Sandor Farbas\n");						
	while(opt) {	
		loop = 0;									
		printf("\n%s #INFO# - Bitte Option waehlen: \n\t[1] lg(x)\t[2] ln(x) \t[3] ld(x)\t[0] Exit\n\n", __TIME__); 
		printf(">> ");
		scanf("%u", &opt);
		if(opt == 0) return 1;
		else {
			while(loop != 3) {
				printf("%s #INFO# - Bitte Start-Intervall angeben: ", __TIME__);
				scanf("%u", &from);
				(from == 0) ? printf("#ERROR# -  Ein Problem wurde festgestellt."
									 "Start-Intervall = %d", 
									 from) : (loop += 1);
				if(loop == 1) {
					printf("%s #INFO# - Bitte Ziel-Intervall angeben: ", __TIME__); 
					scanf("%u", &to);
					(to < from) ? printf("%s #ERROR# - Ein Problem wurde festgestellt. "
										 "Ziel-Interval kleiner als Start-Intervall.", 
										 __TIME__) : (loop += 1);
				}
				if(loop == 2) {
<<<<<<< HEAD
					printf("%s #INFO# - Bitte Schrittfolge angeben: ", __TIME__);
					scanf("%f", &steps);			 /* segfault nach scanf */			
					(steps == 0) ? printf("\n%s #ERROR# - Ein Problem wurde festgestellt. "
										  "Schrittfolge ist 0.",
										  __TIME__) : (loop += 1); 
=======
					printf("\n#INFO# - Bitte Schrittfolge angeben: ");
					scanf("%f", &steps);			 	/* segfault nach scanf */			
					(steps == 0) ? printf("\n#ERROR# - Ein Problem wurde festgestellt. "
										  "Schrittfolge ist 0."
										  ) : (loop += 1); 
>>>>>>> 144f7cc1884244d7a3b490ac509af640b3750d2e
				}
			}
			switch(opt) {
				case LG: operate(from, to, steps, LG); break;
				case LN: operate(from, to, steps, LN); break;
				case LD: operate(from, to, steps, LD); break;
				default: printf("%s #ERROR' - Unbekannter Befehl!", __TIME__);
			}
		}
	} return 1;
}

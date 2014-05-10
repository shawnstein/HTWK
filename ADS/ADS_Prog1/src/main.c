/*
git add * && git commit -m "Kommentar" && git push origin master
cc ADS/ADS_Prog1/src/main.c -g -std=c99 -o ADS/ADS_Prog1/bin/a.out && gdb ./ADS/ADS_Prog1/bin/a.out
cc ADS/ADS_Prog1/src/main.c -g -std=c99 -o ADS/ADS_Prog1/bin/a.out && ./ADS/ADS_Prog1/bin/a.out
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef unsigned int u_int;

// Arrays mit Zufallszahlen fuellen zwischen 0 und 100
void fill(u_int *array, u_int len) {
	time_t t;
	time(&t);
	
	srand((u_int)t);
	for(u_int i = 0; i < len; ++i) array[i] = rand() % 100;
}

void swap(u_int *a, u_int *b) {
	u_int swp = *b;
	*b = *a;
	*a = swp;
}

// eigentliche bubblesort funktion
void bubblesort(u_int *array, u_int len) {
	u_int steps = 0;
	for(u_int i = 0; i < (len - 1); ++i) {
		for(u_int j = 0; j < (len - i - 1); ++j) {
			if(array[j] > array[j + 1]) {
				swap(&array[j], &array[j + 1]);
				for(u_int k = 0; k < len; ++k) printf("%d ", array[k]);
				printf("\n");
			}
		}
	}
}

void slowsort(u_int *array, u_int i, u_int j) {
	if(i >= j) return;
	u_int m = (i + j) / 2;
	slowsort(array, i, m);
	slowsort(array, m + 1, j);
	if(array[j] < array[m]) {
		swap(&array[j], &array[m]);
		for(u_int c = 0; c <= sizeof(array); ++c) printf("%d ", array[c]);
		printf("\n");
	}
	slowsort(array, i, j - 1);
}

int main() {
	u_int array[5];
	u_int len = sizeof(array) / sizeof(u_int);
	
	printf("\nGenerate random numbers...");
	fill(array, len);
	
	printf("\nSort by slowsort and print...\n");
	slowsort(array, 0, 4);
	
	printf("\nGenerate random numbers...");
	fill(array, len);
	
	printf("\nSort by bubblesort and print...\n");
	bubblesort(array, len);
	
	return 0;
}
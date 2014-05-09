/*
git add * && git commit -m "Kommentar" && git push origin master
cc /home/sandor/Dokumente/GitHub/HTWK/ADS_Prog1/main.c -g -std=c99 && gdb ./home/sandor/Dokumente/GitHub/HTWK/ADS_Prog1/a.out
cc /home/sandor/Dokumente/GitHub/HTWK/ADS_Prog1/main.c -g -std=c99 && ./home/sandor/Dokumente/GitHub/HTWK/ADS_Prog1/a.out
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef unsigned int u_int;

void fill(u_int *array, u_int len) {
	time_t t;
	time(&t);
	
	srand((u_int)t);
	for(u_int i = 0; i < len; ++i) array[i] = rand() % 100;
}

u_int sort(u_int *array, u_int len) {
	u_int steps = 0;
	for(u_int i = 0; i < len; ++i) {
		for(u_int j = 0; j < len; ++j) {
			for(u_int k = 0; k < len; ++k) printf("%d ", array[k]);
			printf("\n");
			if(array[j] > array[j + 1]) {
				u_int swp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = swp;
				steps++;
			}
		}
	}
	return steps;
}

int main() {
	u_int array[10];
	u_int len = sizeof(array) / sizeof(u_int);

	fill(array, len);
	printf("\ntotal steps: %d\n", sort(array, len));
	
	return 0;
}
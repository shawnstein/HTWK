#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>

/*
void signal_callback_handler(int signum) {
    printf("Ausgeloestes Signal %d\n", signum);
	printf("mache noch mehr irgendwas"); 
	exit(signum);
}

int main() {
	signal(SIGINT, signal_callback_handler);	// Warte auf Interrupt und gib es dem Handler

	while(1) {
		printf("Mache irgendwas.\n");
		sleep(1);
	}
	return 0;
}
*/

typedef unsigned int u_int;
      
struct text { 
	char placeholder[255];
	struct text *next;
};		  


void printList(struct text *l) {
	struct text *list;
	list = l;
	printf("%s\n", list->placeholder);
	while(list->next != NULL) {
		list = list->next;
		printf("%s\n", list->placeholder);
	}	
}

void insertList(struct text **list, char *txt) {
	struct text *new;
	struct text *list_iter = *list;
	
	new = (struct text *) calloc(1, sizeof(*new));
	strcpy(new->placeholder, txt);
	new->next = NULL;
	
	if(list_iter != NULL) {
		while(list_iter->next != NULL) list_iter = list_iter->next;
		list_iter->next = new;
	} else *list = new;
}
 
int main() {
	struct text *list;
	list = NULL;
	
	insertList(&list, "test");
	insertList(&list, "test2");
	insertList(&list, "test3");
	
	printList(list);

	return 0;
}
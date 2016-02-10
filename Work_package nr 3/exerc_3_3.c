/* ====================================
 File name: exerc_3_3.c (or cpp)
 Date: 2016-02-08
 Group Number: 33
 Members that contributed:
 Darja Linkova
 Pooriya Balavi
 Andreas Aronsson
 Demonstration code: 11876
 Important , No code no bonus !
 ====================================== */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//#### Konstanter #####
#define MAX 5

// ##### Typedefs

typedef struct q {
	int number;
	struct q *next;
	struct q *prev;
} REGTYPE;

// ##### Funcion declarations #####

REGTYPE* slumpa_lista(void);
REGTYPE* add_first(REGTYPE* temp, int data);

//###### Main program #######

int main(int argc, char *argv[])
{
	int nr = 0;
	REGTYPE *akt_post, *head = NULL;
	srand(time(0)); // Random seed
	head = slumpa_lista();
	akt_post = head;
	while (akt_post != NULL) {
		printf("\n Post nr %d : %d", nr++, akt_post->number);
		akt_post = akt_post->next;
	}
//todo

// --- Free of allocated memory ---

	while ((akt_post = head) != NULL) {
		head = akt_post->next;
		free(akt_post);
	}

//------------------
	//system("PAUSE");
	//system("CLS");
	return 0;
}

// ====

//Slut main ======================================

REGTYPE* slumpa_lista(void ) {
	int nr,i=0;
	REGTYPE *top, *old, *item, *first;



	top=(REGTYPE*) malloc(sizeof(REGTYPE));
	nr = rand()%100;
	//add node at the beginning
	first = add_first(malloc(sizeof(REGTYPE)), nr);
	top -> number=nr;
	top -> prev=NULL;
	top -> next=NULL;
	item=top;
	i++;
	while(i<MAX){
		old=item;
		item=(REGTYPE*) malloc(sizeof(REGTYPE));
		//To test set all other nodes to nr = 6
		//nr = 6;
		nr=rand()%100;
		item->number=nr;
		item->prev=old;
		item->next=NULL;
		old->next=item;
		i++;
	}
	return(top);

}

//==========================================================

REGTYPE* add_first(REGTYPE* temp, int data) {


// Adds a record first i list and set the field tal to data
	temp->number = data;
	temp->prev = NULL;
	return temp;
}

/* ====================================
 File name: exerc_2_6.c (or cpp)
 Date: 2016-01-27
 Group Number: 33
 Members that contributed:
 Darja Linkova
 Pooria Balavi
 Andreas Aronsson
 Demonstration code: [<Ass code 1-4> <abc>]
 Important , No code no bonus !
 ====================================== */

#include <stdio.h>
#include <stdlib.h>

#define MAX 5
int list[MAX];

/*initializes a list to initially contain
 max nr of vacant positions (-1).*/

void initQue(int list[], int max) {
	for (int i = 0; i < max; i++) {
		list[i] = -1;
	}
}

/*//adds a number in the queue according to the rules ,
 and returns number 1 if the number could be entered and
 0 if the queue is full.
 vacancy in queue is represented by -1*/
int input(int list[], int number, int max) {
	for (int i = 0; i < max; ++i) {
		if (list[i] == -1) {
			list[i] = number;
			return 1;
		}
	}
	return 0;
}

/*replaces int with -1 in the last position*/
int output(int list[], int max) {
	for (int i = 0; i < max - 1; i++) {
		if (list[i] != -1) {
			list[i] = list[i + 1];
		}
	}
	list[max - 1] = -1;
	return 0;
}

/*prints the line of numbers */
void print(int list[]) {
	for (int i = 0; i < MAX; i++) {
		printf("%d" "%s", list[i], " ");
	}
	printf("\n");
}

int main() {
	int que[MAX];
	int max = MAX;
	initQue(que, max);
	print(que);
	input(que, 3, max);
	input(que, 4, max);
	input(que, 5, max);
	print(que);
	input(que, 8, max);
	print(que);
	output(que, max);
	print(que);

	return 0;
}


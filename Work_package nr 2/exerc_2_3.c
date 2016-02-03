/* ====================================
 File name: exerc_2_3.c (or cpp)
 Date: 2016-02-02
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
#include <string.h>

#define MAX 100
/*
 Create a program that reads in two strings from the command line
 when program starts and checks if it is two strings and if the
 two strings are identical or not.
 Do this with and without library function strcmp(..).
 */

int compare(char[], char[]);

int main(int argc, char *argv[]) {

	char argument1[MAX];
	char argument2[MAX];
	int compareResult;

	if (argc != 3) {
		printf(
				"Please input the correct amount of arguments\nEX: ./ex2_3 arg1 arg2 \n");
	} else {
		if (strcmp(argv[1], argv[2]) == 0) {
			printf("The strings are identical\n");
		} else {
			printf("The strings are not identical\n");
		}

		// without string compare
		compareResult = compare(argv[1], argv[2]);
		if (compareResult == 1) {
			printf("Without strcmp: The strings are identical\n");
			return EXIT_SUCCESS;
		} else {
			printf("Without strcmp: The strings are not identical\n");
			return EXIT_FAILURE;
		}
	}
}

// return 0 when arguments are equal
int compare(char argument1[], char argument2[]) {
	int i = 0;
	// 1 if not equal 1 if equal
	int isEqual = 0;

	while (argument1[i] != '\0' && argument2[i] != '\0') {
		if (argument1[i] != argument2[i]) {
			isEqual = 1;
			break;
		}
		i++;
	}
	if (isEqual == 0) {
		return 1;
	} else {
		return 0;
	}

}


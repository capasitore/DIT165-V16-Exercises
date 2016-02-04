#include <stdio.h>
#include <string.h>

/* ====================================
File name: exerc_2_1.c (or cpp)
Date: 2016-mm-dd
Group Number: 33
Members that contributed:
Darja Linkova
Pooriya Balavi
Andreas Aronsson
Demonstration code: 88085
Important , No code no bonus !
====================================== */



// Write a program that reads in a string with max 20 characters
// from stdin to a local string variable .

// Copy the string to another string by using :
// a) strcpy -- DONE
// b) A function void copyString(…) not using any libray function.


#define MAX_LENGTH 20

void copyString(char [], char []);

int main() {
	char src[MAX_LENGTH];
	char destination[MAX_LENGTH];

	//A
	printf("A)  (using strcpy) Enter an string using max %d characters: \n", MAX_LENGTH);
	fgets(src, MAX_LENGTH, stdin);
	strcpy(destination, src);
	 printf("Source string:  %s\n", src);
	 printf("Destination string: %s\n", destination);

	//B
	char src2[MAX_LENGTH];
	char destination2[MAX_LENGTH];
	printf("B) Enter your sting using max %d characters: \n", MAX_LENGTH);
	gets(src2);

	copyString(destination2, src2);

	   printf("Source string:      %s\n", src2);
	   printf("Destination string: %s\n", destination2);

	return 0;
}

void copyString(char destination2[], char src2[]){
	int i = 0;

	while(src2[i] != '\0'){
		destination2[i] = src2[i];
		i++;
	}
	destination2[i] = '\0';
	printf("test");
}


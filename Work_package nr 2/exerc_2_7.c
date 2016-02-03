/* ====================================
File name: exerc_2_7.c (or cpp)
Date: 2016-02-03
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


/*
Create a program that checks an entered Swedish person number.
The number is entered in the form of : 71 07 25 4786 (yymmddxxxx).
The number should be read in as a string and then converted to
integers for year, month , day and number.

The last digit (6) is a control digit and is calculated from the other
digits by an algorithm that you can find on the internet.

The user inputs the number, the program first checks that the number of month and day
is in the right range and after that calculate and checks the control digit.
The program then prints out the result and asks for a new person number.
This is repeated until the user inputs a ‘q’.
*/

#define LINE_MAX 11
char * inputNumbers[LINE_MAX];

void readPersnr( char *person){

	//printf("Your number is:%s", person);
	//convert char to int
	//int i = person[0] - '0';


	//printf("\n\t# Input personal number: ");
	int i = 0;
	char c;
	while ((c = getchar()) != '\n' && i < (LINE_MAX-1)) {
		*(person + i) = c;
		i++;
	}
	*(person + (LINE_MAX - 1)) = '\0';

}

/*int isValid(char *persnr) {
	return controlDigit(persnr) % 10 == 0 ? 0 : 1;

}*/


//if 1 persnr is valid
int controlDigit(const char * persnr){
	int number;
		int num;
		int sum = 0;

	for (int i = 0; i < (LINE_MAX - 1); i++) {

		if (persnr[i] % 2 != 0) {
			number = num * 1;
		}
		else {
			number = num * 2;
		}
		if (number > 9){
			number -= 9;
			sum += number;
		}


}
	int correct = (sum % 10);
	if(correct == 0){
		return 1;
	} else {
		return 0;
	}

}

int main(int argc, char*argv[]) {
	//get person numbers as string
	//convert to int
	//int i = c[0] - '0';
	do {
		printf("Enter a person number: \n");
			fgets(inputNumbers, LINE_MAX, stdin);
			readPersnr(inputNumbers);
			if (inputNumbers[0] =='q') {
				printf("q has been used as input");

				//EXIT_FAILURE;
				break;
			} else {
				controlDigit(inputNumbers) == 1 ? printf("Person number is valid\n") : printf("Person number is Invalid \n");
				//isValid(inputNumbers) == 1 ? printf("Person number is valid\n") : printf("Person number is Invalid \n");
			}
		} while (1);

		return 0;

}




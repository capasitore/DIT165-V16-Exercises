/* ====================================
File name: exerc_2_7.c (or cpp)
Date: 2016-02-02
Group Number: 33
Members that contributed:
Darja Linkova
Pooriya Balavi
Andreas Aronsson
Demonstration code: 85247
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


//check if out of range

#define LINE_MAX 11
char * inputNumbers[LINE_MAX];

void readPersnr( char *person){

    int i = 0;
    char c;
    while ((c = getchar()) != '\n' && i < (LINE_MAX-1)) {
        *(person + i) = c;
        i++;
    }
    *(person + (LINE_MAX - 1)) = '\0';

}



//if 1 persnr is valid
int controlDigit(const char * persnr){


    int year;
    int month;
    int day;
    int control;
    year = (*persnr - 48) * 10 + (*(persnr + 1) - 48);
    month = (*(persnr + 2) - 48) * 10 + (*(persnr + 3) - 48);
    day = (*(persnr + 4) - 48) * 10 + (*(persnr + 5) - 48);
    control = (*(persnr + 9) - 48);

    int checksum = 0;
    if (month > 0 && month < 13) {
        if (day > 0 && day < 32) {
            for (int i = 0; i < LINE_MAX - 2; i++) {
                0 == (i % 2) ?
                    (checksum += ((*(persnr + i) - 48) * 2 / 10 + (*(persnr + i) - 48) * 2 % 10) ) :
                     (checksum += (*(persnr + i) - 48));
            }
        }
    }
    return ((10 - (checksum % 10)) % 10) == control ? 1 : 0;


}




int main(int argc, char*argv[]) {

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

            }
        } while (1);

        return 0;

}




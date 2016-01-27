#include <stdio.h>
#include <string.h>


// Write a program that reads in a string with max 20 characters
// from stdin to a local string variable .

// Copy the string to another string by using :
// a) strcpy -- DONE
// b) A function void copyString(…) not using any libray function.


#define MAX_LENGTH 50

char src[MAX_LENGTH];

int main(int argc, char *argv[])
{

    char destination[MAX_LENGTH];


// A)
    printf("A) (using strcpy) Enter a string with max %d characters: \n", MAX_LENGTH);
    fgets(src, MAX_LENGTH, stdin);
    strcpy(destination, src);
    printf("The output is: %s\n", destination);


// B) TODO
    copyString(src);

   // printf("B) (function) Enter a string with max %d characters: \n", MAX_LENGTH);

    return 0;

}


void copyString(char *src) {
    char cpy[MAX_LENGTH];
    int i;
    while(src[i] != '\0'){

        cpy[i] = src[i];
        i++;
    }

    printf("B) (function)The output is: %s\n", cpy);
}


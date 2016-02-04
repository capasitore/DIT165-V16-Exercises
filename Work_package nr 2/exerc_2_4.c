/* ====================================
File name: exerc_2_4.c (or cpp)
Date: 2016-02-03
Group Number: 33
Members that contributed:
Darja Linkova
Pooriya Balavi
Andreas Aronsson
Demonstration code: 11432
Important , No code no bonus !
====================================== */

#include <stdio.h>
#include <string.h>


void main() {
printf("Enter a word:");
char str[20];
scanf ("%s", str);
char str_rev[20];

int i;
int length = strlen(str);
int temp;
int last_letter = length-1;

if (length == 2){
    if (str[0]==str[1]){
        printf("This is a palindrome");
    }
    else{
        printf("This is not a palindrome");
    }
    
}
if (length!=2){
for  (i=0; i < length-1; i++){
    temp = str[last_letter];
    str_rev[last_letter] = str[i];
    str_rev[i]=temp;
    last_letter--;
    
} 


if(strcmp(str,str_rev) == 0){
   printf("This is a palindrome!");  
}
else {
     printf("This is not a palindrome!");
}




}

}




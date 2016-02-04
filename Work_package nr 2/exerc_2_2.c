/* ====================================
File name: exerc_2_2.c (or cpp)
Date: 2016-02-02
Group Number: 33
Members that contributed:
Darja Linkova
Pooriya Balavi
Andreas Aronsson
Demonstration code: 84182
Important , No code no bonus !
====================================== */

#include <stdio.h>
#include <stdlib.h>
#define MAX 8


void double_array(int *begin);

int main(void) {
	 int arr[MAX]= {10,21,99,65,8,38,90,11};
		  int *ptr = NULL;
		  ptr = arr[MAX];


		  printf("The value of label array ( address) is : %p\n", ptr);
		  printf("the first value in the array is : %d\n", arr[0]);
		  printf("The size of an integer(number of bytes) is: %ld\n", sizeof(int));
		  printf("The size of the whole array is: %ld\n", sizeof(arr));

          //print array
        for (int i = 0; i < MAX; i++)
        {
            printf("%d ", arr[i]);
        }

        double_array(arr);
          return 0;
}

//double values in array
void double_array(int *array){
    printf("\nDoubled Values:\n");
    int *pointer = array;
    for (; pointer != array + MAX; pointer++) {
        *pointer = *pointer * 2;
    printf("%d ", *pointer);
}
        
}

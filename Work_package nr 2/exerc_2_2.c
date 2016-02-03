#include <stdio.h>
#include <stdlib.h>
#define MAX 8

int main(void) {
	 int arr[MAX]= {10,21,99,65,8,38,90,11};
		  int *ptr = NULL;
		  ptr = arr[MAX];


		  printf("The value of label array ( address) is : %p\n", ptr);
		  printf("the first value in the array is : %d\n", arr[0]);
		  printf("The size of an integer(number of bytes) is: %ld\n", sizeof(int));
		  printf("The size of the whole array is: %ld\n", sizeof(arr));


		  return 0;
}

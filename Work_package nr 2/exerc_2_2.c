#include <stdio.h>
#include <stdlib.h>
#define MAX 20

int main(void) {
	 int arr[MAX];
		  int i, *ptr;
		  ptr = arr[MAX];

		  srand(time(NULL));

		  for(i=0; i<=MAX; i++){
			  arr[i] = rand()%100;
		  	}

		  printf("The value of label array ( address) is : %x\n", ptr);
		  printf("the first value in the array is : %d\n", arr[0]);
		  printf("The size of an integer(number of bytes) is: %ld\n", sizeof(int));
		  printf("The size of the whole array is: %ld\n", sizeof(arr));


		  return 0;
}

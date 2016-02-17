/* ====================================
File name: code.c (or cpp)
Date: 2016-02-15
Group Number: 33
Members that contributed:
Darja Linkova
Pooriya Balavi
Andreas Aronsson
Demonstration code: 80931
Important , No code no bonus !
====================================== */

#include <stdio.h>
#include <stdlib.h>


//Pack and unpack variables into a byte. You need to store 4 different values in a byte. The values are:
/*
range	bits	name
0-1		1		engine_on
0-4		3		gear_pos
0-2		2		key_pos
0-1		1		brake1
0-1		1		brake2
*/


int main(int argc, char *argv[]) {
	//if not 5 arguments
	if (argc != 6) {
		printf("Error, you need to enter 5 arguments\n");
		return 1;
	} else{

		// check if number is out of range or negative
		if(atoi(argv[1]) < 0 || atoi(argv[1])  > 1){
			printf("Argument #1 is out of range\n");
			//exit(1);
			return 1;
		}
		if(atoi(argv[2]) < 0 || atoi(argv[2])  > 4){
			printf("Argument #2 is out of range\n");
			//exit(1);
			return 1;
		}
		if(atoi(argv[3]) < 0 || atoi(argv[3])  > 2){
			printf("Argument #3 is out of range\n");
			//exit(1);
			return 1;
		}
		if(atoi(argv[4]) < 0 || atoi(argv[4])  > 1){
			printf("Argument #4 is out of range\n");
			//exit(1);
			return 1;
		}
		if(atoi(argv[5]) < 0 || atoi(argv[5])  > 1){
			printf("Argument #5 is out of range\n");
			//exit(1);
			return 1;
		}
		//end of argument checks

		// shift  bits accordingly
		unsigned char packedValues = atoi(argv[1]) << 7 | atoi(argv[2]) << 4 | atoi(argv[3]) << 2 | atoi(argv[4]) << 1 | atoi(argv[5]);

		 // print binary

		printf("Print as hex: \n%02x\n", packedValues);
		return 0;
	}
}



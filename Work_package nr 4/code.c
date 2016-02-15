/*
 ============================================================================
 Name        : exerc_4_1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

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

	//unsigned char byte;
	if (argc != 6) {
		printf("Error, you need to enter 5 arguments\n");
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

		//main logic
	/*	int a = 1;
		int b = 2;
		int c = 2;
		int d = 1;
		int e = 1;*/

		//int f = atoi(argv[1]);
		//printf("Int f: %i", f);
		//char y= a << 4| b << 3 | c << 2 | d << 1 | e;//merge

		char y= atoi(argv[1]) << 1 | atoi(argv[2]) << 3 | atoi(argv[3]) << 2 | atoi(argv[4]) << 1 | atoi(argv[5]);//merge
		printf("print as decimal: %i, as Hex %02x\n", y, y);

	}
}

/*uint8_t GetByteFromInts(const char eightBools[8])
{
   uint8_t ret = 0;
   for (int i=0; i<8; i++) if (eightBools[i] == true) ret |= (1<<i);
   return ret;
}*/


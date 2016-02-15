/* ====================================
File name: exerc_4_2.c (or cpp)
Date: 2016-02-15
Group Number: 33
Members that contributed:
Darja Linkova
Pooriya Balavi
Andreas Aronsson
Demonstration code:
Important , No code no bonus !
====================================== */

#include <stdio.h>
#include <stdlib.h>


/*
range	bits	name
0-1		1		engine_on
0-4		3		gear_pos
0-2		2		key_pos
0-1		1		brake1
0-1		1		brake2
*/

typedef struct {
	unsigned char engine_on : 1;
	unsigned char gear_pos 	: 3;
	unsigned char key_pos 	: 2;
	unsigned char brake1	: 1;
	unsigned char brake2	: 1;
}unpack;


int main(int argc, char *argv[]) {
	if (argc != 2) {
			printf("Error, you need to enter 1 arguments\n");
			return 1;
		} else{

			//base 16
			unsigned char input = strtol(argv[1], NULL, 16);
			unpack up;

			up.engine_on  = input >> 7;
			up.gear_pos = input>> 4;
			up.key_pos = input >> 2;
			up.brake1 = input >> 1;
			up.brake2 = input;

			printf("Name\t\t Value\n");
			printf("------------------------\n");
			printf("engine_on\t %d\n", up.engine_on);
			printf("gear_pos\t %d\n", up.gear_pos);
			printf("key_pos\t\t %d\n", up.key_pos);
			printf("brake1\t\t %d\n", up.brake1);
			printf("brake2\t\t %d\n", up.brake2);


			return 0;
		}

}

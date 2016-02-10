#include <stdio.h>
#include <stdlib.h>
#include <string.h>


enum DIRECTION {N,O,S,W};


void move(int *xpos, int *ypos, enum DIRECTION *dir);
void turn(enum DIRECTION *dir);


typedef struct {
        int xpos;
        int ypos;
        enum DIRECTION dir;
} ROBOT;



int main ()
{
	int exit = 0;

	do{
	ROBOT robot;

	char inputMove[50];
	int i = 0;

	robot.dir = N;

	printf("Give the robot's starting position: \n");
	scanf("%d %d", &robot.xpos, &robot.ypos);

	printf("Enter inputMoves for the robot (m for move and t for turn):\n");
	scanf("%s", inputMove);

	int length = strlen(inputMove);

	while (i < length) {

		if(inputMove[i] == 'm') {
			move(&robot.xpos, &robot.ypos, &robot.dir);
		}
		if(inputMove[i] == 'M') {
			move(&robot.xpos, &robot.ypos, &robot.dir);
		}
		if(inputMove[i] == 't') {
			turn(&robot.dir);
		}
		if(inputMove[i] == 'T') {
			turn(&robot.dir);
		}
		i++;

	}
	printf("The new position is: %d, %d\n", robot.xpos, robot.ypos);

	}
	while(exit != 1);

    return(0);
}

void move(int *xpos, int *ypos, enum DIRECTION *dir) {

	if(*dir == N) {
		*xpos += 1;
	}
	if(*dir == O) {
		*ypos += 1;
		}
	if(*dir == S) {
		*xpos -= 1;
		}
	if(*dir == W) {
		*ypos -= 1;
		}

	return;
}

void turn(enum DIRECTION *dir) {

	if (*dir == N) {
		*dir = O;
		return;
	}
	if (*dir == O) {
		*dir = S;
		return;
	}
	if (*dir == S) {
		*dir = W;
		return;
	}
	if (*dir == W) {
		*dir = N;
		return;
	}
}


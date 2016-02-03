/* ====================================
File name: exerc_2_5.c (or cpp)
Date: 2016-01-27
Group Number: 33
Members that contributed:
Darja Linkova
Pooria Balavi
Andreas Aronsson
Demonstration code: 88147
Important , No code no bonus !
====================================== */

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>


#define MAX_COINS 13

const int HUMAN = 0;
const int COMPUTER = 1;

/* ------------- IO --------------- */

/*
 * human_choice
 * Get human choce as an int from stdin.
 * Clears stdin.
 * in: pile
 * out: int-value in range 1-3 (and also less than pile)
 */
int human_choice(int pile);

/*
 * write_winner
 * Write winner as a string on stdout.
 * in: Values HUMAN or COMPUTER.
 * out:
 */
void write_winner( int player );

/*
 * play_again
 * Ask human if he/she wants to play
 * another round. If 'n' or 'N' selected
 * (single char) return false else true.
 * Clears stdin.
 * in:
 * out: true or false
 */
int play_again();

/* ---------------- Logic ----------------*/

/*
 * computer_choice
 * Get computers choice (including some AI,
 * if 4 coins or less left, function makes a
 * smart choice else random).
 * in: pile
 * out: int-value in range 1-3 (and also less than pile)
 */
int computer_choice(int pile);

/*
 * toggle
 * Switches player, if HUMAN in COMPUTER out
 * etc.
 * in:  actual player
 * out: next player
 */
int toggle( int player );

/* --------------------- Utilities -------------*/
void clear_stdin();

/***************************************************
 *
 *    MAIN
 *
 ***************************************************/
int main()
{
  int pile,			/* This is how many coins we have */
    player,			/* Who is playing? */
    n_coins;			/* Number of coins taken */

  srand( time(0) );		/* Setup random */

  printf("Welcome to the NIM game by Pooria, Andreas and Darja! \n");


  pile = MAX_COINS;		/* Set start values (= init) */
  player = HUMAN;

  /*
   *  Program main loop
   */
  while( true ) {

    printf("there are %d coins in the pile.\n", pile );

    if( player == HUMAN ){
      n_coins = human_choice(pile);
    }else{
      n_coins = computer_choice(pile);
      printf("- the computer chooses %d, what your choice? \n", n_coins);
    }
    pile -= n_coins;
    player = toggle( player );

    if( pile <= 1 ){
      break;
    }
  }
  /*
   * end main loop
   */

  write_winner( player );
if(play_again() == true){
	main();
}else
		  printf("End of the game\n");

		  return 0;

}

/******************************************************
 *
 *  DEFINITIONS
 *
 ******************************************************/


void clear_stdin()
{
  while( getchar() != '\n' ){
    ;
  }
}

int human_choice(int pile){
	int coinChoice = 0;
	printf("please enter a number between 1 to 3:\n");
	scanf("%d", &coinChoice);
	clear_stdin();
	if((coinChoice >= 1 && coinChoice <= 3) && (coinChoice < pile)){
		return coinChoice;
	}else
		printf("incorrect input, please try again! \n");
	human_choice(pile);
return 0;
}

int computer_choice(int pile){
	int coinChoice;
	if(pile <= 4){
		if(pile == 4){
			coinChoice = 3;
		}
		if(pile == 3){
			coinChoice = 2;
		}
		if(pile == 2){
			coinChoice = 1;
		}
	}else{
		coinChoice = rand() %3 +1;}
	return coinChoice;
}


void write_winner(int player )
{
if (player == 0){
	printf("The computer defeats you\n");
}else {
	printf("You win!\n");
}
}

int play_again(){
	char playAgain;

		printf("Would you like to play again? say n or y \n");
		scanf("%c", &playAgain);
		clear_stdin();
		if(playAgain == 'y'){
			return true;
		}else if(playAgain == 'n'){
			return false;
	}
		else
			printf("incorrect input");
		play_again();
		return 0;
}

int toggle( int player ){
int who;
if (player == 0){
	who = 1;
}else {
	who = 0;
}
return who;
}

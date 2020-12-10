/* PROGRAM :  dice.c
    AUTHOR :  Sifat Jamaly, Nathan Fan
  DUE DATE :  December 05, 2020
     TOPIC :  Dice Game Implementation
   PURPOSE :  CST8234 - C Language - Assignment2 
*/

/**************************************************************************/
/* Declare include files
 **************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/**************************************************************************/
/* Macros
 **************************************************************************/
#define WON 0
#define LOSE 1


/**************************************************************************/
/* Function prototypes
 **************************************************************************/
int rollDice (); 
int playGame();


/**************************************************************************/
/* Global variables
 **************************************************************************/
int total, pointMatch, rollNum, win, lose;
char decide;


/**************************************************************************
 * Driver
 **************************************************************************/

int main () {

	printf("\n                     ROLL THE DICE [ENTER]\n\n");
	playGame();
	char decide;
	rollNum = 0;
	
	do{		
		/*prompt user to replay or quit*/
		printf("\nContinue? (y/n)\n");
        getchar();
        scanf("%c", &decide);
	 }while (decide != 'n' && decide != 'y');

	while (decide != 'n')
	{
		if (decide == 'y')
		{
			printf("\n                     ROLL THE DICE [ENTER]\n\n");
			playGame();
		}
		printf("\nAnother game? (y/n)\n");

		scanf("  %c", &decide);
	}



	/*Exiting message*/
	printf("\nThank-you for playing!\n");
	printf("You won %1d games and lost %d games!\n", win, lose);


	/*custom statement if you're a loser*/
	if (win > lose) {
		printf("What a winner!\n\n");
	} else {
		printf("Better luck next time!\n\n");
		}
	return 0;
}


/**************************************************************************
 * FUNCTION : rollDice
 *     TASK : to randomly generate a number between 1-6. 
 **************************************************************************/
int rollDice () {
		
	int dice = (1 + rand() % 6);
	return dice;	
}
            
            
/**************************************************************************
 * FUNCTION : playGame
 *     TASK : play dice 
 **************************************************************************/
int playGame() {
	
	int dice1, dice2, sum, pointMatch, stopPlaying;

	/*seeding random number with time so its different each time*/
	srand(time(NULL));
	
	
	/*roll the two dice and add the results*/ 
	dice1 = rollDice();
	dice2 = rollDice();
	sum = dice1 + dice2;
	pointMatch = sum;

	/*print statement with format*/
	printf("------------------------------------------------------------------------\n");
	printf(" ROLL NUM     DICE #1     DICE #2     TOTAL ROLL     POINT MATCH\n");
	printf("------------------------------------------------------------------------\n");


	/*printing the numbers so far*/
	printf("%9d %11d %11d              %d              %d\n",   	
	rollNum, dice1, dice2, sum, pointMatch);


	/*win if first roll is a 7 or 11*/
	if (sum == 7 || sum == 11) {
		printf("Congratulations you roll %10d. and WON at your first try" , sum);
		win++;			
		return WON;
			
	
	/*game is lost if roll is 2, 3, or 12*/			
   	} else if (sum == 2 || sum == 3 || sum == 12) {
		printf("Sorry, you roll %10d and you lose!!!" , sum);
		lose++;				
		return LOSE;
				
				
	} else {
		/*if neither top conditions activate*/
		/*the pointMatch is used*/	
		do {
			
			dice1 = rollDice();
			dice2 = rollDice();
			sum = dice1 + dice2;
			rollNum++;


			printf("        %d           %d           %d              %d              %d				\n", rollNum, dice1, dice2, sum, pointMatch);
		
			if (sum == 2 || sum == 3 || sum == 12) {
				printf("Sorry, you roll %10d and you lose!!!" , sum);
				lose++;				
				return LOSE;
		
			} else if (sum == pointMatch) {
				printf("Congratulations! You have won with a roll of %3d." ,							sum);
				win++;						
				return WON;	
						

			}
		
		/*keep playing until win or lose condition*/				
		} while (stopPlaying != WON || stopPlaying != LOSE);			
				
		return;			
	}		
}

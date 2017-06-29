// BubbleShip.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "BubbleShip.h"
#include <Windows.h>
#include <stdio.h>
#include <string.h>
#define NUM_SHIPS 4

int main()
{
	char* playerOneField;
	char* playerTwoField;
	int playerOneNumber = 1;
	int playerTwoNumber = 2;
	int attackResults = 0;
	int coord = 0;

	playerOneField = BuildField();
	playerTwoField = BuildField();

	PlaceShips(NUM_SHIPS, playerOneNumber, playerOneField);
	PlaceShips(NUM_SHIPS, playerTwoNumber, playerTwoField);



	//while (1) //Loops forever
	{

		 // Player One's turn
		PromptPlayerForCoords(playerOneNumber, &coord);
		attackResults = LaunchAttackAgainstPlayer(playerOneNumber, playerTwoNumber, playerTwoField, coord);

			printf("Player One sunk %d ships!", attackResults);
			if (attackResults == 9999)
			{
				printf("Player One Wins!");
				return 0; //Exit main function
			}


			//Player Two's turn
			PromptPlayerForCoords(playerTwoNumber, &coord);
			attackResults = LaunchAttackAgainstPlayer(playerTwoNumber, playerOneNumber, playerOneField, coord);

			printf("Player Two sunk %d ships", attackResults);
			if (attackResults == 9999)
			{
				printf("Player Two Wins!");
				return 0; //Exit main function
			}
		}

	    return -1; //Should never get here;
	}


char* BuildField()

{
	int index;

	char* spaces;
	spaces = (char*)malloc(21);
	for (index = 0; index < 20; index = index + 1) {
		spaces[index] = 'o';


	}
		

	spaces[index] = 0; 
	//printf("%s", spaces);
	return spaces;
}

int PromptPlayerForCoords(int playerNumber, int* xpos)
{


	int coord = 0;
	//printf("player %d enter coords: ", playerNumber);
	scanf("%i", &coord);
	printf("%i", coord);
	//*xpos = coord;
	if (coord < 20) {
		return 0;
	}
	else {
		return -1;
	}
}

void PlaceShips(int numShips, int playerNumber, char* field)
{

	int shipXpos;
	//int shipIndex;
	int shipCounter = 1;
	while (shipCounter < 5) { //made a variable to be the counter in the loop. Once the variable equals 5 or more the loop stops
		printf("player %d enter ship %d location: ", playerNumber, shipCounter);
		PromptPlayerForCoords(playerNumber, &shipXpos); //calls promptplayerforcoords function
		shipCounter = shipCounter + 1; //adds 1 to the counter each iteration of the loop
		*field; //I dereferenced the pointer so I have access to the character array 
		field[shipXpos] = 's'; //shipXpos holds the location the user entered. I set shipXpos as the index of field and set it equal to s, so it puts an s anywhere there is a ship

	}


	//printf("%s", field);

	return;

}
int LaunchAttackAgainstPlayer(int playerNumberOfAttacker, int playerNumberOfDefender, char* fieldOfDefender, int xpos)

{
	

	
	int sunkShip=0;
	int ret;
	int index;

	char* spaces;
	spaces = (char*)malloc(21);
	for (index = 0; index < 20; index = index + 1) {
		spaces[index] = 'o';
		spaces[index] = 0;
	}

	*fieldOfDefender;
	
	if (fieldOfDefender[xpos] == 's') {
		fieldOfDefender[xpos] = 'o';

		printf("%d launch attack against %d", playerNumberOfAttacker, playerNumberOfDefender);
		scanf("%i", xpos);
		sunkShip = sunkShip + 1;

	}
		if (fieldOfDefender[xpos] == 's') {
			fieldOfDefender[xpos] = 'o';
		}


		ret = strcmp(fieldOfDefender, spaces);
		if (ret == 0) {
			return 9999;
		}
		else if (ret != 0) {
			return sunkShip;
		}

		else
		{
			return -1;
		}

	}
			
			//*fieldOfDefender;

	

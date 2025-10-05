
//Zybooks 5.13
#ifndef FUNCTIONS_H 
#define FUNCTIONS_H

#define DECKSIZE 84
#define HANDSIZE 7

typedef struct card_struct{
     int value;
     char action[15];
} card;

//**************SETUP FUNCTIONS******************

void ShuffleCards(card x[]); //Shuffles the deck of cards
void SortHand(card x[][2]);  //Sorts the hand of the player at the beginning of the game
void StartingDraw(card player[][2], card cardDeck[], int *draw); //Gives seven cards to a player
void RegularDrawStart(card cardDeck[], card player[][2], card upPile[], int *draw, int *upCount); //Draws a card for the "first" round of playing
void SpecialDraw(card player[][2], card cardDeck[], card discard[], card upPile[], int *draw, int *upCount, int *discardCount); //Special Drawing for the "first" round of playing


//**************DESIGN PRINTING FUNCTIONS********

void PrintCardSpecial(card cardDeck[], int *deckCount); //Prints out the drawn cards for the pre 1st round
void PrintCard(card specificCard); //Prints Card
void PrintHand(card playerHand[][2]); //Prints the hand of the current player
void PrintFaceUp(card upPile[], int *upCount); //Prints out Face Up Cards for abilites


//*************ACTION/DRAW FUNCTIONS*******************

bool WinCheck(card x[][2]);  //Checks if a player's hand wins the game
int LongestTrain(card player[][2]); //Checks who has the longest train in order (starting from 1st train) if draw pile = 0
void FaceUpCheck(card upPile[], card discard[], int *discardCount, int *upCount); //Checks if two cards in the face up pile are the same

void RegularDraw(card cardDeck[], card player[][2], card upPile[], int *draw, int *upCount); //Draws a card 

//Power Up Functions
void ShiftingPower(card player[][2], int typeShift); //Shifts a player's hand dependent on which type
void LockingPower(card player[][2], card *lock); //Locking Power Up
void RemovePower(card player1[][2], card player2[][2], card cardDeck[], card upPile[], int typeRemove, int *draw); //Remove Power Up (will iterate through each player)

#endif
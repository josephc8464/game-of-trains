#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>

#include "functions.h"

card nullCard1 = {0, "NULL\0"}; //To replace drawn cards

int main()
{
    int discardPileCount = 0; //Counts the current discard pile
    int faceUpCount = 0; //Counts the number of face up Cards
    int drawPileCount = 0; //Counts the number in the draw pile
    
    //Something to note is that all these variables should always add up to 84 cards (83 in index)
    
    card discardPile[DECKSIZE]; //Is the discard pile
    card deck[DECKSIZE]; //Deck ARRAY is the deck of cards used
    card faceUp[9]; //Is the cards that are avaliable to use for power ups (should only be 8 at most since we are discarding duplicates)
    card player1[HANDSIZE][2], player2[HANDSIZE][2], temp; //Defining vars for players

    int choice;
    
    char userDeck[50] = "";
    char userInput = 'y';
    
    for(int i=0; i<9; i++) {
        faceUp[i] = nullCard1;
    }
    
    printf("Do you want to use the standard deck? (y/n): ");  //Asks user if they want to use standard deck
    scanf("%c", &userInput);
    
    while(userInput != 'y' && userInput != 'n') {     //Keeps asking if valid character is not chosen
        
        printf("Please enter a valid letter\n\nDo you want to use the standard deck? (y/n): ");
        scanf("%*c%c", &userInput);
        
    }
    
    if(userInput == 'n') {   //Asks for name of file if using a custom deck
        printf("Please enter name of deck file: ");
        
        scanf("%s", &*userDeck);
        
        if(userDeck[strlen(userDeck)-1] == '\n') {
           userDeck[strlen(userDeck)-1] = '\0';
        }    
        
    }
    else {   //Otherwise inputs the standard deck
        strcpy(userDeck, "sampledeck.txt");
    }
    
    
    FILE *deckinput = fopen(userDeck, "r");
    
    if(deckinput == NULL) {                   //If the file is not found print this
        printf("File not found\n");
        return -1;
    }
    
    for(int i=0;i<DECKSIZE; i++) {                                          //SCANS IN DECK
        
        fscanf(deckinput, "%d", &deck[i].value);
        fgets(deck[i].action, 15, deckinput);
        if (deck[i].action[strlen(deck[i].action)-1] == '\n') {
            deck[i].action[strlen(deck[i].action)-1] = '\0';
        }
        
    }

    ShuffleCards(deck);
    
    StartingDraw(player1,deck, &drawPileCount);
    StartingDraw(player2,deck, &drawPileCount);
    
    SortHand(player1);
    SortHand(player2);
    
    printf("\nWELCOME TO GAME OF TRAINS\n");
    
    //************************************PRE-FIRST ROUND***********************************************
    
    printf("\n\n********************* PLAYER1 *********************\n\n");
    RegularDrawStart(deck, player1, faceUp, &drawPileCount, &faceUpCount);
    
    printf("\n\n********************* PLAYER2 *********************\n\n");
    SpecialDraw(player2, deck, discardPile, faceUp, &drawPileCount, &faceUpCount, &discardPileCount);
    
    
    //************************************ACTUAL GAMEPLAY CODE HERE*************************************
    
    
    while( WinCheck(player1) != true || WinCheck(player2) != true || deck[83].action != "NULL") 
    {
        printf("\n\n********************* PLAYER1 *********************\n\n");
        
        FaceUpCheck(faceUp, discardPile, &discardPileCount, &faceUpCount);
        
        printf("\nCurrent Hand:\n");
        PrintHand(player1);
        
        if(strcmp(faceUp[0].action, nullCard1.action) == 0) 
        {
            printf("\n1: Draw a card    There are no cards in the Face Up Pile\n");
            scanf("%d", &choice);
            
            if(choice != 1) 
            {
                printf("You must draw a card, you do not have a choice\n");
            }
        
            RegularDraw(deck, player1, faceUp, &drawPileCount, &faceUpCount);
        }
        else 
        {
            printf("\nAction Cards:\n");
            PrintFaceUp(faceUp, &faceUpCount);
            printf("\n1: Draw a card    2:Pick an Action Card\n");
            scanf("%d", &choice);
            
            while(choice < 1 || choice > 2) 
            {
                printf("Please select a valid option: "); 
                scanf("%d", &choice);
                scanf("%d", &choice);
            }
            
            if(choice == 1) 
            {
                RegularDraw(deck, player1, faceUp, &drawPileCount, &faceUpCount);
            }
            
            else if(choice == 2) 
            {
                printf("Please choose one of the avaliable action cards(1-%d)\n", faceUpCount);
                scanf("%d", &choice);
                
                while(choice < 1 || choice > faceUpCount) 
                {
                    printf("Please select a valid option: "); 
                    scanf("%d", &choice);
                }
                
                if(strcmp(faceUp[choice-1].action, "shift2Right") == 0) 
                {
                    printf("Shift 2 Right");
                }
                
            }
        }
        
        printf("\n\n********************* PLAYER2 *********************\n\n");
        
        FaceUpCheck(faceUp, discardPile, &discardPileCount, &faceUpCount);
        
        printf("\nCurrent Hand:\n");
        PrintHand(player1);
        
        if(strcmp(faceUp[0].action, nullCard1.action) == 0) 
        {
            printf("\n1: Draw a card    There are no cards in the Face Up Pile\n");
            scanf("%d", &choice);
            
            if(choice != 1) 
            {
                printf("You must draw a card, you do not have a choice\n");
            }
            
            RegularDraw(deck, player1, faceUp, &drawPileCount, &faceUpCount);
        }
        else 
        {
            printf("\nAction Cards:\n");
            PrintFaceUp(faceUp, &faceUpCount);
            printf("\n1: Draw a card    2:Pick an Action Card\n");
            scanf("%d", &choice);
            
            while(choice < 1 || choice > 2) 
            {
                printf("Please select a valid option: "); 
                scanf("%d", &choice);
                scanf("%d", &choice);
            }
            
            if(choice == 1) 
            {
                RegularDraw(deck, player1, faceUp, &drawPileCount, &faceUpCount);
            }
            
            else if(choice == 2) 
            {
                printf("Please choose one of the avaliable action cards(1-%d)\n", faceUpCount);
                scanf("%d", &choice);
                
                while(choice < 1 || choice > faceUpCount) 
                {
                    printf("Please select a valid option: "); 
                    scanf("%d", &choice);
                }
                
                if(strcmp(faceUp[choice-1].action, "shift2Right") == 0) 
                {
                    printf("Shift 2 Right");
                }
                
            }
        }
        
    }
    
    return 0;
   
}


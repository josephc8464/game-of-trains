#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

#include "functions.h"

card nullCard = {0, "NULL\0"}; //To replace drawn cards

void ShuffleCards(card x[]) { //Random Numbers
    
    srand(time(NULL));
    
    for(int i=0; i < DECKSIZE; i++) {
        int y = rand() % DECKSIZE;
        card tempVal = x[i];
        x[i] = x[y];
        x[y] = tempVal;
    }
    
}

void SortHand(card x[][2]) { //Selection Sort
    
    int i;
    int j;
    int indexBiggest;
    card temp;      
   
    for (i = 0; i < HANDSIZE - 1; ++i) {
      
        indexBiggest = i;
        for (j = i + 1; j < HANDSIZE; ++j) {
         
        if ( x[j][0].value > x[indexBiggest][0].value ) {
            indexBiggest = j;
            }
        }
        
        temp = x[i][0];
        x[i][0] = x[indexBiggest][0];
        x[indexBiggest][0] = temp;
        
    }
    
}

void StartingDraw(card player[][2], card cardDeck[], int *draw) {
    
    for(int i=0;i<7;i++) {
        
        player[i][0] = cardDeck[i+*draw];
        
        cardDeck[i+*draw] = nullCard;
        
    }
    
    *draw += 7;
    
}

void SpecialDraw(card player[][2], card cardDeck[], card discard[], card upPile[], int *draw, int *upCount, int *discardCount) {
    
    int choice=0;
    card tempVal;
    
    printf("\nCurrent Hand:\n");
    PrintHand(player);
    
    printf("\nDrawn Cards\n");
    PrintCardSpecial(cardDeck, &*draw);
    
    printf("Choose a card that'll replace one in your hand (1-2)\n");
    
    scanf("%d", &choice);
    while(choice < 1 || choice > 2) {
        printf("Choose a valid card that'll replace one in your hand. (1-2)\n");
        scanf("%d", &choice);
    }
    
    if(choice == 1) {
        tempVal = cardDeck[*draw];
        discard[*discardCount] = cardDeck[*draw+1];
        cardDeck[*draw+1] = nullCard;
    }
    else if(choice == 2) {
        tempVal = cardDeck[*draw+1];
        discard[*discardCount] = cardDeck[*draw];
        cardDeck[*draw] = nullCard;
    }
    ++*discardCount;
    *draw += 2;
    
    printf("Choose a card from your hand to replace. (1-7)\n");
    scanf("%d", &choice);
    while(choice < 1 || choice > 7) {
        printf("Choose a valid card from your hand to replace. (1-7)\n");
        scanf("%d", &choice);
    }
    
    switch(choice) {
        case 1:
        upPile[*upCount] = player[0][0];
        player[0][0] = tempVal;
        break;
        
        case 2:
        upPile[*upCount] = player[1][0];
        player[1][0] = tempVal;
        break;
        
        case 3:
        upPile[*upCount] = player[2][0];
        player[2][0] = tempVal;
        break;
        
        case 4:
        upPile[*upCount] = player[3][0];
        player[3][0] = tempVal;
        break;
        
        case 5:
        upPile[*upCount] = player[4][0];
        player[4][0] = tempVal;
        break;
        
        case 6:
        upPile[*upCount] = player[5][0];
        player[5][0] = tempVal;
        break;
        
        case 7:
        upPile[*upCount] = player[6][0];
        player[6][0] = tempVal;
        break;
    }
    ++*upCount;
    
    printf("\n\nNew Hand:");
    PrintHand(player);
}

void RegularDrawStart(card cardDeck[], card player[][2], card upPile[], int *draw, int *upCount) {
    
    int choice=0;
    card tempVal;
    
    printf("\nCurrent Hand:\n");
    PrintHand(player);
    printf("\nDrawn Card\n");
    PrintCard(cardDeck[*draw]);
    
    printf("Choose a card from your hand to replace. (1-7)\n");
    
    scanf("%d", &choice);
    while(choice < 1 || choice > 7) {
        printf("Choose a valid card from your hand to replace. (1-7)\n");
        scanf("%d", &choice);
    }
    
    tempVal = cardDeck[*draw];
    switch(choice) {
        case 1:
        upPile[*upCount] = player[0][0];
        player[0][0] = tempVal;
        break;
        
        case 2:
        upPile[*upCount] = player[1][0];
        player[1][0] = tempVal;
        break;
        
        case 3:
        upPile[*upCount] = player[2][0];
        player[2][0] = tempVal;
        break;
        
        case 4:
        upPile[*upCount] = player[3][0];
        player[3][0] = tempVal;
        break;
        
        case 5:
        upPile[*upCount] = player[4][0];
        player[4][0] = tempVal;
        break;
        
        case 6:
        upPile[*upCount] = player[5][0];
        player[5][0] = tempVal;
        break;
        
        case 7:
        upPile[*upCount] = player[6][0];
        player[6][0] = tempVal;
        break;
    }
    
    ++*upCount;
    ++*draw;
    
    printf("\n\nNew Hand:");
    PrintHand(player);
}

void PrintCardSpecial(card cardDeck[], int *deckCount) {
    
    printf("\n       1          "); printf("       2         \n");
    printf("    *******       "); printf("    *******       \n");
    printf("    *     *       "); printf("    *     *       \n");
    printf("    * %-2d  *       ", cardDeck[*deckCount].value);  printf("    * %-2d  *       \n", cardDeck[*deckCount+1].value);
    printf("    *     *       "); printf("    *     *       \n");
    printf("    *******       "); printf("    *******       \n");
    printf("   %-15s", cardDeck[*deckCount].action); printf("   %-15s\n\n", cardDeck[*deckCount+1].action);
    
}

void PrintCard(card specificCard) {
    printf("\n    *******       \n");
    printf("    *     *       \n");
    printf("    * %-2d  *       \n", specificCard.value);
    printf("    *     *       \n");
    printf("    *******       \n");
    printf("   %-15s\n\n", specificCard.action);
}

void PrintHand(card playerHand[][2]) {
    
    for(int i=0; i<7; i++) {
        
        if(strcmp(playerHand[i][1].action, "protect") == 0) {
            printf("    LOCKED        ");
        }
        else {
            printf("                  ");
        }
    }
    
    printf("\n");
    for(int i=0; i<7; i++) {
       printf("       %d          ", i+1);
    }
    
    printf("\n");
    
    for(int i=0; i<7; i++) {
       printf("    *******       ");
    }
    printf("\n");
    
    for(int i=0; i<7; i++) { printf("    *     *       ");} printf("\n");
    for(int i=0; i<7; i++) { printf("    * %-2d  *       ", playerHand[i][0].value); } printf("\n");
    for(int i=0; i<7; i++) { printf("    *     *       "); } printf("\n");
    
    for(int i=0; i<7; i++) {
       printf("    *******       ");
    }
    printf("\n");
    
    for(int i=0; i<7; i++) {
        printf("   %-15s", playerHand[i][0].action);
    }
    printf("\n");
}

void PrintFaceUp(card upPile[], int *upCount) {
    
    
    printf("\n");
    for(int i=0; i<*upCount; i++) {
       printf("       %d          ", i+1);
    }
    
    printf("\n");
    
    for(int i=0; i<*upCount; i++) {
       printf("    *******       ");
    }
    printf("\n");
    
    for(int i=0; i<*upCount; i++) { printf("    *     *       ");} printf("\n");
    for(int i=0; i<*upCount; i++) { printf("    * %-2d  *       ", upPile[i].value); } printf("\n");
    for(int i=0; i<*upCount; i++) { printf("    *     *       "); } printf("\n");
    
    for(int i=0; i<*upCount; i++) {
       printf("    *******       ");
    }
    printf("\n");
    
    for(int i=0; i<*upCount; i++) {
        printf("   %-15s", upPile[i].action);
    }
    printf("\n");
}

bool WinCheck(card x[][2]) {
    
    for(int i=0; i<HANDSIZE; i++) {
        if(x[i][0].value > x[i+1][0].value && i+1 != HANDSIZE) {
            return false;
        }
    }
    return true;
}

int LongestTrain(card player[][2]);

void FaceUpCheck(card upPile[], card discard[], int *discardCount, int *upCount) {
        
    int i;
    int j;
    int indexBiggest;
    card tempVal = nullCard;
    
    for(i=0; i<9; i++) {
        for(j=0; j<9; j++) {
            if(strcmp(upPile[i].action, upPile[j].action) == 0 && i != j && strcmp(upPile[i].action, nullCard.action) != 0 && strcmp(upPile[j].action, nullCard.action) != 0) {
    
                discard[*discardCount] = upPile[i];
                discard[*discardCount+1] = upPile[j];
                upPile[i] = nullCard;
                upPile[j] = nullCard;
                
                *discardCount += 2;
                *upCount -= 2;
            }   
        
        }
    }
    
    //Selection Sort, to move null cards to the end of the array
   
    for (i = 0; i < 9; ++i) {
      
      // Find index of smallest remaining element
      indexBiggest = i;
      for (j = i + 1; j < 8; ++j) {
         
         if (upPile[j].value > upPile[indexBiggest].value ) {
            indexBiggest = j;
         }
      }
      
      // Swap numbers[i] and numbers[indexSmallest]
      tempVal = upPile[i];
      upPile[i] = upPile[indexBiggest];
      upPile[indexBiggest] = tempVal;
   }
   
}

void RegularDraw(card cardDeck[], card player[][2], card upPile[], int *draw, int *upCount) {
    
    int choice=0;
    card tempVal;
    
    printf("\nDrawn Card\n");
    PrintCard(cardDeck[*draw]);
    
    printf("Choose a card from your hand to replace. (1-7)\n");
    
    scanf("%d", &choice);
    while(choice < 1 || choice > 7) {
        printf("Choose a valid card from your hand to replace. (1-7)\n");
        scanf("%d", &choice);
    }
    
    tempVal = cardDeck[*draw];
    switch(choice) {
        case 1:
        upPile[*upCount] = player[0][0];
        player[0][0] = tempVal;
        break;
        
        case 2:
        upPile[*upCount] = player[1][0];
        player[1][0] = tempVal;
        break;
        
        case 3:
        upPile[*upCount] = player[2][0];
        player[2][0] = tempVal;
        break;
        
        case 4:
        upPile[*upCount] = player[3][0];
        player[3][0] = tempVal;
        break;
        
        case 5:
        upPile[*upCount] = player[4][0];
        player[4][0] = tempVal;
        break;
        
        case 6:
        upPile[*upCount] = player[5][0];
        player[5][0] = tempVal;
        break;
        
        case 7:
        upPile[*upCount] = player[6][0];
        player[6][0] = tempVal;
        break;
    }
    
    ++*upCount;
    ++*draw;
    
    printf("\n\nNew Hand:");
    PrintHand(player);
}

void ShiftingPower(card player[][2], int typeShift) {
    
    int choice = 0;
    
    if(typeShift == 1) {
        PrintHand(player);
        printf("Please select a card to shift two to the right\n");
        scanf("%d", &choice);
        
        while(choice < 1 || choice > 5) {
            printf("Please select a valid card to shift two to the right\n");
            scanf("%d", &choice);
        }
        for(int i=0; i<5; i++) {
            player[i][1] = nullCard;
        }
        
    }
    else if(typeShift == 2) {
        
    }
    else if(typeShift == 3) {
        
    }
    else if(typeShift == 4) {
        
    }
    
}
void LockingPower(card player[][2], card *lock) {
    
}
void RemovePower(card player1[][2], card player2[][2], card cardDeck[], card discard[], int typeRemove, int *draw) {
    
    if(typeRemove == 5) {
        
    }
    else if(typeRemove == 6) {
        
    }
    else if(typeRemove == 7) {
        
    }
    
}


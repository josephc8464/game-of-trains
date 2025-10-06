# game-of-trains
This project replicates the card game, Game Of Trains in the language C.
Due to saving errors, some of the files are missing updated code. 

# main
The code accepts an optional deck that follows the same convention as the supplied sampledeck.txt (card number, card power).
If you do not use a self created deck, just simply put 'y' to use the standard deck.
The game should execute! Some features have not been fully completed (such as remove power up and others). But
the main swap and other card functions are functional from the test cases I have used. 
One big bug that needs to be fixed is detecting a char character (should be a simple fix but as stated before the file was not correctly saved and 
lost some of the checks).

# functions.h / functions.c
functions.h contains all the declarations and function expectations. The definitions are located in the bigger file 
functions.c. The functions contain all the printing, and swapping / power up functions, to learn more about what they do
I'd reccommend looking at the game of trains instruction manual.
As a final note I plan on dividing the files into smaller chunks to help with performance and future updates. 

# What is game of trains?
Game of trains is a card game in which a player gets an intial descending order of cards and uses their turns to move
their cards in ascending order the fastest. There is a power up pile and a draw pile from which the player can take. 
In each turn the players can either choose to use a power up from a discarded card or use the number from a drawn card.
To learn more about the game, seach Game Of Trains on google.

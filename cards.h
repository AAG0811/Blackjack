/*
File to store and display card sprites for blackjack game 

card shape
/-----\
|     |
|     |
|     |
\-----/

card stored in array of lines so it can easily be drawn multiple times

card values:
    A, 2, 3, 4, 5, 6, 7, 8, 9, 10, J, Q, K

store cards with padding after 'face' of the card and have its associated numerical value

deck stores each unique card 4 times
cards are removed from the deck based on a random index; that index is then swapped with the last card in the deck.
the deck is then shurnk by one, effectively removing the selected card from the deck.

the deck doesn't need to be randomised due to the card being chosen from a random spot within the deck.
while not being the same as a real deck of cards it simulates the deck being shuffled without the time it takes to rearrange the array several times.
therefore the actual order of the deck is the order cards are randomly pulled from it and not as they are stored in the array.
*/
#ifndef CARDS_H
#define CARDS_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// template for displaying playing cards in the terminal
// stored as a list of strings for each horizontal line in the glyph
// const char* cardBase[] = {
//     "/-----\\",
//     "|%s   |",
//     "|     |",
//     "|   %s|",
//     "\\-----/"
// };
// \033[47m\033[30m - white bg black text
extern const char* cardBase[];
extern const int linesInCard;
extern const char* faces[13];
extern const int values[13];

// basic key/value struct to store card info
typedef struct {
    char face[3]; // the face of the card e.g. queen, king, '2 ' | single digit faces will have a space after for padding
    int value; // how many points the card is worth
} Card;

// vector to store cards 
typedef struct {
    Card *cards; // dynamic array to store cards
    int cardsInHand; // how many cards are in the array (hand)
} Hand;

// Deck has same data structure as Hand but has different name to avoid confusion
typedef Hand Deck;

// function to create a logical deck of cards 
void createDeck(Deck* dest);

// remove a random card from the deck of cards
void popFromDeck(Card *dest, Deck *deck);

// draws random card from deck and assigns it to a players hand
void drawCard(Hand *hand, Deck *deck);

// displays all the cards in a players hand
void displayHand(Hand *hand);

// free memory used
void freeHand(Hand *hand);
#endif
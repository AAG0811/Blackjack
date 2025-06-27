/*
Blackjack game created by aidan grier (June 2025)

each round player will be randomly given two cards from a deck of cards

a deck will have the same values as a real deck of cards

each player will take turns trying to reach a score of 21 

could add score in form of tokens 
 */
// #include "cards.h"
#include "game.h"
#include <time.h>

int main() {
    // setup random
    srand(time(NULL));


    printf("Blackjack\n");

    GameManager gm;
    createGame(&gm, 3);

    newRound(&gm);

    endGame(&gm);

    // setup gamedeck 
    // Deck gameDeck = {NULL, 0};
    // createDeck(&gameDeck);
    
    // // initialise player hand
    // Hand myhand = {NULL, 0};
    // drawCard(&myhand, &gameDeck);
    // drawCard(&myhand, &gameDeck);
    // displayHand(&myhand);

    // drawCard(&myhand, &gameDeck);
    // displayHand(&myhand);

    // /*
    // Hand/Deck data layout

    // Hand {
    //     cards {
    //         Card{face = A, value = 11}, Card{8, 8}, Card{10, 10}
    //     }
    //     cardsInHand = 3
    // }
    
    // */
    // // free dynamic memory used
    // freeHand(&myhand);
    // freeHand(&gameDeck);
    return 0;
}
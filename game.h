/*
File to manage rounds and game state

Game manager to keep track of score, players and rounds


Round to give each player there turn and handle there input
round also keeps track of score

cards will be dealt face up and the dealer will get second card after players turn
dealer cant stand below 17 

on a players turn they will have the option to:
    Hit – Take another card.
    Stand – Keep your current hand.
    Double Down – Double your bet, take one more card, then stand.
    Surrender (if allowed) – Give up your hand and get half your bet back.

    they wont be able to... yet
    Split – If you have two cards of the same value, split them into two hands (requires an additional bet).

*/
#ifndef GAME_H
#define GAME_H
#include "cards.h"

typedef struct {
    // players - max 6
    // players will be based on index; player 1, player 2
    int playerCount;
    // scores will be kept in array based on players index
    int scores[6];
    // array of pointers to player hands
    Hand playerHands[6];
    Hand dealer;
    Deck deck;
    // counter to keep track of the round
    int round;

    // might need failsafe to ensure game is created
} GameManager;

// initialise values needed for game
void createGame(GameManager *gm, int playerCount);
// present player with options for turn and handle choices
void playerTurn(GameManager *gm, int player);

// dealer (AI) turn
void dealerTurn(GameManager *gm);

// start new round and give all players their turn
void newRound(GameManager *gm);


// free memory used in game
void endGame(GameManager *gm);
#endif
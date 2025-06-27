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
void createGame(GameManager *gm, int playerCount) {
    // set players
    gm->playerCount = playerCount;
    // init player hands not needed due to happening at start of each round
    // set round to 0
    gm->round = 0;

    // initialise all hands and decks
    for (int i = 0; i < 6; i++) {
        gm->playerHands[i].cards = NULL;
        gm->playerHands[i].cardsInHand = 0;
    }

    gm->dealer.cards = NULL;
    gm->dealer.cardsInHand = 0;

    gm->deck.cards = NULL;
    gm->deck.cardsInHand = 0;
}
// present player with options for turn and handle choices
void playerTurn(GameManager *gm, int player);
// start new round and give all players their turn
void newRound(GameManager *gm) {
    // clear player hands and game deck
    freeHand(&gm->deck); 
    freeHand(&gm->dealer);
    for (int p = 0; p < gm->playerCount; p++) {
        // free memory from existing hand
        freeHand(&gm->playerHands[p]);
        // assign default values to player hands
        gm->playerHands[p].cards = NULL;
        gm->playerHands[p].cardsInHand = 0;
    }
    // increment round counter
    gm->round += 1;
    // setup deck for round and dealer
    gm->deck.cards = NULL;
    gm->deck.cardsInHand = 0;
    gm->dealer.cards = NULL;
    gm->dealer.cardsInHand = 0;
    createDeck(&gm->deck);
    // deal cards
    // deal as if real game - except don't give dealer second card
    // deal card to dealer after players
    for (int i = 0; i < gm->playerCount; i++) {
        // give each player two cards
        for (int c = 0; c < 2; c++) {
            // draw card for player
            drawCard(&gm->playerHands[i], &gm->deck);
        }
    }
    drawCard(&gm->dealer, &gm->deck);

    // display cards
    for (int p = 0; p < gm->playerCount; p++) {
        printf("Player %i\n", p+1);
        displayHand(&gm->playerHands[p]);
    }
    // dealers cards
    printf("Dealer\n");
    displayHand(&gm->dealer);
}


// free memory used in game
void endGame(GameManager *gm) {
    // free all dynamic memory
    for (int i = 0; i < gm->playerCount; i++) {
        freeHand(&gm->playerHands[i]);
    }
    freeHand(&gm->dealer);
    freeHand(&gm->deck);
    gm->playerCount = 0;
}
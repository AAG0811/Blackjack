#include "game.h"
#include "cards.h"

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
// TODO handle player turn
void playerTurn(GameManager *gm, int player) {}

// dealer (AI) turn
void dealerTurn(GameManager *gm) {}

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

    // each player takes their turn 
    // handle dealers turn
    // score round and adjust game scores

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
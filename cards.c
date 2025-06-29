#include "cards.h"

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
const char* cardBase[] = {
    "\033[1m╭─────╮\033[0m",
    "\033[1m│%s   │\033[0m",
    "\033[1m│     │\033[0m",
    "\033[1m│   %s│\033[0m",
    "\033[1m╰─────╯\033[0m",

};
// the amount of lines in the card graphic
// could use sizeof but since card graphic wont be changing, the number is hardcoded
// stored as a variable so it is easy to change
const int linesInCard = 5;

// loop through all values to create complete 'deck' of cards
// variables to store all possible cards when creating the deck of cards
// the Ace card is stored as 11 but game logic code will also consider it as a 1
const char* faces[13] = {"A ", "2 ", "3 ", "4 ", "5 ", "6 ", "7 ", "8 ", "9 ", "10", "J ", "Q ", "K "};
const int values[13] = {11, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10};

// function to create a logical deck of cards 
void createDeck(Deck* dest) {
    // 13 different cards; 4 suits
    // allocate space for 52 cards
    dest->cards = (Card *)malloc(52 * sizeof(Card));
    dest->cardsInHand = 52;
    if (!dest->cards) {
        perror("Failed to allocate memory for deck");
        exit(EXIT_FAILURE);
    }
    // index stores what posion in the deck array is currently being written to
    int index = 0;
    // assign each card to deck
    // loop for each suit of card (4 times)
    for (int s = 0; s < 4; s++) {
        // loop for each card in the list of card types 
        for (int c = 0; c < 13; c++) {
            // copy string value from card faces to the array in the deck
            strncpy(dest->cards[index].face, faces[c], 3);
            // make sure string is terminated
            dest->cards[index].face[2] = '\0';
            // assign corrosponding card value
            dest->cards[index].value = values[c];
            // increment index to assign next card to next spot in array
            index+=1;
        }
    }
}

// remove a random card from the deck of cards
void popFromDeck(Card *dest, Deck *deck) {
    // select card at random index
    // remove from dynamic array (deck)
    // assign random card from deck to dest
    if (deck->cardsInHand == 0) {
        fprintf(stderr, "Deck is empty!\n");
        exit(EXIT_FAILURE);
    }
    // select a random index from the cards array using it's length
    int index = rand() % deck->cardsInHand;
    // write new card value to the card
    *dest = deck->cards[index];
    // set the selected card in the deck to the last card in the deck; removing selected card from the deck
    deck->cards[index] = deck->cards[deck->cardsInHand - 1];
    // shrink the deck by 1
    deck->cardsInHand--;
}

// draws random card from deck and assigns it to a players hand
void drawCard(Hand *hand, Deck *deck) { 
    // ensuring hand is initialised 
    if (hand->cardsInHand < 0) hand->cardsInHand = 0;
    if (hand->cards == NULL && hand->cardsInHand == 0) {
        hand->cards = (Card *)malloc(sizeof(Card));
    } else {   
        // increase size of dynamic array and check for allocation error
        hand->cards = (Card *)realloc(hand->cards, (hand->cardsInHand+1) * sizeof(Card)); // +1 because cards hasn't been incremented yet
    }
    if (!hand->cards) {
        perror("Failed to allocate memory for cards");
        exit(EXIT_FAILURE);
    }
    // temp Card to save output from deck 
    Card drawn;
    popFromDeck(&drawn, deck);
    // assign face and value from drawn card to hand
    hand->cards[hand->cardsInHand] = drawn;
    // increase cards in hand by 1 and expand array by the size of 1 card struct
    // only increment if above code doesn't fail
    hand->cardsInHand += 1;
}

// displays all the cards in a players hand
void displayHand(Hand *hand) {
    // print each line of card glyph seperately 
    // so cards can easily be drawn next to each other
    for (int i = 0; i < linesInCard; i++) { 
        for (int c = 0; c < hand->cardsInHand; c++) {
            // the only lines in the card glyph that need changing are lines 1 and 3
            if (i == 1 || i == 3) {
                // lines with values
                printf(cardBase[i], hand->cards[c].face);
            } else {
                // lines that don't change
                printf(cardBase[i]);
            }
            printf("\t");
       }
        printf("\n");
    }
}

// free memory used
void freeHand(Hand *hand) {
    free(hand->cards);
    hand->cardsInHand = 0;
    hand->cards = NULL;
}
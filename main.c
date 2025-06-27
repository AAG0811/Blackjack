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

/* Code to make program windows compatible*/
#ifdef _WIN32
#include <windows.h>
void enable_utf8_ansi_windows() {
    // Set output/input to UTF-8
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    // Enable ANSI escape codes
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;
    if (GetConsoleMode(hOut, &dwMode)) {
        dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
        SetConsoleMode(hOut, dwMode);
    }
}
#else
// No-op on non-Windows
void enable_utf8_ansi_windows() {}
#endif

int main() {
    // windows compatibility
    enable_utf8_ansi_windows();
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
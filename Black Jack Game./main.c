#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char** argv)
{

    // Inital Code given in Problem Statement
    if(argc == 1)
        srand(time(NULL));
    else
        srand(atoi(argv[1]));

    // Initializing variables used for user input
    int validInput, inputNumber;

    // Initializing variables used for cards the player and dealer get
    int dealerCard1 = rand() % 13 + 1;
    int playerCard1 = rand() % 13 + 1;
    int playerCard2 = rand() % 13 + 1;
    int playerCard3 = rand() % 13 + 1;
    int dealerCard2 = rand() % 13 + 1;
    int dealerCard3 = rand() % 13 + 1;
    int playerCard4 = rand() % 13 + 1;
    int dealerCard4 = rand() % 13 + 1;
    int playerCard5 = rand() % 13 + 1;

    // Initializing variables to store value of each card
    int playerCard1Val, playerCard2Val, playerCard3Val, playerCard4Val, playerCard5Val, dealerCard1Val, dealerCard2Val,
        dealerCard3Val, dealerCard4Val, playerCardValTotal;
    const int VALUE_OF_CARDS_ABOVE_TEN = 10;
    const int HIGHEST_VALUE_POSSIBLE= 21; 

    // Initial Print statement for first cards to player and dealer
    printf("First cards: player %d, dealer %d \n", playerCard1, dealerCard1);

    // Program for value of first card to dealer
    if(dealerCard1 <= VALUE_OF_CARDS_ABOVE_TEN)
        dealerCard1Val = dealerCard1;

    else
        dealerCard1Val = VALUE_OF_CARDS_ABOVE_TEN;

    // Program for value of first card to player
    if(playerCard1 <= VALUE_OF_CARDS_ABOVE_TEN)
        playerCard1Val = playerCard1;

    else
        playerCard1Val = VALUE_OF_CARDS_ABOVE_TEN;

    // Initializing first value of total player card value
    playerCardValTotal = playerCard1Val;

    // Determining value of all dealer cards
    if(dealerCard2 <= VALUE_OF_CARDS_ABOVE_TEN) {
        dealerCard2Val = dealerCard2;
    } else {
        dealerCard2Val = VALUE_OF_CARDS_ABOVE_TEN;
    }

    if(dealerCard3 <= VALUE_OF_CARDS_ABOVE_TEN) {
        dealerCard3Val = dealerCard3;
    } else {
        dealerCard3Val = VALUE_OF_CARDS_ABOVE_TEN;
    }

    if(dealerCard4 <= VALUE_OF_CARDS_ABOVE_TEN) {
        dealerCard4Val = dealerCard4;
    } else {
        dealerCard4Val = VALUE_OF_CARDS_ABOVE_TEN;
    }

    // Ensuring that user inputs valid input, otherwise prompt is repeated: Round 1
    do {
        printf("Type 1 for Hit, 0 to Stay:");
        scanf("%d", &inputNumber);
        if(inputNumber == 1 || inputNumber == 0)
            validInput = 1;
        else
            validInput = 0;
    } while(validInput == 0);

    // Condition if user input is 1
    if(inputNumber == 1) {
        if(playerCard2 <= VALUE_OF_CARDS_ABOVE_TEN)
            playerCard2Val = playerCard2;
        else
            playerCard2Val = VALUE_OF_CARDS_ABOVE_TEN;
        playerCardValTotal = playerCardValTotal + playerCard2Val; // Value continues throughout the entire program
        printf("Player gets a %d, worth is %d \n", playerCard2, playerCardValTotal);
        if(playerCardValTotal > HIGHEST_VALUE_POSSIBLE) {
            printf("Player over 21, Dealer wins");
            return (0);
        }
    }

    // Condition if user input is 0
    else {
        if(playerCard1Val > dealerCard1Val && playerCard1Val < HIGHEST_VALUE_POSSIBLE) {
            printf("Player better than Dealer, Player wins \n");
            return (0);
        } else if(playerCard1Val < dealerCard1Val && dealerCard1Val < HIGHEST_VALUE_POSSIBLE) {
            printf("Dealer better than Player, Dealer wins \n");
            return (0);
        } else if(dealerCard1Val > HIGHEST_VALUE_POSSIBLE) {
            printf("Dealer over 21, Player wins \n");
            return (0);
        } else if(dealerCard1Val == playerCard1Val) {
            printf("Tie! \n");
            return (0);
        } else if(playerCard1Val > HIGHEST_VALUE_POSSIBLE) {
            printf("Player over 21, Dealer wins \n");
            return (0);
        }
    }

    // Ensuring that user inputs valid input, otherwise prompt is repeated: Round 2
    do {
        printf("Type 1 for Hit, 0 to Stay:");
        scanf("%d", &inputNumber);
        if(inputNumber == 1 || inputNumber == 0)
            validInput = 1;
        else
            validInput = 0;
    } while(validInput == 0);

    // Condition if user input is 1
    if(inputNumber == 1) {
        if(playerCard3 <= VALUE_OF_CARDS_ABOVE_TEN)
            playerCard3Val = playerCard3;
        else
            playerCard3Val = VALUE_OF_CARDS_ABOVE_TEN;
        playerCardValTotal = playerCardValTotal + playerCard3Val; // Value continues throughout the entire program
        printf("Player gets a %d, worth is %d \n", playerCard3, playerCardValTotal);
        if(playerCardValTotal > HIGHEST_VALUE_POSSIBLE) {
            printf("Player over 21, Dealer wins");
            return (0);
        }
    }

    // Condition if user input is 0
    else {
        printf("Dealer gets: %d \n", dealerCard2);
        if((playerCard1Val + playerCard2Val) > (dealerCard1Val + dealerCard2Val) &&
            (playerCard1Val + playerCard2Val) < HIGHEST_VALUE_POSSIBLE) {
            printf("Player better than Dealer, Player wins \n");
            return (0);
        } else if((playerCard1Val + playerCard2Val) < (dealerCard1Val + dealerCard2Val) &&
            (dealerCard1Val + dealerCard2Val) < HIGHEST_VALUE_POSSIBLE) {
            printf("Dealer better than Player, Dealer wins \n");
            return (0);
        } else if((dealerCard1Val + dealerCard2Val) > HIGHEST_VALUE_POSSIBLE) {
            printf("Dealer over 21, Player wins \n");
            return (0);
        } else if((dealerCard1Val + dealerCard2Val) == (playerCard1Val + playerCard2Val)) {
            printf("Tie! \n");
            return (0);
        } else if((playerCard1Val + playerCard2Val) > HIGHEST_VALUE_POSSIBLE) {
            printf("Player over 21, Dealer wins \n");
            return (0);
        }
    }

    // Ensuring that user inputs valid input, otherwise prompt is repeated: Round 3
    do {
        printf("Type 1 for Hit, 0 to Stay:");
        scanf("%d", &inputNumber);
        if(inputNumber == 1 || inputNumber == 0)
            validInput = 1;
        else
            validInput = 0;

    } while(validInput == 0);

    // Condition if user input is 1
    if(inputNumber == 1) {
        if(playerCard4 <= 10)
            playerCard4Val = playerCard4;
        else
            playerCard4Val = VALUE_OF_CARDS_ABOVE_TEN;
        playerCardValTotal = playerCardValTotal + playerCard4Val; // Value continues throughout the entire program
        printf("Player gets a %d, worth is %d \n", playerCard4, playerCardValTotal);
        if(playerCardValTotal > HIGHEST_VALUE_POSSIBLE) {
            printf("Player over 21, Dealer wins \n");
            return (0);
        }
    }

    // Condition if user input is 0
    else {
        printf("Dealer gets: %d %d \n", dealerCard2, dealerCard3);
        if((playerCard1Val + playerCard2Val + playerCard3Val) > (dealerCard1Val + dealerCard2Val + dealerCard3Val) &&
            (playerCard1Val + playerCard2Val + playerCard3Val) < HIGHEST_VALUE_POSSIBLE) {
            printf("Player better than Dealer, Player wins \n");
            return (0);
        } else if((playerCard1Val + playerCard2Val + playerCard3Val) <
                (dealerCard1Val + dealerCard2Val + dealerCard3Val) &&
            (dealerCard1Val + dealerCard2Val + dealerCard3Val) < HIGHEST_VALUE_POSSIBLE) {
            printf("Dealer better than Player, Dealer wins \n");
            return (0);
        } else if((dealerCard1Val + dealerCard2Val + dealerCard3Val) > HIGHEST_VALUE_POSSIBLE) {
            printf("Dealer over 21, Player wins \n");
            return (0);
        } else if((dealerCard1Val + dealerCard2Val + dealerCard3Val) ==
            (playerCard1Val + playerCard2Val + playerCard3Val)) {
            printf("Tie! \n");
            return (0);
        } else if((playerCard1Val + playerCard2Val + playerCard3Val) > HIGHEST_VALUE_POSSIBLE) {
            printf("Player over 21, Dealer wins \n");
            return (0);
        }
    }

    // Ensuring that user inputs valid input, otherwise prompt is repeated: Round 4
    do {
        printf("Type 1 for Hit, 0 to Stay:");
        scanf("%d", &inputNumber);
        if(inputNumber == 1 || inputNumber == 0)
            validInput = 1;
        else
            validInput = 0;
    } while(validInput == 0);

    // Condition if user input is 1
    if(inputNumber == 1) {
        if(playerCard5 <= VALUE_OF_CARDS_ABOVE_TEN)
            playerCard5Val = playerCard5;
        else
            playerCard5Val = VALUE_OF_CARDS_ABOVE_TEN;
        playerCardValTotal = playerCardValTotal + playerCard5Val; // Value continues throughout the entire program
        printf("Player gets a %d, worth is %d \n", playerCard5, playerCardValTotal);
        if(playerCardValTotal > HIGHEST_VALUE_POSSIBLE) {
            printf("Player over 21, Dealer wins");
            return (0);
        }
    }

    // Condition if user input is 0
    else {
        printf("Dealer gets: %d %d %d \n", dealerCard2, dealerCard3, dealerCard4);
        if((playerCard1Val + playerCard2Val + playerCard3Val + playerCard4Val) >
                (dealerCard1Val + dealerCard2Val + dealerCard3Val + dealerCard4Val) &&
            (playerCard1Val + playerCard2Val + playerCard3Val + playerCard4Val) < HIGHEST_VALUE_POSSIBLE) {
            printf("Player better than Dealer, Player wins \n");
            return (0);
        } else if((playerCard1Val + playerCard2Val + playerCard3Val + playerCard4Val) <
                (dealerCard1Val + dealerCard2Val + dealerCard3Val + dealerCard4Val) &&
            (dealerCard1Val + dealerCard2Val + dealerCard3Val + playerCard4Val) < HIGHEST_VALUE_POSSIBLE) {
            printf("Dealer better than Player, Dealer wins \n");
            return (0);
        } else if((dealerCard1Val + dealerCard2Val + dealerCard3Val + dealerCard4Val) > HIGHEST_VALUE_POSSIBLE) {
            printf("Dealer over 21, Player wins \n");
            return (0);
        } else if((dealerCard1Val + dealerCard2Val + dealerCard3Val + dealerCard4Val) ==
            (playerCard1Val + playerCard2Val + playerCard3Val + playerCard4Val)) {
            printf("Tie! \n");
            return (0);
        } else if((playerCard1Val + playerCard2Val + playerCard3Val + playerCard4Val) > HIGHEST_VALUE_POSSIBLE) {
            printf("Player over 21, Dealer wins \n");
            return (0);
        }
    }
} // End of program

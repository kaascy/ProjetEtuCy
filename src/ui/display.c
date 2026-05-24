#include <stdio.h>
#include "display.h"

#define RED    "\033[31m"
#define GREEN  "\033[32m"
#define YELLOW "\033[33m"
#define CYAN   "\033[36m"
#define BOLD   "\033[1m"
#define RESET  "\033[0m"

// display a single card
void display_card(Card c)
{
    if (c.type == NUM) {
        printf("[%d] ", c.value);
    } else if (c.type == BONUS_MULT) {
        printf(GREEN "[x%d] " RESET, c.value);
    } else if (c.type == BONUS_ADD) {
        printf(RED "[+%d] " RESET, c.value);
    }
}

// display all info of a player
void display_player(const Player *p)
{
    int i;

    printf(BOLD "Joueur : %s\n" RESET, p->name);

    printf("  Cartes en main : ");
    if (p->handSize == 0) {
        printf("(aucune)");
    } else {
        for (i = 0; i < p->handSize; i++) {
            display_card(p->hand[i]);
        }
    }
    printf("\n");

    printf("  Score de la manche : " YELLOW "%d" RESET "\n", p->roundScore);
    printf("  Score total        : " YELLOW "%d" RESET "\n", p->totalScore);
}

// display the current game state for the current player
void display_game_status(const Player players[], int currentPlayer,
                         int nbPlayers, const Deck *deck)
{
    int i, j;
    int compteur[13] = {0};

    printf("\n");
    for (i = 0; i < 50; i++) printf("-");
    printf("\n");

    printf(BOLD CYAN ">> Joueur actuel : %s <<\n" RESET, players[currentPlayer].name);
    printf("   Cartes restantes dans la pioche : %d\n\n", deck->size);

    // count cards already drawn by all players
    for (i = 0; i < nbPlayers; i++) {
        for (j = 0; j < players[i].handSize; j++) {
            if (players[i].hand[j].type == NUM)
                compteur[players[i].hand[j].value]++;
        }
    }

    // display only values that have been drawn at least once
    printf("  Cartes deja piochees : ");
    for (i = 0; i <= 12; i++) {
        if (compteur[i] > 0)
            printf("[%d]x%d  ", i, compteur[i]);
    }
    printf("\n\n");

    display_player(&players[currentPlayer]);
    printf("\n");
}

// display the round summary with scores
void display_round_summary(const Player players[], int nbPlayers)
{
    int i;

    printf("\n");
    for (i = 0; i < 50; i++) printf("=");
    printf("\n");
    printf(BOLD "  Fin de la manche - Scores :\n" RESET);

    for (i = 0; i < nbPlayers; i++) {
        printf("  %-15s : %d pts (total : %d)\n",
               players[i].name,
               players[i].roundScore,
               players[i].totalScore);
    }

    for (i = 0; i < 50; i++) printf("=");
    printf("\n\n");
}

// find and display the winner of the game
void display_winner(const Player players[], int nbPlayers)
{
    int i;
    int indexGagnant = 0;

    // find the player with the highest total score
    for (i = 1; i < nbPlayers; i++) {
        if (players[i].totalScore > players[indexGagnant].totalScore)
            indexGagnant = i;
    }

    printf("\n");
    for (i = 0; i < 50; i++) printf("*");
    printf("\n");
    printf(BOLD GREEN "  Le gagnant de la partie est %s avec %d points !\n" RESET,
           players[indexGagnant].name,
           players[indexGagnant].totalScore);
    for (i = 0; i < 50; i++) printf("*");
    printf("\n\n");
}
#include <stdio.h>
#include "display.h"
 
#define RED    "\033[31m"
#define GREEN  "\033[32m"
#define YELLOW "\033[33m"
#define CYAN   "\033[36m"
#define BOLD   "\033[1m"
#define RESET  "\033[0m"
 
// affiche une seule carte
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
 
// affiche les infos d'un joueur
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
 
// affiche l'etat global du jeu pour le joueur courant
void display_game_status(const Player players[], int currentPlayer,
                         int nbPlayers, const Deck *deck)
{
    int i;
    (void)nbPlayers;
 
    printf("\n");
    for (i = 0; i < 50; i++) printf("-");
    printf("\n");
 
    printf(BOLD CYAN ">> Joueur actuel : %s <<\n" RESET, players[currentPlayer].name);
    printf("   Cartes restantes dans la pioche : %d\n", deck->size);
 
    display_player(&players[currentPlayer]);
    printf("\n");
}
 
// affiche le bilan de fin de manche
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
 
// affiche le gagnant final
void display_winner(const Player players[], int nbPlayers)
{
    int i;
    int indexGagnant = 0;
 
    // trouver le joueur avec le meilleur score
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

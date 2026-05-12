#include <stdio.h>
#include "stats.h"
 
// affiche le joueur avec le score total le plus eleve
void stats_display_best_player(const Player players[], int nbPlayers)
{
    int i;
    int indexMeilleur = 0;
 
    for (i = 1; i < nbPlayers; i++) {
        if (players[i].totalScore > players[indexMeilleur].totalScore)
            indexMeilleur = i;
    }
 
    printf("  Meilleur joueur : %s avec %d points\n",
           players[indexMeilleur].name,
           players[indexMeilleur].totalScore);
}
 
// affiche la moyenne des scores de tous les joueurs
void stats_display_average_scores(const Player players[], int nbPlayers)
{
    int i;
    int somme = 0;
    float moyenne;
 
    for (i = 0; i < nbPlayers; i++)
        somme += players[i].totalScore;
 
    moyenne = (float)somme / nbPlayers;
    printf("  Moyenne des scores : %.2f\n", moyenne);
}
 
// affiche tous les scores en colonnes alignees
void stats_display_all_scores(const Player players[], int nbPlayers)
{
    int i;
 
    printf("\n  %-15s | %s\n", "Joueur", "Score total");
    printf("  ---------------|-----------\n");
    for (i = 0; i < nbPlayers; i++) {
        printf("  %-15s | %d pts\n",
               players[i].name,
               players[i].totalScore);
    }
    printf("\n");
}

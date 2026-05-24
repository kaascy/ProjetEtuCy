#include <stdio.h>
#include "save.h"
#include "../ui/input.h"
 
// save the scores in a text file
void save_scores_to_file(const Player players[], int nbPlayers)
{
    char filename[100];
    FILE *fichier;
    int i;
 
    safe_input_string(filename, sizeof(filename), "Nom du fichier de sauvegarde");
 
    fichier = fopen(filename, "w");
    if (fichier == NULL) {
        printf("  Erreur : impossible de creer le fichier '%s'.\n", filename);
        return;
    }
 
    //  NAME | TOTAL_SCORE | ROUND_SCORE
    for (i = 0; i < nbPlayers; i++) {
        fprintf(fichier, "%s | %d | %d\n",
                players[i].name,
                players[i].totalScore,
                players[i].roundScore);
    }
 
    fclose(fichier);
    printf("  Scores sauvegardes dans '%s'.\n", filename);
}
 
// loads and displays scores from a file
void load_scores_from_file(const char *filename)
{
    FILE *fichier;
    char ligne[200];
 
    fichier = fopen(filename, "r");
    if (fichier == NULL) {
        printf("  Erreur : impossible d'ouvrir '%s'.\n", filename);
        return;
    }
 
    printf("\n  --- Contenu de '%s' ---\n", filename);
    while (fgets(ligne, sizeof(ligne), fichier) != NULL)
        printf("  %s", ligne);
    printf("  -----------------------\n");
 
    fclose(fichier);
}

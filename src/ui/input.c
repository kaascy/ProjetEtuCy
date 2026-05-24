#include <stdio.h>
#include <string.h>
#include "input.h"

// reads a number between min and max 
int safe_input_int(const char *prompt, int min, int max)
{
    int valeur;
    int resultat;

    while (1) {
        printf("%s (entre %d et %d) : ", prompt, min, max);
        resultat = scanf("%d", &valeur);

        // clear the  buffer
        while (getchar() != '\n');

        if (resultat != 1) {
            printf("  Erreur : veuillez entrer un nombre.\n");
            continue;
        }
        if (valeur < min || valeur > max) {
            printf("  Erreur : le nombre doit etre entre %d et %d.\n", min, max);
            continue;
        }
        return valeur;
    }
}

void safe_input_string(char *buffer, int size, const char *prompt)
{
    int longueur;

    while (1) {
        printf("%s : ", prompt);
        fgets(buffer, size, stdin);

        // remove the line break left by fgets
        longueur = strlen(buffer);
        if (longueur > 0 && buffer[longueur - 1] == '\n')
            buffer[longueur - 1] = '\0';

        // ask again if the player pressed enter without typing
        if (strlen(buffer) == 0) {
            printf("  Erreur : veuillez entrer quelque chose.\n");
            continue;
        }

        return;
    }
}

// yes or no question
int safe_input_yes_no(const char *prompt)
{
    char reponse[20];

    while (1) {
        safe_input_string(reponse, sizeof(reponse), prompt);

        if (strcmp(reponse, "o") == 0 || strcmp(reponse, "O") == 0 ||
            strcmp(reponse, "oui") == 0 || strcmp(reponse, "OUI") == 0)
            return 1;

        if (strcmp(reponse, "n") == 0 || strcmp(reponse, "N") == 0 ||
            strcmp(reponse, "non") == 0 || strcmp(reponse, "NON") == 0)
            return 0;

        // Neither yes nor no we ask again.
        printf("  Erreur : tapez 'oui' ou 'non'.\n");
    }
}

// asks the player to draw or go out
int safe_input_choice_pipick(void)
{
    printf("Piocher (1) ou sortir (2) ?\n");
    return safe_input_int("Votre choix", 1, 2);
}
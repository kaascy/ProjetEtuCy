#include <stdio.h>
#include <string.h>
#include "input.h"

// lit un entier entre min et max, redemande si la saisie est invalide
int safe_input_int(const char *prompt, int min, int max)
{
    int valeur;
    int resultat;

    while (1) {
        printf("%s (entre %d et %d) : ", prompt, min, max);
        resultat = scanf("%d", &valeur);

        // vider le buffer clavier apres chaque saisie
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

// lit une chaine de caracteres et enleve le \n final
// redemande si la chaine est vide
void safe_input_string(char *buffer, int size, const char *prompt)
{
    int longueur;

    while (1) {
        printf("%s : ", prompt);
        fgets(buffer, size, stdin);

        // supprimer le retour a la ligne laisse par fgets
        longueur = strlen(buffer);
        if (longueur > 0 && buffer[longueur - 1] == '\n')
            buffer[longueur - 1] = '\0';

        // redemander si le joueur a appuye sur entree sans rien taper
        if (strlen(buffer) == 0) {
            printf("  Erreur : veuillez entrer quelque chose.\n");
            continue;
        }

        return;
    }
}

// pose une question oui/non, retourne 1 pour oui et 0 pour non
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

        // ni oui ni non, on redemande
        printf("  Erreur : tapez 'oui' ou 'non'.\n");
    }
}

// demande au joueur de piocher ou sortir, retourne 1 ou 2
int safe_input_choice_pipick(const char *prompt)
{
    (void)prompt;
    printf("Piocher (1) ou sortir (2) ?\n");
    return safe_input_int("Votre choix", 1, 2);
}
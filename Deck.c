#include <stdio.h>
#include “deck.h”
#include “../utils/random.h” le troisième ?

// deck init deck_init
 Remplit le paquet 85 cartes :
(79 cartes numerotees)
 (6 cartes bonus) //

void deck_init(Deck *paquet) {
    paquet->taille = 0;
    for (int valeur_carte = 0; valeur_carte <= 12; valeur_carte++) {
        int nb_exemplaires;
 if (valeur_carte <= 1) {
    nb_exemplaires = 1;
}   else {
    nb_exemplaires = valeur_carte;
}
   for (int exemplaire = 0; exemplaire < nb_exemplaires; exemplaire++) {
            paquet->cartes[paquet->taille].type   = NUM;
            paquet->cartes[paquet->taille].valeur = valeur_carte;
            paquet->taille++;
        }
    }
   //Carte bonus x2 //
    paquet->cartes[paquet->taille].type   = BONUS_MULT;
    paquet->cartes[paquet->taille].valeur = 2;
    paquet->taille++;

    //Cartes bonus add : +2, +4, +6, +8, +10 //
    int montants_bonus_add[] = {2, 4, 6, 8, 10};
    int nb_bonus_add         = 5;

    for (int indice_bonus = 0; indice_bonus < nb_bonus_add; indice_bonus++) {
        paquet->cartes[paquet->taille].type   = BONUS_ADD;
        paquet->cartes[paquet->taille].valeur = montants_bonus_add[indice_bonus];
        paquet->taille++;
    }
   
}

//Deck shufle melanger aleatoir//
void deck_shuffle(Deck *paquet) {
    for (int position_courante = paquet->taille - 1; position_courante > 0; position_courante--) {
        int position_echange = random_int(0, position_courante);

        Carte carte_temp                      = paquet->cartes[position_courante];
        paquet->cartes[position_courante]     = paquet->cartes[position_echange];
        paquet->cartes[position_echange]      = carte_temp;
    }
}



//Deck draw retourn et retourn au dessus//
Carte deck_draw(Deck *paquet) {
    Carte carte_vide = { NUM, -1 };

        if (paquet->taille == 0) {
        return carte_vide;
    }

    paquet->taille--;
      return paquet->cartes[paquet->taille];
}


//Deck print affiche les cartes restantes//
void deck_print(const Deck *paquet) {
    printf(" Paquet (%d cartes restantes) \n", paquet->taille);

    for (int position = 0; position < paquet->taille; position++) {
        const Carte *carte_courante = &paquet->cartes[position];

           if (carte_courante->type == NUM) {
            printf("  [%2d] NUM        valeur = %d\n",
                   position, carte_courante->valeur);
        }    else if (carte_courante->type == BONUS_MULT) {
            printf("  [%2d] BONUS_MULT valeur = x %d\n",
                   position, carte_courante->valeur);
        }     else if (carte_courante->type == BONUS_ADD) {
            printf("  [%2d] BONUS_ADD  valeur = + %d\n",
                   position, carte_courante->valeur);
        }
    }
}


//Deck empty retourn 1 ou 0 si deck vide//
int deck_is_empty(const Deck *paquet) {
    return paquet->taille == 0;
}

// Deck size retourn le nombre de carte encore presentes//

int deck_size(const Deck *paquet) {
    return paquet->taille;
}


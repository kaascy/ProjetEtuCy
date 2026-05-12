#include <stdio.h>
#include "deck/structures.h"
#include "ui/display.h"
#include "ui/input.h"
#include "save/save.h"
#include "stats/stats.h"

/* ces fonctions seront fournies par Brahim et Kais */
void deck_init(Deck *deck);
void deck_shuffle(Deck *deck);
void game_run(Deck *deck, Joueur players[], int nbPlayers);

int main(void)
{
    Deck deck;
    Joueur players[10];
    int nbPlayers;
    int i;
    char nomJoueur[50];

    printf("\n  ====================================\n");
    printf("       Bienvenue dans FLIPTECH !\n");
    printf("  ====================================\n\n");

    deck_init(&deck);
    deck_shuffle(&deck);
    printf("  Deck pret : %d cartes melangees.\n\n", deck.taille);

    nbPlayers = safe_input_int("Combien de joueurs ?", 1, 10);

    for (i = 0; i < nbPlayers; i++) {
        printf("  Nom du joueur %d", i + 1);
        safe_input_string(nomJoueur, sizeof(nomJoueur), "");
        // player_init sera fourni par Kais
        // player_init(&players[i], nomJoueur);
    }

    printf("\n  La partie commence ! Bonne chance.\n\n");

    game_run(&deck, players, nbPlayers);

    display_winner(players, nbPlayers);

    if (safe_input_yes_no("Voulez-vous enregistrer les scores ? (oui/non)"))
        save_scores_to_file(players, nbPlayers);

    if (safe_input_yes_no("Voulez-vous voir les statistiques ? (oui/non)")) {
        printf("\n  --- Statistiques ---\n");
        stats_display_best_player(players, nbPlayers);
        stats_display_average_scores(players, nbPlayers);
        stats_display_all_scores(players, nbPlayers);
    }

    printf("  Merci d'avoir joue a FlipTech !\n\n");
    return 0;
}

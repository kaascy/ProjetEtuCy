#include "../game/game.h"
#include "../rules/rules.h"
#include "../game/round.h"
#include "../ui/display.h"
#include "../ui/input.h"
#include <stdio.h>

void game_run(Deck *deck, Player players[], int nbPlayers)
{
    int game_over = 0;

    while (!game_over && !deck_is_empty(deck)) {

        round_reset_all_players(players, nbPlayers);

        int out[10];
        int i;
        for (i = 0; i < nbPlayers; i++) out[i] = 0;

        int round_running = 1;

        while (round_running && !deck_is_empty(deck)) {

            int tous_sortis = 1;

            for (i = 0; i < nbPlayers && round_running; i++) {

                if (out[i]) continue;

                tous_sortis = 0;

                // afficher l'etat du jeu pour le joueur courant
                display_game_status(players, i, nbPlayers, deck);

                // demander piocher ou sortir
                int choice = safe_input_choice_pipick("");

                if (choice == 2) {
                    out[i] = 1;
                    continue;
                }

                // piocher une carte
                Card c = deck_draw(deck);

                // afficher la carte piochee immediatement
                printf("  Carte piochee : ");
                display_card(c);
                printf("\n");

                RoundStatus status = rules_apply_card(&players[i], c);

                if (status == ROUND_LOST) {
                    printf("  Doublon ! %s perd la manche.\n", players[i].name);
                    players[i].roundScore = 0;
                    out[i] = 1;
                } else if (status == ROUND_OVER_WIN) {
                    printf("  7 cartes differentes ! %s gagne la manche.\n", players[i].name);
                    round_apply_bonus_winner(&players[i]);
                    round_running = 0;
                }
            }

            // si tout le monde est sorti la manche est terminee
            if (tous_sortis) round_running = 0;
        }

        // calculer et ajouter les scores finaux
        for (i = 0; i < nbPlayers; i++) {
            int final_score = rules_compute_round_score(&players[i]);
            players[i].totalScore += final_score;
        }

        // afficher le resume de la manche
        display_round_summary(players, nbPlayers);

        // verifier si la partie est terminee
        if (rules_is_game_over(players, nbPlayers))
            game_over = 1;
    }
}
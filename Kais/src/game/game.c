#include "game.h"
#include "rules.h"
#include "round.h"
#include <stdio.h>

/* je dois mettre en commun avec youssef */

void game_run(Deck *deck, Player players[], int nbPlayers) {
    int game_over = 0;
    int round_winner = -1;

    while (!game_over && !deck_is_empty(deck)) {
        round_reset_all_players(players, nbPlayers);
        int out[nbPlayers];
        for (int i = 0; i < nbPlayers; i++) out[i] = 0;
        int round_running = 1;

        while (round_running && !deck_is_empty(deck)) {
            for (int i = 0; i < nbPlayers && round_running; i++) {
                if (out[i]) continue;

                printf("\n--- %s's turn (round score: %d) ---\n", players[i].name, players[i].roundScore);
                printf("1. Draw card\n");
                printf("2. Exit round\n");
                printf("Choice: ");
                int choice;
                scanf("%d", &choice);

                if (choice == 2) {
                    out[i] = 1;
                    continue;
                }

                Card c = deck_draw(deck);
                printf("Drawn: ");
                if (c.type == NUM) printf("%d\n", c.value);
                else if (c.type == BONUS_MULT) printf("x%d\n", c.value);
                else printf("+%d\n", c.value);

                RoundStatus status = rules_apply_card(&players[i], c);

                if (status == ROUND_LOST) {
                    printf("Duplicate! %s loses the round.\n", players[i].name);
                    players[i].roundScore = 0;
                    out[i] = 1;
                } else if (status == ROUND_OVER_WIN) {
                    printf("7 different cards! %s wins the round.\n", players[i].name);
                    round_apply_bonus_winner(&players[i]);
                    round_running = 0;
                }
            }
        }

        for (int i = 0; i < nbPlayers; i++) {
            int final_score = rules_compute_round_score(&players[i]);
            players[i].totalScore += final_score;
            printf("%s: +%d points (total: %d)\n", players[i].name, final_score, players[i].totalScore);
        }

        if (rules_is_game_over(players, nbPlayers)) {
            game_over = 1;
        }
    }
}
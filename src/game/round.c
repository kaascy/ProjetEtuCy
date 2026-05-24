#include "round.h"

void round_reset_all_players(Player players[], int nbPlayers) {
    for (int i = 0; i < nbPlayers; i++) {
        player_reset_round(&players[i]);
    }
}

int round_is_over(Player players[], int nbPlayers, int *winnerIndex) {
    for (int i = 0; i < nbPlayers; i++) {
        if (player_has_seven(&players[i])) {
            *winnerIndex = i;
            return 1;
        }
    }
    return 0;
}
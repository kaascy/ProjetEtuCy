#ifndef ROUND_H
#define ROUND_H

#include "../player/player.h"

void round_reset_all_players(Player players[], int nbPlayers);
int round_is_over(Player players[], int nbPlayers, int *winnerIndex);

#endif
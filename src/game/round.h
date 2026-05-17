#ifndef ROUND_H
#define ROUND_H

#include "player.h"

void round_reset_all_players(Player players[], int nbPlayers);
int round_is_over(Player players[], int nbPlayers, int *winnerIndex);
void round_apply_bonus_winner(Player *winner);

#endif
#ifndef STATS_H
#define STATS_H

#include "../deck/structures.h"

void stats_display_best_player(const Joueur players[], int nbPlayers);
void stats_display_average_scores(const Joueur players[], int nbPlayers);
void stats_display_all_scores(const Joueur players[], int nbPlayers);

#endif

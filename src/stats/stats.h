#ifndef STATS_H
#define STATS_H
 
#include "../player/player.h"
 
void stats_display_best_player(const Player players[], int nbPlayers);
void stats_display_average_scores(const Player players[], int nbPlayers);
void stats_display_all_scores(const Player players[], int nbPlayers);
 
#endif

#ifndef SAVE_H
#define SAVE_H
 
#include "../player/player.h"
 
void save_scores_to_file(const Player players[], int nbPlayers);
void load_scores_from_file(const char *filename);
 
#endif

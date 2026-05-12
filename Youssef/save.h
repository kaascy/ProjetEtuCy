#ifndef SAVE_H
#define SAVE_H

#include "../deck/structures.h"

void save_scores_to_file(const Joueur players[], int nbPlayers);
void load_scores_from_file(const char *filename);

#endif

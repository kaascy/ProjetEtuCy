#ifndef GAME_H
#define GAME_H

#include "../deck/deck.h"
#include "../player/player.h"

void game_run(Deck *deck, Player players[], int nbPlayers);

#endif
#ifndef DISPLAY_H
#define DISPLAY_H

#include "../player/player.h"
#include "../deck/deck.h"



void display_card(Card c);
void display_player(const Player *p);
void display_game_status(const Player players[], int currentPlayer, int nbPlayers, const Deck *deck);
void display_round_summary(const Player players[], int nbPlayers);
void display_winner(const Player players[], int nbPlayers);

#endif

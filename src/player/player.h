#ifndef PLAYER_H
#define PLAYER_H

#include "../deck/deck.h"

typedef struct {
    char name[50];
    Card hand[20];
    int handSize;
    int roundScore;
    int totalScore;
    int bonusMulti;
    int bonusAdd;
} Player;

void player_init(Player *p, const char *name);
void player_add_card(Player *p, Card c);
int player_has_duplicate(Player *p, Card c);
int player_has_seven(Player *p);
void player_reset_round(Player *p);

#endif
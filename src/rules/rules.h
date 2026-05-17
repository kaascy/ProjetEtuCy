#ifndef RULES_H
#define RULES_H

#include "../player/player.h"

typedef enum {
    ROUND_CONTINUE,
    ROUND_LOST,
    ROUND_OVER_WIN
} RoundStatus;

RoundStatus rules_apply_card(Player *p, Card c);
int rules_compute_round_score(Player *p);
int rules_is_game_over(Player players[], int nbPlayers);

#endif
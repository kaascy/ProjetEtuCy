#include "player.h"
#include <string.h>

void player_init(Player *p, const char *name) {
    strcpy(p->name, name);
    p->handSize = 0;
    p->roundScore = 0;
    p->totalScore = 0;
    p->bonusMulti = 1;
    p->bonusAdd = 0;
}

void player_add_card(Player *p, Card c) {
    p->hand[p->handSize] = c;
    p->handSize++;
}

int player_has_duplicate(Player *p, Card c) {
    for (int i = 0; i < p->handSize; i++) {
        if (p->hand[i].type == NUM && p->hand[i].value == c.value) {
            return 1;
        }
    }
    return 0;
}

int player_has_seven(Player *p) {
    int seen[13] = {0};
    int count = 0;
    for (int i = 0; i < p->handSize; i++) {
        if (p->hand[i].type == NUM) {
            int v = p->hand[i].value;
            if (!seen[v]) {
                seen[v] = 1;
                count++;
            }
        }
    }
    return count >= 7;
}

void player_reset_round(Player *p) {
    p->handSize = 0;
    p->roundScore = 0;
    p->bonusMulti = 1;
    p->bonusAdd = 0;
}
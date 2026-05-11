#include "rules.h"

RoundStatus rules_apply_card(Player *p, Card c) {
    if (c.type == NUM && c.value == -1) {
        return ROUND_CONTINUE;
    }

    if (c.type == NUM) {
        if (player_has_duplicate(p, c)) {
            return ROUND_LOST;
        }
        player_add_card(p, c);
        p->roundScore += c.value;
        if (player_has_seven(p)) {
            return ROUND_OVER_WIN;
        }
    }
    else if (c.type == BONUS_MULT) {
        p->bonusMulti *= c.value;
    }
    else if (c.type == BONUS_ADD) {
        p->bonusAdd += c.value;
    }
    return ROUND_CONTINUE;
}

int rules_compute_round_score(Player *p) {
    int score = p->roundScore;
    score = score * p->bonusMulti;
    score = score + p->bonusAdd;
    return score;
}

int rules_is_game_over(Player players[], int nbPlayers) {
    for (int i = 0; i < nbPlayers; i++) {
        if (players[i].totalScore >= 200) {
            return 1;
        }
    }
    return 0;
}
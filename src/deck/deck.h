#ifndef DECK_H
#define DECK_H

#define DECK_MAX_SIZE 85

typedef enum {
NUM,
BONUS_MULT,
BONUS_ADD
} CardType;

typedef struct {
CardType type;
int      value;
} Card;

typedef struct {
Card cards[DECK_MAX_SIZE];
int  size;
} Deck;

typedef struct {
char name[50];
Card hand[20];
int  handSize;
int  roundScore;
int  totalScore;
int  bonusMult;
int  bonusAdd;
} Player;

typedef enum {
ROUND_CONTINUE,
ROUND_LOST,
ROUND_WIN
} RoundStatus;

void deck_init(Deck *deck);
void deck_shuffle(Deck *deck);
Card deck_draw(Deck *deck);
void deck_print(const Deck *deck);
int  deck_is_empty(const Deck *deck);
int  deck_size(const Deck *deck);

#endif

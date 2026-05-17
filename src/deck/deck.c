#include <stdio.h>
#include "deck.h"
#include "../utils/random.h"

void deck_init(Deck *deck) {
deck->size = 0;


for (int card_value = 0; card_value <= 12; card_value++) {
    int count = (card_value <= 1) ? 1 : card_value;

    for (int copy = 0; copy < count; copy++) {
        deck->cards[deck->size].type  = NUM;
        deck->cards[deck->size].value = card_value;
        deck->size++;
    }
}

deck->cards[deck->size].type  = BONUS_MULT;
deck->cards[deck->size].value = 2;
deck->size++;

int bonus_add_values[] = {2, 4, 6, 8, 10};
int nb_bonus_add       = 5;

for (int bonus_index = 0; bonus_index < nb_bonus_add; bonus_index++) {
    deck->cards[deck->size].type  = BONUS_ADD;
    deck->cards[deck->size].value = bonus_add_values[bonus_index];
    deck->size++;
}


}

void deck_shuffle(Deck *deck) {
for (int current_pos = deck->size - 1; current_pos > 0; current_pos--) {
int swap_pos = random_int(0, current_pos);


    Card temp_card           = deck->cards[current_pos];
    deck->cards[current_pos] = deck->cards[swap_pos];
    deck->cards[swap_pos]    = temp_card;
}


}

Card deck_draw(Deck *deck) {
Card empty_card = { NUM, -1 };


if (deck->size == 0) {
    return empty_card;
}

deck->size--;
return deck->cards[deck->size];


}

void deck_print(const Deck *deck) {
printf("=== Deck (%d cards remaining) ===\n", deck->size);


for (int position = 0; position < deck->size; position++) {
    const Card *current_card = &deck->cards[position];

    if (current_card->type == NUM) {
        printf("  [%2d] NUM        value = %d\n", position, current_card->value);
    } else if (current_card->type == BONUS_MULT) {
        printf("  [%2d] BONUS_MULT value = x%d\n", position, current_card->value);
    } else if (current_card->type == BONUS_ADD) {
        printf("  [%2d] BONUS_ADD  value = +%d\n", position, current_card->value);
    }
}


}

int deck_is_empty(const Deck *deck) {
return deck->size == 0;
}

int deck_size(const Deck *deck) {
return deck->size;
}
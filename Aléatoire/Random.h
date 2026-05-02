#include <stdlib.h>
#include <time.h>
#include "random.h"

void random_init(void) {
    srand(time(NULL));
}


int random_int(int min, int max) {
    if (min > max) return min;
    return min + rand() % (max - min + 1);
}

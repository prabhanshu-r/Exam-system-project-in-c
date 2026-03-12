#include <stdlib.h>
#include <time.h>
#include "random.h"

void initRandom() {
    srand((unsigned int)time(NULL));
}

int getRandomIndex(int total, int used[]) {
    int available = 0;

    for (int i = 0; i < total; i++) {

        if (!used[i]) available++;
    }

    if (available == 0) return -1;

    int pick = rand() % available;

    int num = 0;

    for (int i = 0; i < total; i++) {

        if (!used[i]) {
            if (num == pick) {
                return i;
            }
            num++;

        }
    }

    return -1;
}

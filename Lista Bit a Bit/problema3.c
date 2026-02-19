# include "problema3.h"

int verifica_bit (unsigned int n, unsigned short bit) {
    int state;
    state = n & ( 1 << bit);

    if (state == 0) {
        return 0;
    }
    else {
        return 1;
    }
}
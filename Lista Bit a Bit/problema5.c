#include "problema5.h"

unsigned int desliga_bit(unsigned int n, unsigned short bit) {

    int res = ~ (~ n) | (1 << bit);

    return res;
}
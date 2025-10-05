#include "problema4.h"

unsigned int ativa_bit(unsigned int n, unsigned short bit) {

    int res = n | (1 << bit);

    return res;
}

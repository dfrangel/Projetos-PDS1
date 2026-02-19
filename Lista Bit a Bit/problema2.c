#include "problema2.h"

int par_ou_impar (unsigned int n) {
    int res;

    res = (~ n) & 1;

    return res;
}
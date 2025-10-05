#include "problema3.h"

int quantidade_divisiveis (int *v, int tam, int n) {
    int counter = 0;

    for (int i = 0; i < tam; i++) {
        if (v[i] % n == 0) {
            counter++;
        }
    }

    return counter;
}
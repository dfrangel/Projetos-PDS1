#include "problema8.h"

int menor (int *v, int tam) {
    if (tam == 1) {
        return v[0];
    }

    if (v[tam - 1] < menor(v, tam - 1)) {
        return v[tam - 1];
    }
}

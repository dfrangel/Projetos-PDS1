#include "problema5.h"

int soma_vetor (int *v, int tam) {
    if (tam == 1) {
        return v[0];
    }
    return v[tam - 1] + soma_vetor(v, tam - 1);
}
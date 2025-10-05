#include "problema10.h"

int soma_acima_diagonal(int M[][10], int n) {
    int soma = 0;

    for (int i = 0; i < n; i++) {
        
        for(int j = 0; j < n; j++) {
            if (j > i) {
                soma += M[i][j];
            }
        }
    }
    return soma;
}
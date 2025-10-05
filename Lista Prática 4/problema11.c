#include "problema11.h"

int serie_divergente (int k) {
    double soma = 0, fracao; 
    int i;

    if (k <= 0) {
        return 1;
    }
    
    for (i = 1; soma <= k; i++) {

        fracao = (1.0 / i);

        soma += fracao;
    }
  
    return (i - 1);
}
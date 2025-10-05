#include "problema7.h"
#include <stdio.h>

int imprime_binario (unsigned int n) {
    unsigned int resn; 
    resn = n % 2;

    if (n == 0) {
        return 0;
    }

    n = (n - resn) / 2;
    imprime_binario(n);
    printf("%d", resn);
}
    

    

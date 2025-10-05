#include "problema7.h"

int componentes_distintas(int *v, int n, int *d) {
    int dsize = 0;

    d[0] = v[0];

    for (int i = 1; i < n; i++) {
        int repetido = 0;

        for (int j = 0; j <= dsize; j++) {
            if (v[i] == d[j]) {
                repetido ++;
                break;
            }
        }
        
        if (repetido == 0) {
            dsize++;
            d[dsize] = v[i];
        }
    }

    return dsize + 1;
}
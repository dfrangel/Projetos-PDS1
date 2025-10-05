#include "problema4.h"
#include <math.h>

double norma(double *v, int n) {
    double somaquad = 0, res;

    for (int i = 0; i < n; i++) {
        somaquad += pow(v[i], 2);
    }

    res = sqrt(somaquad);

    return res;
}
#include "problema5.h"

double produto_escalar(double *v, double *u, int n) {
    double res = 0;

    for (int i = 0; i < n; i++) {
        res += (v[i] * u[i]);
    }

    return res;
}
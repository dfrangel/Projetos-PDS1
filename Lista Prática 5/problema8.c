#include "problema8.h"

void ordena(int *v, int n) {
    int holder, i = 0;

    while (i < n) {
        for (int j = 0; j < n - 1; j++) {
            if (v[j] > v[j + 1]) {
               holder = v[j];
                v[j] = v[j + 1];
                v[j + 1] = holder;
            }
        }
    i++;
    }
}
# include "problema6.h"

int amplitude(int *v, int n) {
    int min, max, amp;

    min = v[0];
    max = v[0];

    for (int i = 1; i < n; i++) {
        if (v[i] < min) {
            min = v[i];
        }
    }

    for (int i = 1; i < n; i++) {
        if (v[i] > max) {
            max = v[i];
        }
    }
    
    amp = max - min;

    return amp;
}
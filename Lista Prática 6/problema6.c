#include <stdio.h>
#include "problema6.h"

void inverte (char *str) {
    int size = 0;
    char holder;

    for (int size = 0; str[size] != '\0'; size++) {
    }

    size -= 1;

    for (int i = 0, j = size; i < j; i++, j--) {
        holder = str[i];
        str[i] = str[j];
        str[j] = holder;
    }
}
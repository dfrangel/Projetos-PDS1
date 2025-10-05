#include <stdio.h>
#include <string.h>
#include "problema9.h"

void remove_zero (char *str, int x, int y) {
    int soma, size;
    char num[100];

    soma = x + y;

    sprintf(num, "%d", soma);

    for (int i = 0; num[i] != '\0'; i++) {
        size++;
        if (num[i] == '0') {
            for (int j = i; num[j] != '\0'; j++) {
                num[j] = num[j + 1];
            }
            i--;
        }
    }

    strncpy(str, num, size);
}
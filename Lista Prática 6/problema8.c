#include "problema8.h"

void remove_char (char *str, char letra) {
    char holder;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == letra) {
            for (int j = i; str[j] != '\0'; j++) {
                str[j] = str[j + 1];
            }
            break;
        }
    }
}

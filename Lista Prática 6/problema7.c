#include "problema7.h"

unsigned int char_count(char *frase, char letra) {
    unsigned int counter = 0;

    for (int i = 0; frase[i] != '\0'; i++) {
        if (frase[i] == letra) {
            counter++;
        }
    }

    return counter;
}
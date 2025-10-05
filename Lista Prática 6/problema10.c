#include "problema10.h"
#include <string.h>

int find(char *str, char *substr) {
    int subsize = 0, counter = 0;

    for (subsize = 0; substr[subsize] != '\0'; subsize++){
    }

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == substr[0]) {
            for (int j = i, k = 0; substr[k] != '\0'; j++, k++) {
                if (substr[k] != str[j]) {
                    break;
                }
                else {
                    counter++;
                }
                if (subsize == counter) {
                    return i;
                }
            }
        }
        counter = 0;
    }
    return -1;
}
            
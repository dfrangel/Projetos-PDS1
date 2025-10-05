#include "problema11.h"
#include <string.h>

void remove_str (char *str, char *substr) {
    char *inicio = strstr(str, substr);
    int strsize = 0, subsize = 0;
    
    for (subsize = 0; substr[subsize] != '\0'; subsize++) {
    }
    for (strsize = 0; str[strsize] != '\0'; strsize++) {
    }

    if (strstr(str, substr) == NULL) {
    }
    else {
        for (int i = 0; i < strsize; i++) {
            inicio[i] = inicio[i + subsize];
        }
    }
}
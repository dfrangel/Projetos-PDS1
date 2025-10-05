#include "problema6.h"
#include <string.h>
#include <stdio.h>

int imprime_invertida (char *s) {
    int tam = strlen(s);

    if (s[0] == '\0') {
        return 0;
    }
    
    printf("%c", s[tam - 1]);
    s[tam - 1] = '\0';
    imprime_invertida (s);
}

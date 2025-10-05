#include <stdio.h>
#include <string.h>

int main () {
    char frase[100];
    int i = 0, size;

    fgets(frase, 100, stdin);

    while (frase[i] != '\0') {
        i++;
        size = i;
    }

    size -= 1;

    for (int j = 0; j < size; j++){
        if (frase[j] == 'a') {
            printf("%d a\n", j);
        }
        else if (frase[j] == 'e') {
            printf("%d e\n", j);
        }
        else if (frase[j] == 'i') {
            printf("%d i\n", j);
        }
        else if (frase[j] == 'o') {
            printf("%d o\n", j);
        }
        else if (frase[j] == 'u') {
            printf("%d u\n", j);
        }
    }
}
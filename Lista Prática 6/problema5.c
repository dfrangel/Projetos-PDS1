#include <stdio.h>
#include <string.h>

int main () {
    char frase[100];
    int counter = 1;

    fgets(frase, 100, stdin);

    for (int i = 0; frase[i] != '\0'; i++) {
        if (frase[i] == ' ') {
            counter++;
        }
    }
    
    printf("Total: %d", counter);
}
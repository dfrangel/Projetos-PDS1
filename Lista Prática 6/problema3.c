#include <stdio.h>
#include <string.h>

int main () {
    char nome[50];
    int size;

    fgets (nome, 50, stdin);

    for (size = 0; nome[size] != '\0'; size++) {
    }

    size -= 1;

    for (int i = size; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            printf("%c", nome[j]);
        }
        
        printf("\n");
    }
}
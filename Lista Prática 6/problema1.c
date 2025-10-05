#include <stdio.h>
#include <string.h>

int main () {
    char nome[50];
    int size;

    fgets (nome, 50, stdin);

    for (size = 0; nome[size] != '\0'; size++) {
    }

    for (int i = 0; i < size; i++) {
        printf("%c\n", nome[i]);
    }
}

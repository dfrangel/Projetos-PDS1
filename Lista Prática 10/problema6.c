#include "problema6.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char** le_arquivo(char* nome_arquivo, int* num_linhas) {
    char** Vlinhas, holder;
    char* plinha;
    char linha[1024];
    int tam = 10;
    *num_linhas = 0;

    FILE *file = fopen(nome_arquivo, "r");

    Vlinhas = malloc (tam * sizeof(char*));

    while (fgets(linha, 1024, file) != NULL) {
        plinha = (char*) malloc ((strlen(linha) + 1) * sizeof(char));

        if (*num_linhas > tam) {
            tam *= 2;
            holder = realloc (Vlinhas, tam * sizeof(char*));
            Vlinhas = holder;
        }

        Vlinhas[*num_linhas] = plinha;
        *num_linhas++;
    }

    *num_linhas = tam;
    close(file);
    return Vlinhas;
}
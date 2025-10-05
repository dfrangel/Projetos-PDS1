#include <stdio.h>
#include <string.h>

unsigned int conta_palavras (FILE *file) {
    char linha[501];
    unsigned int qtd;

    while (fgets(linha, 501, file) != NULL) {
        int tam = strlen(linha);

        for (int i = 0; i < tam; i++) {
            if (linha[i] == ' ') {
                qtd++;
            }
        }
        qtd++;
    }

    return qtd;
}
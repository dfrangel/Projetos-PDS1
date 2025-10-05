#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main () {

    char filename[51], nome[51], linha[501];
    int nota, nota1, soma = 0, qtd = 0;
    float media = 0;
    char *p;

    scanf("%s", filename);

    FILE *file = fopen(filename, "r");

    while (fgets(linha, 501, file) != NULL) {
        
        strcpy(nome, strtok(linha, " "));

        while ((p = strtok(NULL, " ")) != NULL) {
            
            nota = atoi(p);
            soma += nota;
            qtd++;
        }
        
        media = (float) soma / qtd;

        printf("%s - %.2f\n" , nome, media);

        soma = 0;
        qtd = 0;
    }

    fclose(file);

    return 0;
}
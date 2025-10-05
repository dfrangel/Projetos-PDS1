#include "problema1.h"
#include <stdio.h>
#include <stdlib.h>

int *cria_vetor_ordenado(char *nome_arquivo, int *tam) {
    int n, holder;
    int *v;

    FILE *file = fopen(nome_arquivo, "r");

    fscanf(file, "%d", &n); 

    //Aloca um espaço de memória suficiente para um vetor de int de n posições e o
    //armazena em v
   v = (int *) malloc(n * sizeof(int));

    //Lê número por número e os armazena no vetor v
    for (int i = 0; i < n; i++) {
        fscanf(file, "%d", &v[i]);
    }
    //O & em &v[i] se dá pois o fscanf lerá um inteiro e tem que armazená-lo no
    //endereço de memória apontado pela posição v[i] e não na posição v[i]

    //Organiza o vetor v em ordem crescente
    for (int j = 0; j < n; j++) {
        for (int k = 1; k < n; k++) {
            if (v[k] < v[k - 1]) {
                holder = v[k];
                v[k] = v[k - 1];
                v[k - 1] = holder;
            }
        }
    }

    fclose(file);

    *tam = n;

    return v;
}

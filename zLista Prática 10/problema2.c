#include "problema2.h"
#include <stdio.h>
#include <stdlib.h>

int **cria_matriz(char *nome_arquivo, int *linhas, int *colunas) {
    //M é inicializado como um vetor de ponteiros
    int **M;
    int l, c;

    FILE *file = fopen(nome_arquivo, "r");

    fscanf(file, "%d %d", &l, &c);

    //Aloca memória para um vetor de ponteiros M de tamanho l
    M = (int **) malloc(l * sizeof(int*));

    //Faz com que cada posição do vetor M aja aponte para um vetor de inteiros
    //Assim, cada posição de M age como uma "linha" armazenando um vetor de inteiros
    for (int i = 0; i < l; i++) {
        //Aloca memória para um cada posição de M receber 
        //um vetor de inteiros de tamanho c
        M[i] = (int *) malloc (c * sizeof(int));
    }

    //Para cada linha (ponteiro para vetor) o código passa por todas
    //as posições desse vetor (colunas) e armazena em seus endereços de memória
    //o inteiro lido do arquivo
    for (int i = 0; i < l; i ++) {
        for (int j = 0; j < c; j++) {
            fscanf(file, "%d", &M[i][j]);
        }
    }

    *linhas = l;
    *colunas = c;

    return M;
}
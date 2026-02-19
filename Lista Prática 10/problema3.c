#include "problema3.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct Produto* cria_produto(int codigo, char* nome, int quantidade, float preco) {
    struct Produto* produto;

    //Aloca memória para os campos do produto apontado pelo ponteiro "produto"
    produto = (struct Produto*) malloc (sizeof(struct Produto));

    produto->codigo = codigo;

    //Ainda não havia sido alocada memória para armazenar a string nome, apenas o
    //ponteiro para a string
    produto->nome = malloc((strlen(nome) + 1) * sizeof(char));
    strcpy(produto->nome, nome);

    produto->quantidade = quantidade;
    produto->preco = preco;

    return produto;
}

float calcula_valor_total(struct Produto* estoque[], int qtd) {
    float total = 0;

    for (int i = 0; i < qtd; i++) {
        total += estoque[i]->quantidade * estoque[i]->preco;
    }

    return total;
}
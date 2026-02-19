#include "problema4.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Produto* cria_produto(char *nome, float preco) {
    struct Produto* produto;

    //Aloca memória para uma variável struct Produto
    produto = (struct Produto*) malloc (sizeof(struct Produto));

    //Aloca memória para a string apontada por nome
    produto->nome = malloc ((strlen(nome) + 1) * sizeof(char));
    strcpy(produto->nome, nome);

    produto->preco = preco;

    return produto;
}

struct Pedido* cria_pedido(int quant_produtos) {
    struct Pedido* pedido;

    //Aloca memória para struct Pedido
    pedido = (struct Pedido*) malloc (sizeof(struct Pedido));

    pedido->quantidade = 0;

    //Aloca memória para o vetor de produtos apontado por "produtos"
    pedido->produtos = (struct Produto**) malloc(quant_produtos * sizeof(struct Produto*));

    return pedido;
}

void adiciona_produto_pedido(struct Pedido *pedido, struct Produto *produto) {
    struct Produto* nproduto;

    //Inicializa um novo produto com os mesmos valores que a referência passada
    nproduto = cria_produto(produto->nome, produto->preco);

    //Armazena esse novo produto na última posição do vetor de produtos em pedido
    pedido->produtos[pedido->quantidade] = nproduto;

    pedido->quantidade++;
}

float total_pedido(struct Pedido *pedido) {
    float total = 0;

    for (int i = 0; i < pedido->quantidade; i++) {
        total += pedido->produtos[i]->preco;
    }

    return total;
}
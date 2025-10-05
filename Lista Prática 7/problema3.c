#include "problema3.h"
#include <string.h>

struct Produto cria_produto(char *nome, float preco) {
    struct Produto novoproduto;
    char *novonome[40];

    strcpy(novonome, nome);

    strcpy(novoproduto.nome, novonome);

    novoproduto.preco = preco;
    
    return novoproduto;
};

struct Pedido cria_pedido() {
    struct Pedido novopedido;

    novopedido.quantidade = 0;

    return novopedido;
};

void adiciona_produto_pedido(struct Pedido *pedido, struct Produto produto) {

    pedido->produtos[pedido->quantidade] = produto;
    pedido->quantidade++;

}

float total_pedido(struct Pedido pedido) {
    float total = 0;

    for (int i = 0; i < pedido.quantidade; i++) {
        
        total += pedido.produtos[i].preco;
    }

    return total;
}


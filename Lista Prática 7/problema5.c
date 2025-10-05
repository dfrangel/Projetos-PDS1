#include "problema5.h"

void ordena_por_preco (struct Pedido *pedido) {
    struct Produto holder;

    for (int i = 0; i < pedido->quantidade; i++) {
        
        for (int j = 1; j < pedido->quantidade; j++) {
            
            if (pedido->produtos[j].preco < pedido->produtos[j - 1].preco) {
                
                holder = pedido->produtos[j - 1];
                pedido->produtos[j - 1] = pedido->produtos[j];
                pedido->produtos[j] = holder;
            }
        }
    }
}
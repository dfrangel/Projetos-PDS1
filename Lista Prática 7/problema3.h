struct Produto {
    char nome[40];
    float preco;
};

struct Pedido {
    struct Produto produtos[100];
    int quantidade;
};

struct Produto cria_produto(char *nome, float preco);

struct Pedido cria_pedido();

void adiciona_produto_pedido(struct Pedido *pedido, struct Produto produto);

float total_pedido(struct Pedido pedido);

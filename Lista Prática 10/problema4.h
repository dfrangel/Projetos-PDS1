struct Produto {
    char *nome;
    float preco;
};

struct Pedido {
    struct Produto** produtos;
    int quantidade;
};

struct Produto* cria_produto(char *, float);

struct Pedido* cria_pedido(int);

void adiciona_produto_pedido (struct Pedido*, struct Produto*);

float total_pedido(struct Pedido*);
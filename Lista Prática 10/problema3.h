struct Produto {
    int codigo;
    char *nome;
    int quantidade;
    float preco;
};

struct Produto* cria_produto(int ,char *, int, float);

float calcula_valor_total(struct Produto* estoque[], int);
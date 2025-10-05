typedef struct {
    int ataque;
    int defesa;
    int pontos_vida;
    int id_guerreiro;
} Guerreiro;

void define_seed (int);

int rola_dados ();

void cria_guerreiro (Guerreiro *guerreiro);

void ataca (Guerreiro *guerreiro1, Guerreiro *guerreiro2);

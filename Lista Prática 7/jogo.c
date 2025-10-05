#include "jogo.h"
#include <stdlib.h>

void define_seed (int seed) {
    srand(seed);
}

int rola_dados () {
    int res1 = 0, res2 = 0, res3 = 0;

    res1 = ((rand() % (6 - 1 + 1)) + 1);
    res2 = ((rand() % (6 - 1 + 1)) + 1);
    res3 = ((rand() % (6 - 1 + 1)) + 1);

    return (res1 + res2 + res3);
}

void cria_guerreiro(Guerreiro *guerreiro) {

    guerreiro->ataque = rola_dados();
    guerreiro->defesa = rola_dados();
    guerreiro->pontos_vida = rola_dados() + rola_dados() + rola_dados();
}

void ataca (Guerreiro *guerreiro1, Guerreiro *guerreiro2) {
    int golpe, dano, escudo;

    golpe = rola_dados() + guerreiro1->ataque;

    escudo = rola_dados() + guerreiro2->defesa;

    dano = golpe - escudo;

    if (dano > 0) {

        guerreiro2->pontos_vida -= dano;

        if (guerreiro2->pontos_vida < 0) {
            guerreiro2->pontos_vida = 0;
        }
    }
}
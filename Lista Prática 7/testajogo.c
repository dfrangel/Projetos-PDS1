#include "jogo.h"
#include <stdlib.h>
#include <stdio.h>

int main () {
    int seed;

    printf("Seed:\n");
    scanf("%d", &seed);

    define_seed(seed);

    Guerreiro guerreiro1;
    Guerreiro *guerreiro1p;
    guerreiro1p = &guerreiro1;

    guerreiro1.id_guerreiro = 1;
    cria_guerreiro(guerreiro1p);
    
    Guerreiro guerreiro2;
    Guerreiro *guerreiro2p;
    guerreiro2p = &guerreiro2;

    guerreiro2.id_guerreiro = 2;
    cria_guerreiro(guerreiro2p);


    while (1 == 1) {

        ataca(guerreiro1p, guerreiro2p);

        if (guerreiro2p->pontos_vida == 0) {
            printf("Vencedor: 1\n");
            printf("Pontos de vida restantes: %d", guerreiro1p->pontos_vida);
            return 0;
        }

        ataca(guerreiro2p, guerreiro1p);

        if (guerreiro1p->pontos_vida == 0) {
            printf("Vencedor: 2\n");
            printf("Pontos de vida restantes: %d", guerreiro2p->pontos_vida);
            return 0;
        }
    }
}
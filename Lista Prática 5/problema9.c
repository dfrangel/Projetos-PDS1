#include "problema9.h"

int mais_frequente(int *v, int n, int *end_frequencia) {
    int e; //Elemento que mais se repete
    
    e = v[0];

    int maisfrequente = 0; //Frequencia do mais frequente

    //Passar por todos os elementos de v
    for (int i = 0; i < n; i++) {
        int repetido = 0; //Frequencia do elemento atual (v[i])

        //Comparar o elementos atual de v com todos os outros
        for (int j = 0; j < n; j++) {
            if (v[i] == v[j]) {
                repetido++;
            }
        }

        if (repetido > maisfrequente) {
            maisfrequente = repetido;
            e = v[i];
            *end_frequencia = maisfrequente;
        }
    }
    return e;
}
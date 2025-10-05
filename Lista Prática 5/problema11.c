#include <stdio.h>

int main() {
    int L, C;

    printf("Linhas: \n");
    scanf("%d", &L);

    printf("Colunas: \n");
    scanf("%d", &C);

    int M[L][C];

//Preencher a Matriz
    for (int l = 0; l < L; l++) {
        for(int c = 0; c < C; c++) {
            scanf("%d", &M[l][c]);
        }
    }

//Programa deve encontrar alvos (elementos iguais ao seu anterior e proximo)
    int NAlvosH = 0;
    int NAlvosV = 0;

//Procurar alvos na horizontal (mesmo L / diferentes C)
    for (int l = 0; l < L; l++) {
        for (int c = 1; c < (C - 1); c++) {
            if (M[l][c] == M[l][c - 1] && M[l][c] == M[l][c + 1]) {
                NAlvosH++;
            }
        }
    }
   
//Procurar alvos na vertical (diferentes L / mesmo C)
    for (int c = 0; c < C; c++) {
        for(int l = 1; l < (L - 1); l++) {
            if (M[l][c] == M[l - 1][c] && M[l][c] == M[l + 1][c]) {
                NAlvosV++;
            }
        }
    }

//Gerar um vetor com tamanho suficiente para armazenar as coordenadas dos alvos
    int CrdAlvosH[NAlvosH * 2];
    int CrdAlvosV[NAlvosV * 2];
    int PosCrdAlvosH = 0, PosCrdAlvosV = 0;
//Armazenar coordenadas dos alvos no vetor CrdAlvos

//Armazenar alvos na horizontal (mesmo L / diferentes C)
    for (int l = 0; l < L; l++) {
        for (int c = 1; c < (C - 1); c++) {
            if (M[l][c] == M[l][c - 1] && M[l][c] == M[l][c + 1]) {
                CrdAlvosH[PosCrdAlvosH] = l;
                CrdAlvosH[PosCrdAlvosH + 1] = c;
                PosCrdAlvosH += 2;
            }
        }
    }

    for (int c = 0; c < C; c++) {
        for (int l = 1; l < (L - 1); l++) {
            if (M[l][c] == M[l - 1][c] && M[l][c] == M[l + 1][c]) {
                CrdAlvosV[PosCrdAlvosV] = l;
                CrdAlvosV[PosCrdAlvosV + 1] = c;
                PosCrdAlvosV += 2;
            }
        }
    }

//Zerar alvos e vizinhos

//Zerar alvos na horizontal (mesmo L / diferentes C)
   for (int i = 0; i < NAlvosH * 2; i += 2) {
        M[CrdAlvosH[i]][CrdAlvosH[i + 1] - 1] = 0;
        M[CrdAlvosH[i]][CrdAlvosH[i + 1]] = 0;
        M[CrdAlvosH[i]][CrdAlvosH[i + 1] + 1] = 0;
   }

//Zerar alvos na vertical (diferentes L / mesmo C)
   for (int i = 0; i < NAlvosV * 2; i += 2) {
    M[CrdAlvosV[i] - 1][CrdAlvosV[i + 1]] = 0;
    M[CrdAlvosV[i]][CrdAlvosV[i + 1]] = 0;
    M[CrdAlvosV[i] + 1][CrdAlvosV[i + 1]] = 0;
}

    for (int l = 0; l < L; l++) {
        for (int c = 0; c < C; c++) {
            printf("%d ", M[l][c]);
        }
        printf("\n");
    }
}
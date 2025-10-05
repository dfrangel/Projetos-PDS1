#include <stdio.h>

int main() {
    int L, C, holder;

    printf("Linhas: \n");
    scanf("%d", &L);

    printf("Colunas: \n");
    scanf("%d", &C);

    int M[L][C];

//Preencher a Matriz
    for (int l = 0; l < L; l++) {
        for (int c = 0; c < C; c++) {
            scanf("%d", &M[l][c]);
        }
    }

//"Puxar" os zeros de cada coluna para cima
    for (int n = 0; n < L; n++) {
        for (int c = 0; c < C; c++) {
            for (int l = 1; l < L; l++) {
                if (M[l][c] == 0) {
                    holder = M[l][c];
                    M[l][c] = M[l - 1][c];
                    M[l - 1][c] = holder;
                }
            }
        }
    }

    for (int l = 0; l < L; l++) {
        for (int c = 0; c < C; c++) {
            printf("%d ", M[l][c]);
        }
        printf("\n");
    }
}
#include <stdio.h>
#include <math.h>

int main() {
    float vi, txj, vf;
    int tempo;

    printf("Digite o valor do investimento inicial: ");
    scanf("%f", &vi);

    printf("Digite a taxa de juros anual: ");
    scanf("%f", &txj);

    printf("Digite o periodo do investimento em anos: ");
    scanf("%d", &tempo);

    vf = vi * pow((1 + (txj * 0.01)), tempo);

    printf("Valor futuro: %.2f", vf);
}
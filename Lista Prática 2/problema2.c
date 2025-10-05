#include <stdio.h>

int main() {
    int vreg, vmax;

    printf("Digite o valor da velocidade maxima: ");
    scanf("%d", &vmax);

    printf("Digite o valor da velocidade registrada: ");
    scanf("%d", &vreg);

    if (vreg <= vmax) {
        printf("Sem Infracao");
    }
    else if (vreg <= 1.2 * vmax) {
        printf("Infracao Media\n");
    }
    else if (vreg <= 1.5 * vmax) {
        printf("Infracao Grave\n");
    }
    else if (vreg > 1.5 * vmax) {
        printf("Infracao Gravissima\n");
    }

    return 0;
}
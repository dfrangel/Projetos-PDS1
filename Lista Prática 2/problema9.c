#include <stdio.h>

int main() {

    int qtsol, qtsolcent, qtsolcinq, qtsolvint, qtsoldez;

    printf("Digite valor: ");
    scanf("%d", &qtsol);

    if (qtsol % 10 != 0) {
        printf("Valor invalido");
    }
    
    qtsolcent = qtsol / 100;

    qtsolcinq = (qtsol % 100) / 50;

    qtsolvint = ((qtsol % 100) % 50) / 20;
    
    qtsoldez = (((qtsol % 100) % 50) % 20) / 10;

    if (qtsolcent != 0) {
        printf("%d nota(s) de 100\n", qtsolcent);
    }
    if (qtsolcinq != 0) {
        printf("%d nota(s) de 50\n", qtsolcinq);
    }
    if (qtsolvint != 0) {
        printf("%d nota(s) de 20\n", qtsolvint);
    }
    if (qtsoldez != 0) {
        printf("%d nota(s) de 10\n", qtsoldez);
    }

    return 0;
}
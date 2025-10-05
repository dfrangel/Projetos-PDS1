#include <stdio.h>
#include <math.h>


int main () {
    int a, b, c;
    float delta, bneg, raizun, raiz1, raiz2;

    printf("Digite os coeficientes: ");
    scanf("%d, %d, %d", &a, &b, &c);

    if (a == 0) {
        printf("Nao e uma equacao quadratica\n");
    }
    
    else {

        delta = pow(b, 2) - (4 * (a * c));

        bneg = -b;

        if (delta < 0) {
             printf("Nao existe raiz real\n");
          }

        else if (delta == 0) {
            printf("Raiz unica\n");

            raizun = bneg / (2 * (float) a);

            printf("Raiz: %.2f", raizun);
        }
        else {
            raiz1 = (bneg + sqrt(delta)) / (2 * (float) a);
            raiz2 = (bneg - sqrt(delta)) / (2 * (float) a);

            printf("Raiz 1: %.2f\n", raiz1);
            printf("Raiz 2: %.2f\n", raiz2);
        }
    }
    return 0;
}
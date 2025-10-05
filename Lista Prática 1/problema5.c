#include <stdio.h>
#include <math.h>

int main() {
    int a, b, c, res;

    printf("Digite tres inteiros: ");
    scanf("%d, %d, %d", &a, &b, &c);

    res = pow(a, 2) + pow(b, 2) + pow(c, 2);

    printf("Resultado: %d", res);
}
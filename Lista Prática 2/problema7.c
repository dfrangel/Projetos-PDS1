#include <stdio.h>

int main () {
    int x, y, z;

    printf("Digite os tres lados: ");
    scanf("%d, %d, %d", &x, &y, &z);

    if (x < y + z && y < x + z && z < x + y) {
        if (x == y && y == z) {
            printf("Triangulo Equilatero");
        }
        else if ((x == y && x != z) || (x == z && x != y) || (y == z && y != x)) {
            printf("Triangulo Isosceles");
        }
        else {
            printf("Triangulo Escaleno");
        }
    } 
    else {
        printf("Nao e um triangulo");
    }

    return 0;
}
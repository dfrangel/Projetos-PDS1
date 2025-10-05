#include <stdio.h>

int main() {
    int num, mil, cent, dez, unid;

    printf("Digite um inteiro de 4 algarismos: ");
    scanf("%d", &num);

    unid = num % 10;
    dez = (num % 100 - unid) /10;
    cent = (num % 1000 - (num % 100 - unid)) / 100;
    mil = (num - (num % 1000)) / 1000;

    printf("Valor invertido: %d%d%d%d", unid, dez, cent, mil);

}
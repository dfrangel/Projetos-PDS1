#include <stdio.h>

int main (){
    float custi, custf, impost, comiss;

    printf("Digite o custo de fabrica: ");
    scanf("%f", &custi);

    if (custi <= 12000) {
        comiss = custi * 0.05;
        impost = 0;
    }
    else if (custi <= 25000) {
        comiss = custi * 0.1;
        impost = custi * 0.15;
    }
    else if (custi > 25000) {
        comiss = custi * 0.15;
        impost = custi * 0.2;
    }

    custf = custi + comiss + impost;

    custf = custf * 100;
    custf = (int) custf;
    custf = (float) custf / 100;

    printf("Custo total: %.2f\n", custf);
}
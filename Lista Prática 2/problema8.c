#include <stdio.h>

int main() {
    double valhrs, salbrut, salliq, inss, imprend, fgts, totdesc;
    int tothrs;

    printf("Digite o valor da hora de trabalho: ");
    scanf("%lf", &valhrs);

    printf("Digitar a quantidade de horas trabalhadas no mes: ");
    scanf("%d", &tothrs);

    salbrut = valhrs * tothrs;

    //IR
    if (salbrut <= 900) {
        imprend == 0;
    }
    else if (salbrut <= 1500) {
        imprend = 0.05 * salbrut;
    }
    else if (salbrut <= 2500) {
        imprend = 0.1 * salbrut;
    }
    else if (salbrut > 2500) {
        imprend = 0.2 * salbrut;
    }
    
    inss = 0.1 * salbrut;

    fgts = 0.11 * salbrut;

    totdesc = inss + imprend;

    salliq = salbrut - totdesc;

    printf("Salario bruto: R$ %.2lf\n", salbrut);
    printf("IR: R$ %.2lf\n", imprend);
    printf("INSS: R$ %.2lf\n", inss);
    printf("FGTS: R$ %.2lf\n", fgts);
    printf("Total de descontos: R$ %.2lf\n", totdesc);
    printf("Salario liquido: R$ %.2lf\n", salliq);

    return 0;
}
#include <stdio.h>

int main() {
    float val, valdesc, valpar, comvaldesc, comvalpar;

    printf("Digite o valor da compra: ");
    scanf("%f", &val);

    valdesc = val * 0.9;
    valpar = val / 6;
    comvaldesc = valdesc * 0.05;
    comvalpar = val * 0.05;

    printf("Valor com desconto: %.2f\n", valdesc);
    printf("Valor da parcela: %.2f\n", valpar);
    printf("Comissao do vendedor (a vista): %.2f\n", comvaldesc);
    printf("Comissao do vendedor (parcelado): %.2f\n", comvalpar);

}
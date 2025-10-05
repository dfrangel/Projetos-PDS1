#include <stdio.h>

int main(){
    float sali, salf, aumento;

    printf("Digite o valor do salario: ");
    scanf("%f", &sali);
    
    if (sali <= 280) {
        salf = sali * 1.2;
    }
    else if (sali <= 700) {
        salf = sali * 1.15;
    }
    else if (sali <= 1500) {
        salf = sali * 1.1;
    }
    else if (sali > 1500) {
        salf = sali * 1.05;
    }
    
    aumento = salf - sali;

    printf("Valor do aumento: %.2f\n", aumento);
    printf("Novo salario: %.2f\n", salf);
}
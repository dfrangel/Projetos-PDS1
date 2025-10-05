#include <stdio.h>

int main() {
    int dia, mes, ano;

    printf("Digite a data: ");
    scanf("%d/%d/%d", &dia, &mes, &ano);

    // Caso de fevereiro
    if (mes == 2) {
        if((ano % 4 == 0 && ano % 100 != 0) || ano % 400 == 0) {
            if (dia <= 29) {
                printf("Data valida");
    	    }
            else {
                printf("Data invalida");
            }
        }
        else {
            if (dia <= 28) {
                printf("Data valida"); 
            }
            else {
            printf("Data invalida");
            }
        }
}

    //Verificar se é Abr, Jun, Set ou Nov que tem 30 dias
    if (mes == 4 || mes == 6 || mes == 9 || mes == 11) {
        if (dia <= 30) {
            printf("Data valida");
        }
        else {
            printf("Data invalida");
        }
    }

    //Verificar se é Jan, Mar, Mai, Jul, Ago, Out ou Dez que tem 31 dias
    if (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12) {
        if (dia > 31) {
            printf("Data invalida");
    }
        else {
            printf("Data valida");
        }
    }

    if (mes > 12) {
        printf("Data invalida");
    }
}
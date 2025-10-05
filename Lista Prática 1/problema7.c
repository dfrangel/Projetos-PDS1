#include <stdio.h>

int main(){
    float Ped, Joa, Mar, Calctot, mult;
    int Tot;

    printf("Digite o valor que o Pedro apostou: ");
    scanf("%f", &Ped);

    printf("Digite o valor que o Joao apostou: ");
    scanf("%f", &Joa);

    printf("Digite o valor que a Marcela apostou: ");
    scanf("%f", &Mar);

    printf("Digite o valor do premio: ");
    scanf("%d", &Tot);

    Calctot = Ped + Joa + Mar;

    mult = Tot / Calctot;

    Ped = Ped * mult;
    Joa = Joa * mult;
    Mar = Mar * mult;

    printf("Premio do Pedro: %.2f\n", Ped);
    printf("Premio do Joao: %.2f\n", Joa);
    printf("Premio da Marcela: %.2f\n", Mar);

}
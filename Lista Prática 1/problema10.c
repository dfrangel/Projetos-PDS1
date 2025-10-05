#include <stdio.h>

int main () {
    float seg, floatmin;
    int intmin, hrs, minfin;

    printf("Digite o valor do tempo em minutos: ");
    scanf("%f", &floatmin);

    intmin = (int) floatmin;

    hrs = intmin / 60;
    minfin = intmin % 60;
    seg = (floatmin - intmin) * 60;

    printf("Valor convertido: %d h %d min %.1f s", hrs, minfin, seg);
    
}
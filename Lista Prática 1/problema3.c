#include <stdio.h>
#include <math.h>

int main() {
     int seg, min, hrs, restomin, restoseg;

     printf("Digite o valor do tempo em segundos: ");
     scanf("%d", &seg);

    hrs = seg / 3600;
    restomin = seg % 3600;
    min = restomin / 60;
    restoseg = restomin % 60;
    
    printf("Valor convertido: %d h %d min %d s", hrs, min, restoseg);


}
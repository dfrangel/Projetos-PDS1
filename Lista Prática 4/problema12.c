# include <stdio.h>
# include "problema12.h"

void decompoe (int n) {
    int i = 2;
    int teste = n;

    printf("%d = ", n);

    while (n > 1) {
            
        if (n == i) {
            printf("%d", i);
            break;
        }
        else if (n % i == 0) {
            printf("%d*", i);
            n = n / i;
        }
        else {
            i++;
            continue;
        }
    }
    return 0;
}

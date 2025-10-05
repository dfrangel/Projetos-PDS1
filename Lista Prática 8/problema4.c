#include <stdio.h>
#include <string.h>

int main () {

    char filename[51];
    int n, qtd = 0, ndiv;

    scanf("%s", filename);

    FILE *file = fopen(filename, "r");

    while (fscanf(file, "%d", &n) == 1) {  
        
        if (n == 2) {
            qtd++;
        }

        for (int i = 2; i < n; i++) {
            if (n % i == 0) {
                break;
            }
            else if (i == n - 1) {
                qtd++;
            }
        }
    }
    
    printf("%d", qtd);

    fclose(file);

    return 0;
}
            
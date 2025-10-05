#include <stdio.h>
#include <string.h>

int main () {

    char *filename = "compras.txt";
    char data[11], datax[11];
    int id;
    float valor, total = 0;

    scanf("%s", data);

    FILE *file = fopen(filename, "r");

    while (fscanf(file, "%d %s %f", &id, datax, &valor) == 3) {
        if (strcmp(data, datax) == 0) {
            total += valor;
        }
    }

    printf("Total: %.2f", total);

    fclose(file);

    return 0;
}

#include <stdio.h>
#include <string.h>

int main() {

    int tamstr;
    char filename[51], line[501], maiorlinha[501];

    scanf("%s", filename);

    FILE *file = fopen(filename, "r");

    while (fgets(line, 501, file) != NULL) {
        if (strlen(line) > strlen(maiorlinha)) {
            strcpy(maiorlinha, line);
        }
    }

    fclose(file);

    tamstr = strlen(maiorlinha) - 1;
    //Remover o caracter de quebra de linha \n

    printf("%s", maiorlinha);
    printf("%d", tamstr);
}
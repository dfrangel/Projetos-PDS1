#include <stdio.h>
#include <string.h>

int main () {


    char filename[51], linha[100], nome[51];
    int n1, n2, n3, n4, linecounter = 0;
    float media;

    scanf("%s", filename);

    FILE *file = fopen(filename, "r");

    while (fscanf(file, "%s %d %d %d %d", nome, &n1, &n2, &n3, &n4) == 5) {
        
        media = (float)(n1 + n2 + n3 + n4) / 4;

        if (media >= 60.0) {
            printf("%s - %.2f\n", nome, media);
        }
    }
    
    fclose(file);

    return 0;
}

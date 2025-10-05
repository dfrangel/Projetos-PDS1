#include <stdio.h>
#include <string.h>

int main () {

    char filename[51];
    int n, l, c, x;

    scanf("%s", filename);

    FILE *file = fopen (filename, "r");

    fscanf(file, "%d", &n);

    fscanf(file, "%d %d", &l, &c);

    int MF[l][c];

    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            MF[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < l; j++) {
            for (int k = 0; k < c; k++) {
                fscanf(file, "%d", &x);
                MF[j][k] += x;
            }
        }

        
    }

    for (int a = 0; a < l; a++) {
            for (int b = 0; b < c; b++) {
                printf("%d ", MF[a][b]);
            }
            printf("\n");
        }
    fclose(file);

    return 0;
}

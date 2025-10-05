#include <stdio.h>
#include <string.h>

int main () {

    int dia, mes, ano, mdia = 0, mmes = 0, mano = 0;
    char filename[51], data[11];

    scanf("%s", filename);

    FILE *file = fopen(filename, "r");

    while (fgets(data, 11, file)  != NULL) {
        fscanf(file, "%d/%d/%d", &dia, &mes, &ano);
            if (ano > mano) {
                mdia = dia;
                mmes = mes;
                mano = ano;
            }
            if (ano == mano) {
                if (mes > mmes) {
                    mdia = dia;
                    mmes = mes;
                    mano = ano;
                }
                else if (mes == mmes) {
                    if (dia >= mdia) {
                        mdia = dia;
                        mmes = mes;
                        mano = ano;
                    }
                }
            }
        }

    printf("%02d/%02d/%d", mdia, mmes, mano);

    fclose(file);

    return 0;
}

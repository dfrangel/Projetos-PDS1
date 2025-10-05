#include "problema13.h"
#include <string.h>
#include <stdlib.h>

int data_valida (char *str) {
    int dia, mes, ano;
    char strdia[3]; 
    char strmes[3];
    char strano[5];

    for (int i = 0; str[i] != '/'; i++) {
        strdia[i] = str[i];
    }
    for (int i = 0; str[i + 3] != '/'; i++) {
        strmes[i] = str[i + 3];
    }
    for (int i = 0; str[i + 6] != '\0'; i++) {
        strano[i] = str[i + 6];
    }

    strdia[2] = '\0';
    strmes[2] = '\0';
    strano[4] = '\0';

    dia = atoi(strdia);
    mes = atoi(strmes);
    ano = atoi(strano);

    if (mes == 2) {
        if((ano % 4 == 0 && ano % 100 != 0) || ano % 400 == 0) {
            if (dia <= 29) {
                return 1;
    	    }
            else {
                return 0;
            }
        }
        else {
            if (dia <= 28) {
                return 1; 
            }
            else {
            return 0;
            }
        }
    }
    if (mes == 4 || mes == 6 || mes == 9 || mes == 11) {
        if (dia <= 30) {
            return 1;
        }
        else {
            return 0;
        }
    }
    if (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12) {
        if (dia > 31) {
            return 0;
    }
        else {
            return 1;
        }
    }
    if (mes > 12) {
        return 0;
    }
}
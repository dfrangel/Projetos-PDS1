#include "problema12.h"
#include <string.h>
#include <ctype.h>

void gera_login (char *nome, char *login) {
    int nomesize = 0, nome1size = 0, loginnext = 0;
    char *sobrenome = strrchr(nome, 32);

    for (nomesize = 0; nome[nomesize] != '\0'; nomesize++) {
    }
    for (nome1size = 0; nome[nome1size] != ' '; nome1size++) {
    }
    
    for (int i = 0; i < nome1size; i++) {
        login[i] = nome[i];
        loginnext++;
    }

    for (int i = 0; i < nomesize; i++) {
        if (nome[i] == ' ') {
            login[loginnext] = nome[i + 1];
            loginnext++;
        }
    }
    
    for (int i = 2; sobrenome[i] != '\0'; i++) {
        login[loginnext] = sobrenome[i];
        loginnext++;
    }

    login[loginnext] = '\0';
    
    for (int i = 0; i < loginnext; i++) {
        login[i] = toupper(login[i]);
    }
}
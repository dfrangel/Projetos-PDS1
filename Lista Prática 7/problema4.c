#include "problema4.h"
#include <string.h>

Aluno cria_aluno (char *nome, float nota) {
    Aluno novoaluno;

    strcpy(novoaluno.nome, nome);

    novoaluno.nota = nota;

    return novoaluno;
};

Turma cria_turma () {
    Turma novaturma;

    novaturma.quantidade = 0;

    return novaturma;
};

void adiciona_aluno_turma (Turma *turma, Aluno aluno) {
    turma->alunos[turma->quantidade] = aluno;
    turma->quantidade++;
};

float media_turma (Turma turma) {
    float soma = 0, media = 0;

    for (int i = 0; i < turma.quantidade; i++) {
        soma += turma.alunos[i].nota;
    }

    media = soma / turma.quantidade;

    return media;
}
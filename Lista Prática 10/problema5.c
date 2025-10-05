#include "problema5.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

Aluno* cria_aluno(char* nome, float nota) {
    Aluno* aluno;

    //aloco memoria para aluno
    aluno = (Aluno*) malloc (sizeof(Aluno));

    //aluno->nome apontar para um espaço de memória alocada do tamanho suficiente
    aluno->nome = (char*) malloc ((strlen(nome) + 1) * sizeof(char));
    strcpy(aluno->nome, nome);

    aluno->nota = nota;

    return aluno;
}

Turma* cria_turma(int quant_alunos) {
    Turma* turma;
    
    //aloco memória para armazenar os campos de turma
    turma = (Turma*) malloc (sizeof(Turma));

    //turma->alunos aponta para uma região de memória com tamanho suficiente para um vetor de ponteiros para alunos
    turma->alunos = (Aluno**) malloc (quant_alunos * (sizeof(Aluno*)));

    turma->quantidade = 0;

    return turma;
}

void adiciona_aluno_turma(Turma* turma, Aluno* aluno) {
    
    turma->alunos[turma->quantidade] = cria_aluno(aluno->nome, aluno->nota);
    turma->quantidade++;
}

float media_turma (Turma *turma) {
    float soma = 0, media;

    for (int i = 0; i < turma->quantidade; i++) {
        soma += turma->alunos[i]->nota;
    }

    media = soma / turma->quantidade;

    return media;
}
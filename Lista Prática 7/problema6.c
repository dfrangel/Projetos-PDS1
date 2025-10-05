#include "problema6.h"

Aluno maior_nota (Turma *turma) {
    Aluno maior = turma->alunos[0];

    for (int i = 1; i < turma->quantidade; i++) {
        
        if (turma->alunos[i].nota > maior.nota) {
            maior = turma->alunos[i];
        }
    }

    return maior;
}
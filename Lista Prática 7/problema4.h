typedef struct {
    char nome[40];
    float nota;
} Aluno;

typedef struct {
    Aluno alunos[100];
    int quantidade;
} Turma;

Aluno cria_aluno (char *, float);

Turma cria_turma ();

void adiciona_aluno_turma (Turma *, Aluno);

float media_turma (Turma);

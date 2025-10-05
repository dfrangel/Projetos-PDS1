typedef struct Aluno {
    char* nome;
    float nota;
} Aluno;

typedef struct Turma {
    struct Aluno** alunos;
    int quantidade;
} Turma;

struct Aluno* cria_aluno(char *, float);

struct Turma* cria_turma(int);

void adiciona_aluno_turma(struct Turma*, struct Aluno*);

float media_turma(struct Turma *);
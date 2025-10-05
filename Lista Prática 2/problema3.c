#include <stdio.h>

int main(){
    int idade, tempo;
    char sex;

    printf("Digite a idade: ");
    scanf("%d", &idade);

    printf("Digite o tempo de contribuicao: ");
    scanf("%d", &tempo);

    printf("Digite o sexo: ");
    scanf(" %c", &sex);

    if (idade >= 60 && tempo >= 35 && sex == 'M'){
        printf("Pode aposentar\n");
    }
    else if (idade >= 55 && tempo >= 30 && sex == 'F') {
        printf("Pode aposentar\n");
    }
    else if (idade >= 65 && sex == 'M') {
        printf("Pode aposentar\n");
    }
    else if (idade >= 60 && sex == 'F') {
        printf("Pode aposentar\n");
    }
    else {
        printf("Nao pode aposentar\n");
    }


}

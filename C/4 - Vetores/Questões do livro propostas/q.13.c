#include <stdio.h>
#include <string.h>
#define alunos 8
int main(){
    int i;
    float notas[alunos],media=0;
    char nome[alunos][50];
    for(i=0;i<alunos;i++){
        printf("Digite o nome do %d aluno:",i+1);
        fflush(stdin);
        fgets(nome[i],sizeof(nome[i]),stdin);
        nome[i][strcspn(nome[i],"\n")]='\0';
        printf("Digite a nota do %s:",nome[i]);
        scanf("%f",&notas[i]);
        media+=notas[i];
    }
    for(i=0;i<alunos;i++){
        printf("%s %.1f\n",nome[i],notas[i]);
    }
    printf("Media da classe = %.1f",media/alunos);
    return 0;
}

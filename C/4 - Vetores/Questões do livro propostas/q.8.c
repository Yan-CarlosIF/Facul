#include <stdio.h>
#include <string.h>
#define aluno 10
int main(){
    int i;
    float notas[aluno],nota_maior;
    char nome[aluno][50],nome_maior[50];
    for(i=0; i < aluno ; i++){
        printf("Digite o nome do %d estudante:\n",i+1);
        fflush(stdin);
        fgets(nome[i],sizeof(nome[i]),stdin);
        nome[i][strcspn(nome[i],"\n")]='\0';
        printf("Digite a nota do %d estudante:\n",i+1);
        scanf("%f",&notas[i]);
        if (i==0){
            nota_maior=notas[i];
            strcpy(nome_maior,nome[i]);
        }
        if (nota_maior<notas[i]){
            nota_maior=notas[i];
            strcpy(nome_maior,nome[i]);
        }
    }
    printf("\nO nome do aluno com maior media %.1f: %s\n",nota_maior,nome_maior);
    for (i = 0; i < aluno; i++){
        if (notas[i]<7){
            printf("\nO %d aluno %s precisa tirar %.1f na final para ser aprovado!",i+1,nome[i],10-notas[i]);
        }
    }
    return 0;
}
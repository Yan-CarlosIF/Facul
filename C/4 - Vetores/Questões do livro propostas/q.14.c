#include <stdio.h>
#include <string.h>
#define alunos 8

int main(){
    int i,cont_aprov=0,cont_exam=0,cont_repro=0;
    char nome[alunos][50],situa[alunos][15];                              
    float nota1[alunos],nota2[alunos],media[alunos],media_c=0;
    for(i = 0; i < alunos; i++){
        printf("Digite o nome do aluno %d:",i+1);
        fflush(stdin);
        fgets(nome[i],sizeof(nome[i]),stdin);
        nome[i][strcspn(nome[i],"\n")]='\0';
        printf("Digite a primeira nota do %s:",nome[i]);
        scanf("%f",&nota1[i]);
        printf("Digite a segunda nota do %s:",nome[i]);
        scanf("%f",&nota2[i]);
        media[i]=(nota1[i]+nota2[i])/2;
        media_c+=media[i];
        if (media[i]>=7){
            cont_aprov++;
            strcpy(situa[i],"Aprovado");            
        }
        else if (media[i]>=3){
            cont_exam++;
            strcpy(situa[i],"Exame Final");
        }
        else{
            cont_repro++;
            strcpy(situa[i],"Reprovado");
        }
        printf("\n");
    }
    for (i = 0; i < alunos; i++){
        printf("\nAluno: %s\n1 Prova: %.1f\n2 Prova: %.1f\nMedia: %.1f\nSituacao: %s\n",nome[i],nota1[i],nota2[i],media[i],situa[i]);
    }
    printf("\nMedia da classe: %.1f\n",media_c/alunos);
    printf("\nPorcentagem alunos:\nAprovados: %.1f\nExame Final: %.1f\nReprovados: %.1f\n",(cont_aprov/(float)alunos)*100,(cont_exam/(float)alunos)*100,(cont_repro/(float)alunos)*100);
    return 0;
}
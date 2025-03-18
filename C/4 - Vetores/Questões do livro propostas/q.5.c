#include <stdio.h>
/*Uma escola deseja saber se existem alunos cursando, simultaneamente, as disciplinas lógica e linguagem de 
Programação. Coloque os números das matrículas dos alunos que cursam lógica em um vetor, quinze alunos. 

 Coloque os números das matrículas dos alunos que cursam linguagem de Programação em outro vetor, dez 
alunos. Mostre o número das matrículas que aparecem nos dois vetores. */
#define log 15
#define pro 10
int main(){
    int i,logica[log],prog[pro];
    for (i = 0; i < log; i++){
        printf("Numero da matricula do %d aluno que cursa logica:\n",i+1);
        scanf("%d",&logica[i]);
    }
    printf("\nAgora o numero da matricula dos alunos de linguagem de programacao\n\n");
    for (i = 0; i < pro; i++){
        printf("Numero da matricula do %d aluno que cursa programacao:\n",i+1);
        scanf("%d",&prog[i]);
    }
    for (i = 0; i < log; i++){
        for (int j = 0; j < pro; j++){
        if (logica[i]==prog[j]){
            printf("O aluno com matricula: %d, Cursa logica e linguagem de programacao ao mesmo tempo!\n",prog[j]);
        }
        }
    }
    return 0;
}

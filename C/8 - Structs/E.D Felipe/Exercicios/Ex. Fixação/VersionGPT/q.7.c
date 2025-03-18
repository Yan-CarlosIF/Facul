#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Cadastro de Livro com Vetor de Ponteiros para Estrutura:

// Defina uma estrutura chamada "Aluno" com campos nome e nota (sendo nota um float).
// Declare um vetor de ponteiros para essa estrutura, aloque memória dinamicamente para cada elemento e preencha com informações de vários alunos.
// Imprima os dados de cada aluno e libere a memória ao final.

typedef struct {
    char nome[50];
    float nota;
} Aluno;


int main() {
    int size;

    printf("Digite quantos alunos deseja cadastrar:");
    scanf("%d", &size);
    getchar();

    Aluno *alunos = (Aluno *)malloc(sizeof(Aluno) * size);

    for (int i = 0; i < size; i++) {
        printf("Digite o nome do %d aluno:", i + 1);
        fgets(alunos[i].nome, 50, stdin);
        alunos[i].nome[strcspn(alunos[i].nome, "\n")] = '\0';

        printf("Digite a sua nota:");
        scanf("%f", &alunos[i].nota);
        getchar();
        printf("\n");        
    }

    printf("\nSituacao dos alunos:\n");
    for (int i = 0; i < size; i++) {
        char situacao[20];
        strcpy(situacao, (alunos[i].nota >= 7) ? "Aprovado" : "Reprovado");
        printf("Aluno '%s'\nNota: %.1f\nSituacao: %s\n\n", alunos[i].nome, alunos[i].nota, situacao);       
    }
    
    return 0;
}
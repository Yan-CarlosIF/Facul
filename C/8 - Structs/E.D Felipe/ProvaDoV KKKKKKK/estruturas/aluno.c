#include "aluno.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

ListaAlunos* initList() {
    ListaAlunos *alunos = malloc(sizeof(ListaAlunos));

    alunos->head = NULL;
    alunos->end = NULL;
    alunos->tamanho = 0;
    
    return alunos;
}

void push(ListaAlunos *alunos, char *nome, char *curso, int idade, int matricula) {
    Aluno *novo = malloc(sizeof(Aluno));
    strcpy(novo->nome, nome);
    strcpy(novo->curso, curso);
    novo->idade = idade;
    novo->matricula = matricula;
    novo->prox = NULL;

    if (alunos->tamanho == 0) {
        alunos->head = novo;
        alunos->end = novo;
    } else {
        alunos->end->prox = novo;
        alunos->end = novo;
    }

    alunos->tamanho++;
}

Aluno* buscarAluno(ListaAlunos *alunos, int matricula) {
    Aluno *temp = alunos->head;
    
    while (temp != NULL) {
        if (temp->matricula == matricula) {
            return temp;
        }

        temp = temp->prox;
    }
    
    return NULL;
}

void modificarDados(ListaAlunos *alunos, int matricula) {
    int encontrado = 0;
    Aluno *temp = alunos->head;
    
    while (temp != NULL) {
        if (temp->matricula == matricula) {
            encontrado = 1;
            int opcoes;
            
            do {
                printf("\nDigite para alterar:\n1 - matricula\n2 - nome\n3 - idade\n4 - curso\n0 - Sair.\n");
                scanf("%d", &opcoes);
                getchar();

                switch (opcoes) {
                    case 0: break;
                    case 1: {
                        int novaMatricula;
                        printf("Digite a nova matricula: ");
                        scanf("%d", &novaMatricula);

                        temp->matricula = novaMatricula;
                        break;
                    }
                    case 2: {
                        char novoNome[50]; 
                        printf("Digite o novo nome: ");
                        fgets(novoNome, sizeof(novoNome), stdin);
                        novoNome[strcspn(novoNome, "\n")] = '\0';

                        strcpy(temp->nome, novoNome);
                        break;
                    }
                    case 3: {
                        int novaIdade;
                        printf("Digite a nova idade: ");
                        scanf("%d", &novaIdade);

                        temp->idade = novaIdade;
                        break;
                    }
                    case 4: {
                        char novoCurso[50];
                        printf("Digite a nova idade: ");
                        fgets(novoCurso, sizeof(novoCurso), stdin);
                        novoCurso[strcspn(novoCurso, "\n")] = '\0';

                        strcpy(temp->curso, novoCurso);
                        break;
                    }
                    default:
                        printf("Opcao invalida!");
                        break;
                }
            } while (opcoes != 0);
        }

        temp = temp->prox;
    }

    if (!encontrado) {
        printf("Aluno inexistente!\n");
    }
}

void exibirLista(ListaAlunos *alunos) {
    if (alunos->tamanho == 0) {
        printf("Lista vazia!\n");
        return;
    }
    
    int i = 1;
    Aluno *temp = alunos->head;

    while (temp != NULL) {
        printf("\nAluno %d:\nNome: %s\nCurso: %s\nIdade: %d\nMatricula: %d\n", 
        i++, temp->nome, temp->curso, temp->idade, temp->matricula);

        temp = temp->prox;
    }
    
    printf("\n");
}

void deletarAluno(ListaAlunos *alunos, int matricula) {
    int encontrado = 0;
    Aluno *anterior = NULL;
    Aluno *atual = alunos->head;
    
    while (atual != NULL) {
        if (atual->matricula == matricula) {
            encontrado = 1;
            Aluno *alunoExcluido = atual;
            anterior->prox = atual->prox;
            free(alunoExcluido);
            alunos->tamanho--;
        }

        anterior = atual;
        atual = atual->prox;
    }

    if (!encontrado) {
        printf("Aluno inexistente!\n");
    }
}

void freeLista(ListaAlunos *alunos) {
    Aluno *temp = alunos->head;

    while (temp != NULL) {
        Aluno *alunoLiberado = temp;
        temp = temp->prox;
        free(alunoLiberado);
    }

    alunos->head = NULL;
    alunos->end = NULL;
    alunos->tamanho = 0;
    free(alunos);    
}
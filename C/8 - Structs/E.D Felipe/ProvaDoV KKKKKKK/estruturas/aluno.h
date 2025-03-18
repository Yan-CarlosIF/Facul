#ifndef ALUNO_H
#define ALUNO_H

typedef struct Aluno {
    char nome[50], curso[30];
    int idade, matricula;
    struct Aluno *prox;
} Aluno;

typedef struct {
    Aluno *head, *end;
    int tamanho;
} ListaAlunos;

ListaAlunos* initList();
void push(ListaAlunos *alunos, char *nome, char *curso, int idade, int matricula);
Aluno* buscarAluno(ListaAlunos *alunos, int matricula);
void modificarDados(ListaAlunos *alunos, int matricula);
void exibirLista(ListaAlunos *alunos);
void deletarAluno(ListaAlunos *alunos, int matricula);
void freeLista(ListaAlunos *alunos);
#endif
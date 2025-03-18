#include "./escola.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Escola *initEscola() {
  Escola *novaEscola = (Escola *)malloc(sizeof(Escola));
  if (novaEscola == NULL) {
    printf("\nERRO: falha na alocação de memoria para uma escola\n");
    exit(1);
  }

  novaEscola->cursos = (Curso *)malloc(sizeof(Curso) * MAX_CURSOS);
  if (novaEscola->cursos == NULL) {
    printf("\nERRO: falha na alocação de memoria para os cursos\n");
    exit(1);
  }
  novaEscola->contCursos = 0;

  return novaEscola;
}

void cadastrarCurso(Escola *escola) {
  if (escola->contCursos == MAX_CURSOS) {
    printf("\nERRO: O limite de cursos foi atingido\n");
    return;
  }

  char descricao[100];
  int alunosMatriculados;
  float valorDaMensalidade;

  getchar();
  printf("\nDigite a descricao do curso: ");
  scanf("%[^\n]", descricao);

  printf("\nDigite a quantidade de alunos matriculados: ");
  scanf("%d", &alunosMatriculados);

  printf("\nDigite o valor da mensalidade: ");
  scanf("%f", &valorDaMensalidade);

  strcpy(escola->cursos[escola->contCursos].descricao, descricao);
  escola->cursos[escola->contCursos].alunosMatriculados = alunosMatriculados;
  escola->cursos[escola->contCursos].valorDaMensalidade = valorDaMensalidade;

  printf("\nCurso cadastrado com sucesso!\n");
  escola->contCursos++;
}

float mediaDeAlunosMatriculados(Escola *escola) {
  float soma = 0;
  for (int i = 0; i < escola->contCursos; i++)
    soma += escola->cursos[i].alunosMatriculados;

  return soma / escola->contCursos;
}

float receita(int alunosMatriculados, float valorDaMensalidade) {
  return alunosMatriculados * valorDaMensalidade;
}

void descricaoDoCursoMaiorReceita(Escola *escola) {
  if (escola->contCursos == 0) {
    printf("\nERRO: Nao foi cadastrado nenhum curso\n");
    return;
  }

  Curso cursoMaiorReceita = escola->cursos[0];

  for (int i = 0; i < escola->contCursos; i++) {
    float maiorReceita = receita(cursoMaiorReceita.alunosMatriculados,
                                 cursoMaiorReceita.valorDaMensalidade);

    float receitaAtual = receita(escola->cursos[i].alunosMatriculados,
                                 escola->cursos[i].valorDaMensalidade);

    if (receitaAtual > maiorReceita) cursoMaiorReceita = escola->cursos[i];
  }

  printf("\nO curso com maior receita eh: %s\n", cursoMaiorReceita.descricao);
}

int menu() {
  int opcao;
  printf("\nDigite uma opcao:\n");
  printf("1 - Cadastrar curso\n");
  printf("2 - Media de alunos matriculados\n");
  printf("3 - Descricao do curso com maior receita\n");
  printf("4 - Sair\n");
  printf("Escolha uma opcao: ");
  scanf("%d", &opcao);
  return opcao;
}
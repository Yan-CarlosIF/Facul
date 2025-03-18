#ifndef ESCOLA_H
#define ESCOLA_H
#define MAX_CURSOS 3058

typedef struct Curso {
  char descricao[100];
  int alunosMatriculados;
  float valorDaMensalidade;
} Curso;

typedef struct {
  Curso *cursos;
  int contCursos;
} Escola;

Escola *initEscola();
void cadastrarCurso(Escola *escola);
float mediaDeAlunosMatriculados(Escola *escola);
float receita(int alunosMatriculados, float valorDaMensalidade);
void descricaoDoCursoMaiorReceita(Escola *escola);
int menu();
#endif
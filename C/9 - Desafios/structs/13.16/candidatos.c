#include "./candidatos.h"
#include <stdio.h>

int menu() {
  int op;
  printf("1 - Inserir Candidato\n");
  printf("2 - Sair\n");
  printf("Escolha uma opcao: ");
  scanf("%d", &op);

  return op;
}

bool isValidCode(Candidato candidatos[CURSOS][VAGAS], int code, Cursos curso, const int *tam) {
  for (int i = 0; i < tam[curso - 1]; i++)
    if (candidatos[curso - 1][i].codigo == code) return true;

  return false;
}

void cadastrarCandidatos(Candidato candidatos[CURSOS][VAGAS], int *tam) {
  Cursos curso;

  do {
    printf("Digite o curso que deseja cadastrar o candidato:\n");
    printf("1 - Ciencia da Computacao\n");
    printf("2 - Engenharia de Computacao\n");
    printf("3 - Analise de Sistemas\n");
    scanf("%d", (int *)&curso);
  } while (curso < 1 || curso > CURSOS);

  int codigo, pontuacao;

  do {
    printf("Digite o codigo do candidato: ");
    scanf("%d", &codigo);
  } while (isValidCode(candidatos, codigo, curso, tam));

  printf("Digite a pontuacao do candidato: ");
  scanf("%d", &pontuacao);

  if (tam[curso - 1] >= VAGAS) {
    if (pontuacao > candidatos[curso - 1][VAGAS - 1].pontuacao) {
      candidatos[curso - 1][VAGAS - 1].codigo = codigo;
      candidatos[curso - 1][VAGAS - 1].pontuacao = pontuacao;
    } else {
      printf("\nNao foi possivel cadastrar o candidato!\n");
    }
  } else {
    int i;
    for (i = tam[curso - 1];
         i > 0 && candidatos[curso - 1][i - 1].pontuacao < pontuacao; i--) {
      candidatos[curso - 1][i] = candidatos[curso - 1][i - 1];
    }
    candidatos[curso - 1][i].codigo = codigo;
    candidatos[curso - 1][i].pontuacao = pontuacao;
    tam[curso - 1]++;
  }

  printf("\nCandidato cadastrado com sucesso!\n");
}

void exibirResultado(Candidato candidatos[CURSOS][VAGAS]) {
  printf("\nResultado do Vestibular:\n");
  printf("Codigo - Pontuacao\n");
  for (int i = 0; i < CURSOS; i++) {
    printf("\nCurso %s:\n", CURSOS_NOMES[i]);
    for (int j = 0; j < VAGAS; j++) {
      printf("%d - %d\n", candidatos[i][j].codigo, candidatos[i][j].pontuacao);
    }
  }
}
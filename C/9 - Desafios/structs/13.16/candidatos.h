#ifndef CANDIDATOS_H
#define CANDIDATOS_H
#include <stdbool.h>
#define CURSOS 3
#define VAGAS 40
const char *CURSOS_NOMES[CURSOS] = {
    "Ciencia da Computacao", "Engenharia de Computacao", "Analise de Sistemas"};

typedef enum {
  BCC = 1,
  ENG = 2,
  ADS = 3,
} Cursos;

typedef struct {
  int codigo;
  int pontuacao;
} Candidato;

int menu();
bool isValidCode(Candidato candidatos[CURSOS][VAGAS], int code, Cursos curso, const int *tam);
void cadastrarCandidatos(Candidato candidatos[CURSOS][VAGAS], int *tam);
void exibirResultado(Candidato candidatos[CURSOS][VAGAS]);
#endif
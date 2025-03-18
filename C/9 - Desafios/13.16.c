#include "./structs/13.16/candidatos.c"

int main() {
  Candidato resultados[CURSOS][VAGAS] = {0};
  int tam[CURSOS] = {0};

  while (1) {
    int op = menu();

    switch (op) {
      case 1:
        cadastrarCandidatos(resultados, tam);
        break;
      case 2:
        break;
      default:
        printf("\nOpcao invalida!");
        break;
    }

    if (op == 2) break;
  }

  exibirResultado(resultados);

  return 0;
}
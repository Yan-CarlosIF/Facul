#include "./structs/13.15/escola.c"

// Uma escola oferece 3.058 cursos. Sabe-se que cada curso possui descrição,
// quantidade de alunos matriculados e valor da mensalidade. A escola precisa
// cadastrar os cursos e, depois, precisa saber: a) a média aritmética de alunos
// matriculados nos cursos; b) a descrição do curso que gera a maior receita
// (receita = quantidade de alunos * valor da mensalidade).

// Crie uma aplicação que, utilizando um vetor de registro, consiga atender as
// necessidades da escola.

int main() {
  Escola *escola = initEscola();

  while (1) {
    int opcao = menu();
    switch (opcao) {
      case 1:
        cadastrarCurso(escola);
        break;
      case 2:
        printf("\nMedia de alunos matriculados: %.2f\n",
               mediaDeAlunosMatriculados(escola));
        break;
      case 3:
        descricaoDoCursoMaiorReceita(escola);
        break;
      case 4:
        printf("\nSaindo do programa...\n");
        free(escola->cursos);
        free(escola);
        return 0;
      default:
        printf("\nOpcao invalida\n");
        break;
    }

    if (opcao == 4) break;
  }

  return 0;
}
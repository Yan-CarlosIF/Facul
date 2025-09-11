#include <stdio.h>
#define STUDENTS 8
#define DISCIPLINES 5

// 11:
// Elabore um programa que: receba a idade de oito alunos e armazene-as em um
// vetor; armazene o código de cinco disciplinas em outro vetor; armazene em uma
// matriz a quantidade de provas que cada aluno fez em cada disciplina.

// 12:
// O programa deverá calcular e mostrar:

// ■ a quantidade de alunos com idade entre 18 e 25 anos que fizeram mais de
// duas provas em determinada  disciplina  cujo  código  é  digitado  pelo
// usuário.  O  usuário  poderá  digitar  um  código  não cadastrado; nesse
// caso, o programa deverá mostrar uma mensagem de erro;

//  ■ uma listagem contendo o código dos alunos que fizeram menos que três
//  provas em determinada
// disciplina, seguido do código da disciplina;

// ■ a média de idade dos alunos que não fizeram nenhuma prova em alguma
// disciplina. Cuidado para não contar duas vezes o mesmo aluno.

int main() {
  int studentAges[STUDENTS];
  int disciplines[DISCIPLINES];
  int testsQuantities[DISCIPLINES][STUDENTS];

  for (int i = 0; i < STUDENTS; i++) {
    printf("Insira a idade do aluno %d°: ", i + 1);
    scanf("%d", &studentAges[i]);
  }

  for (int i = 0; i < DISCIPLINES; i++) {
    printf("Insira o codigo da %d° disciplina: ", i + 1);
    scanf("%d", &disciplines[i]);
  }

  for (int i = 0; i < DISCIPLINES; i++) {
    for (int j = 0; j < STUDENTS; j++) {
      printf(
          "Insira a quantidade de provas que o aluno %d teve na disciplina %d",
          j + 1, i + 1);
      scanf("%d", &testsQuantities[i][j]);
    }
  }

  int disciplineCode;

  printf("Insira o codigo de uma disciplina: ");
  scanf("%d", &disciplineCode);

  int disciplineIndex;
  for (disciplineIndex = 0; disciplineIndex < DISCIPLINES; disciplineIndex++) {
    if (disciplines[disciplineIndex] == disciplineCode) break;
  }

  if (disciplineIndex >= DISCIPLINES) {
    printf("ERRO: codigo da disciplina não encontrado");
  } else {
    int quantityOfStudentsInCondition = 0;

    for (int i = 0; i < STUDENTS; i++) {
      int studentAge = studentAges[i];
      int testQuantity = testsQuantities[disciplineIndex][i];

      if (studentAge >= 18 && studentAge <= 25 && testQuantity > 2) {
        quantityOfStudentsInCondition++;
      }
    }

    printf(
        "Quantidade de alunos com idade entre 18 e 25 anos que fizeram mais de "
        "duas provas na disciplina %d: %d\n",
        disciplines[disciplineIndex], quantityOfStudentsInCondition);
  }

  float average = 0;
  int studentsWithNoTests[STUDENTS] = {0};

  for (int i = 0; i < DISCIPLINES; i++) {
    for (int j = 0; j < STUDENTS; j++) {
      if (testsQuantities[i][j] < 3) {
        printf("Codigo aluno (index): %d | Codigo Disciplina: %d\n", j + 1,
               disciplines[i]);
      }

      if (testsQuantities[i][j] == 0) {
        studentsWithNoTests[j] = 1;
      }
    }
  }

  int contStudentsWithNoTests = 0;
  for (int i = 0; i < STUDENTS; i++) {
    if (studentsWithNoTests[i] == 1) {
      average += (float)studentAges[i];

      contStudentsWithNoTests++;
    }
  }

  printf(
      "Media das idades dos alunos que fizeram nenhuma prova em alguma "
      "disciplina: %.1f",
      average / (float)contStudentsWithNoTests);

  return 0;
}
#include "./structs/13.8/agenda.c"

// Faça um programa que apresente o menu de opções a seguir:
// 1. Cadastrar pessoa na agenda de aniversariantes (nome, dia e mês do
// aniversário).
// 2. Excluir pessoa a partir do nome.
// 3. Alterar dia ou mês a partir do nome.
// 4. Consultar aniversariantes de uma data (dia e mês).
// 5. Consultar aniversariantes por mês.
// 6. Consultar aniversariantes pela letra inicial do nome.
// 7. Mostrar toda a agenda ordenada pelo nome.
// 8. Mostrar toda a agenda ordenada por mês.
// 9. Sair.
// A agenda pode suportar até 15 pessoas.

int main() {
  Agenda *agendaNiver = initAgenda();
  printf("Seja Bem Vindo ao sistema de agenda de aniversariantes!\n");

  while (1) {
    int op = menu();
    switch (op) {
      case 1:
        cadastrarPessoa(agendaNiver);
        break;
      case 2:
        excluirPessoa(agendaNiver);
        break;
      case 3:
        set(agendaNiver);
        break;
      case 4:
        consultarPorDiaEmes(agendaNiver);
        break;
      case 5:
        consultarPorMes(agendaNiver);
        break;
      case 6:
        consultarPorLetraInicial(agendaNiver);
        break;
      case 7:
        ordenarPorNome(agendaNiver);
        break;
      case 8:
        ordenarPorMes(agendaNiver);
        break;
      case 9:
        freeList(agendaNiver);
        printf("\nPrograma encerrado!\n");
        break;
      default:
        printf("Opcao invalida!");
        break;
    }

    if (op == 9) break;
  }
  return 0;
}

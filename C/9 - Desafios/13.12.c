#include "./structs/13.12/q.c"

// Uma empresa do ramo da construção civil está informatizando seu Departamento
// de Pessoal. Inicialmente, cadastrou o salário de todos os cargos da empresa.

int main() {
  printf(
      "\nBem-vindo ao sistema de cadastro da empresa de construcao civil.\n");

  ListaFuncionarios *funcionarios = initList();
  bool cargosCadastrados = false;

  while (1) {
    int opcao = menu();

    switch (opcao) {
      case 1:
        if (cargosCadastrados) {
          printf("\nOs cargos ja foram cadastrados!\n");
          break;
        }

        cadastrarCargos();
        cargosCadastrados = true;
        break;
      case 2:
        cadastrarFuncionario(funcionarios);
        break;
      case 3:
        mostrarRelatorio(funcionarios);
        break;
      case 4: {
        int cargo;
        do {
          printf("\nDigite o codigo do cargo: ");
          scanf("%d", &cargo);
        } while (!validarCodigoCargo(cargo));

        mostrarSalarioCargo(funcionarios, cargo);
      } break;
      case 5:
        printf(
            "\nObrigado por testar o sistema da empresa de construcao "
            "civil!\n");
        return 0;
      default:
        printf("\nOpcao invalida. Tente novamente.\n");
        break;
    }

    if (opcao == 5) break;
  }
  return 0;
}

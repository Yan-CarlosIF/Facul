#include "./q.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Crie uma aplicação que contenha uma função para mostrar um menu ao usuário,
// assim:
// 1. Cadastrar os cargos da empresa.
// 2. Cadastrar os funcionários da empresa.
// 3. Mostrar um relatório contendo o número, o nome e o valor do salário de
// todos os funcionários.
// 4. Mostrar o valor pago aos funcionários que pertençam a um cargo informado
// pelo usuário.
// 5. Finalizar.
int menu() {
  int op;

  printf("Escolha uma opcao:\n");
  printf("1. Cadastrar os cargos da empresa.\n");
  printf("2. Cadastrar os funcionarios da empresa.\n");
  printf(
      "3. Mostrar um relatorio contendo o numero, o nome e o valor do salario "
      "de todos os funcionarios.\n");
  printf(
      "4. Mostrar o valor pago aos funcionarios que pertencaem a um cargo "
      "informado pelo usuario.\n");
  printf("5. Finalizar.\n");
  printf("Escolha uma opcao: ");
  scanf("%d", &op);
  getchar();

  return op;
}

ListaFuncionarios *initList() {
  ListaFuncionarios *lista =
      (ListaFuncionarios *)malloc(sizeof(ListaFuncionarios));
  if (lista == NULL) {
    printf("\nERRO: Falha ao alocar memória!\n");
    exit(1);
  }

  lista->inicio = NULL;
  lista->fim = NULL;
  lista->size = 0;

  return lista;
}

Funcionario *criarFuncionario(int codigo, char *nome, int codigo_cargo) {
  Funcionario *funcionario = (Funcionario *)malloc(sizeof(Funcionario));
  if (funcionario == NULL) {
    printf("\nERRO: Falha ao alocar memória!\n");
    exit(1);
  }

  funcionario->codigo = codigo;
  strcpy(funcionario->nome, nome);
  funcionario->codigo_cargo = codigo_cargo;
  funcionario->prox = NULL;

  return funcionario;
}

void push(ListaFuncionarios *list, Funcionario *funcionario) {
  if (list->size == 0) {
    list->inicio = list->fim = funcionario;
  } else {
    list->fim->prox = funcionario;
    list->fim = funcionario;
  }

  list->size++;
}

// Opção 1: Cada vez que essa opção for selecionada deverá ser chamada uma
// sub-rotina, na qual o usuário poderá cadastrar todos os cargos. Não se
// esqueça, nessa empresa existem apenas cinco cargos. Se o usuário mandar
// executar esta opção mais de uma vez, mostre a mensagem de erro “Salários dos
// cargos já cadastra- dos” e retorne ao menu.
void cadastrarCargos() {
  for (int i = 0; i < 5; i++) {
    printf("Digite o cargo %d: ", i + 1);
    scanf("%f", &Cargos[i]);
  }
}

// Opção 2: Cada vez que essa opção for selecionada deverá ser chamada uma
// sub-rotina, na qual o usuário poderá cadastrar um novo funcionário, ou seja,
// informará o número do funcionário (este número deve ser único, você deverá
// implementar essa validação), nome e código do cargo (lembre-se de que o
// código informado deverá existir no vetor de cargos). Não se esqueça, nessa
// empresa existem apenas 15 funcionários. Se o usuário selecionar essa opção e
// o vetor de funcionários estiver completamente preenchido, mostrar uma
// mensagem de erro e retornar ao menu.

// ■ Crie uma sub-rotina para fazer a validação do número do funcionário — ela
// não poderá aceitar número repetido.
bool validarCodigoFuncionario(ListaFuncionarios *list, int codigo) {
  if (list->size == 0) return true;

  Funcionario *temp = list->inicio;

  while (temp != NULL) {
    if (temp->codigo == codigo) {
      printf("\nERRO: Codigo de funcionario ja cadastrado!\n\n");
      return false;
    }
    temp = temp->prox;
  }

  return true;
}

// ■ Crie  uma  sub-rotina  para  validar  o  nome  do  funcionário, obrigando-o
// a  ser  composto  por  pelo menos duas palavras (nome e sobrenome).
bool validarNomeFuncionario(char *nome) {
  char *token = strtok(nome, " ");
  int cont = 0;

  while (token != NULL) {
    cont++;
    token = strtok(NULL, " ");
  }

  if (cont < 2) printf("\nERRO: Nome do funcionario invalido!\n\n");

  return cont >= 2;
}

// ■ Crie uma sub-rotina para fazer a validação do código do cargo ocupado
// pelo funcionário — ela só poderá aceitar códigos entre 1 e 5 cujos salários
// já tenham sido cadastrados no vetor de cargos.
bool validarCodigoCargo(int codigo_cargo) {
  if (codigo_cargo < 1 || codigo_cargo > 5) {
    printf("\nERRO: Codigo de cargo invalido!\n\n");
    return false;
  }

  return true;
}

void cadastrarFuncionario(ListaFuncionarios *list) {
  if (list->size >= MAX_FUNCIONARIOS) {
    printf("\nERRO: Numero maximo de funcionarios cadastrados!\n\n");
    return;
  }

  int codigo;
  char nome[50];
  int codigoCargo;

  do {
    printf("Digite o codigo do funcionario: ");
    scanf("%d", &codigo);
  } while (!validarCodigoFuncionario(list, codigo));
  getchar();

  do {
    printf("Digite o nome do funcionario: ");
    fgets(nome, 50, stdin);
    nome[strcspn(nome, "\n")] = '\0';
  } while (!validarNomeFuncionario(nome));

  do {
    printf("Digite o codigo do cargo: ");
    scanf("%d", &codigoCargo);
  } while (!validarCodigoCargo(codigoCargo));

  Funcionario *funcionario = criarFuncionario(codigo, nome, codigoCargo);

  push(list, funcionario);
}

// Opção 3: Cada vez que essa opção for selecionada deverá ser chamada uma
// sub-rotina, na qual serão mostrados código, nome e valor do salário de
// todos os funcionários cadastrados (salários podem ser obtidos no vetor de
// cargos).
void mostrarRelatorio(ListaFuncionarios *list) {
  if (list->size == 0) {
    printf("\nERRO: Nenhum funcionario cadastrado!\n\n");
    return;
  }

  Funcionario *temp = list->inicio;

  printf("\nRELATORIO:\nCodigo - Nome - Salario\n");
  while (temp != NULL) {
    printf("\n%d - %s - %.2f\n", temp->codigo, temp->nome,
           Cargos[temp->codigo_cargo - 1]);
    temp = temp->prox;
  }
  printf("\n");
}

// Opção 4: Cada vez que essa opção for selecionada deverá ser chamada uma
// sub-rotina, na qual será feito o somatório do salário de todos os
// funcionários que pertencerem a determinado cargo. Esse cargo é infor- mado
// pelo usuário (entre 1 e 5) no módulo principal do seu programa e o somatório
// calculado deverá ser mostrado, também, no módulo principal.
void mostrarSalarioCargo(ListaFuncionarios *list, int cargo) {
  if (list->size == 0) {
    printf("\nERRO: Nenhum funcionario cadastrado!\n\n");
    return;
  }

  Funcionario *temp = list->inicio;
  bool cargoEncontrado = false;
  float totalSalarios = 0;

  while (temp != NULL) {
    if (temp->codigo_cargo == cargo) {
      cargoEncontrado = true;
      totalSalarios += Cargos[temp->codigo_cargo - 1];
    }
    temp = temp->prox;
  }

  if (cargoEncontrado) {
    printf("\nSalario total do cargo %d: %.2f\n\n", cargo, totalSalarios);
  } else {
    printf("\nERRO: Cargo nao possui funcionarios!\n\n");
  }
}
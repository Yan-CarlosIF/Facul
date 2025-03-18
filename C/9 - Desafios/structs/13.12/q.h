#ifndef Q_H
#define Q_H
#define MAX_FUNCIONARIOS 15
#include <stdbool.h>
//              1           2            3           4         5
// Cargos R$ 2.500,00 R$ 1.500,00 R$ 10.000,00 R$ 1.200,00 R$ 800,00
// Cada tipo de cargo ocupa uma posição do vetor de tamanho 5.
float Cargos[5] = {2500.00, 1500.00, 10000.00, 1200.00, 800.00};

// Depois, cadastrou todos os seus funcionários em um vetor de registros,
// contendo os seguintes campos: código, nome e código do cargo.
typedef struct Funcionario {
  int codigo;
  char nome[50];
  int codigo_cargo;
  struct Funcionario *prox;
} Funcionario;

typedef struct {
  Funcionario *inicio, *fim;
  int size;
} ListaFuncionarios;

int menu();
ListaFuncionarios *initList();
Funcionario *criarFuncionario(int codigo, char *nome, int codigo_cargo);
void push(ListaFuncionarios *list, Funcionario *funcionario);
bool validarCodigoFuncionario(ListaFuncionarios *list, int codigo);
void cadastrarCargos();
void cadastrarFuncionario(ListaFuncionarios *list);
void mostrarRelatorio(ListaFuncionarios *list);
void mostrarSalarioCargo(ListaFuncionarios *list, int cargo);
#endif
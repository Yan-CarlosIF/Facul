#ifndef Q_15_H
#define Q_15_H
#include <stdbool.h>

// Clientes (número do telefone, nome do cliente, endereço, complemento, CEP). 
typedef struct {
    char numeroTelefone[15];
    char nome[50];
    char endereco[50];
    char complemento[15];
    char CEP[15];
    float totalGasto;
} Cliente;

// Pizzas (código da pizza, nome da pizza, valor). 
typedef struct {
    char sabor[30];
    float valor;
} Pizza;

// Pedido (número do pedido, número do telefone, código da pizza, código do motoqueiro, situação).
typedef struct Pedido {
    int numeroPedido;
    Cliente *cliente;
    Pizza *pizza;
    int codigoMotoboy;
    int situacao;
    struct Pedido *prox;
} Pedido;

// Fila de pedidos
typedef struct {
    Pedido *primeiro;
    Pedido *ultimo;
    int tamanho;
} FilaDeEntrega;

// Lista de Motoqueiros
typedef struct Motoboy {
    int codigo;
    int contEntregas;
    struct Motoboy *prox;
} Motoboy;

FilaDeEntrega* iniciarEntregas();
void removerLinha(char *str);
void cadastrarPizza(Pizza **pizzas, int *contPizzas);
void cadastrarCliente(Cliente **clientes, int *contClientes);
Pizza* validaPizza(Pizza *pizzas, char *saborPizza, const int contPizzas);
Cliente* validaCliente(Cliente *clientes, char *numCliente, const int contClientes);
void validaMotoboy(Motoboy **motoboys, int codigo);
void fazerPedido(FilaDeEntrega *entregas, Cliente *clientes, Pizza *pizzas, Motoboy **motoboys, const int contPizzas, const int contClientes);
void despachoPizza(FilaDeEntrega *entregas);
void entregarPizza(FilaDeEntrega *entregas);
void mostrarEntregas(FilaDeEntrega *entregas);
void mostrarTotalGasto(Cliente *clientes, const int contClientes);
void mostrarMotoboys(Motoboy *motoboys);
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "q.15.h"

FilaDeEntrega* iniciarEntregas() {
    FilaDeEntrega *entregas = (FilaDeEntrega*)malloc(sizeof(FilaDeEntrega));

    entregas->primeiro = NULL;
    entregas->ultimo = NULL;
    entregas->tamanho = 0;

    return entregas;
}

void removerLinha(char *str) {
    str[strcspn(str, "\n")] = '\0';
}

void cadastrarPizza(Pizza **pizzas, int *contPizzas) {
    if (*contPizzas == 0) {
        *pizzas = (Pizza*)malloc(sizeof(Pizza));
    } else {
        *pizzas = (Pizza*)realloc(*pizzas, sizeof(Pizza) * (*contPizzas + 1));
    }

    printf("Digite o sabor da pizza: ");
    fgets((*pizzas + *contPizzas)->sabor, 30, stdin);
    removerLinha((*pizzas + *contPizzas)->sabor);

    printf("Digite o valor do sabor %s de pizza: ", (*pizzas + *contPizzas)->sabor);
    scanf("%f", &(*pizzas + *contPizzas)->valor);
    
    (*contPizzas)++;
}

void cadastrarCliente(Cliente **clientes, int *contClientes) {
    if (*contClientes == 0) {
        *clientes = (Cliente*)malloc(sizeof(Cliente));
    } else {
        *clientes = (Cliente*)realloc(*clientes, sizeof(Cliente) * (*contClientes + 1));
    }

    printf("Digite o telefone do cliente: ");
    fgets((*clientes + *contClientes)->numeroTelefone, 15, stdin);
    removerLinha((*clientes + *contClientes)->numeroTelefone);

    printf("Digite o nome do cliente: ");
    fgets((*clientes + *contClientes)->nome, 50, stdin);
    removerLinha((*clientes + *contClientes)->nome);

    printf("Digite o endereco do cliente: ");
    fgets((*clientes + *contClientes)->endereco, 50, stdin);
    removerLinha((*clientes + *contClientes)->endereco);

    printf("Digite o complemento do endereco do cliente: ");
    fgets((*clientes + *contClientes)->complemento, 15, stdin);
    removerLinha((*clientes + *contClientes)->complemento); 

    printf("Digite o CEP do endereco do cliente: ");
    fgets((*clientes + *contClientes)->CEP, 15, stdin);
    removerLinha((*clientes + *contClientes)->CEP);

    (*clientes + *contClientes)->totalGasto = 0;

    (*contClientes)++;
}

Pizza* validaPizza(Pizza *pizzas, char *saborPizza, const int contPizzas) {
    for (int i = 0; i < contPizzas; i++) {
        if (strcasecmp(pizzas->sabor, saborPizza) == 0) {
            return pizzas + i;
        }
    }

    return NULL;
}

Cliente* validaCliente(Cliente *clientes, char *numCliente, const int contClientes) {
    for (int i = 0; i < contClientes; i++) {
        if (strcasecmp(clientes->numeroTelefone, numCliente) == 0) {
            return clientes + i;
        }
    }

    return NULL;
}

void validaMotoboy(Motoboy **motoboys, int codigo) {
    Motoboy *aux = *motoboys;

    while (aux != NULL && aux->codigo != codigo) {
        aux = aux->prox;
    }

    if (aux == NULL) {
        Motoboy *novoMotoboy = (Motoboy*)malloc(sizeof(Motoboy));
        novoMotoboy->codigo = codigo;
        novoMotoboy->contEntregas = 1;
        novoMotoboy->prox = NULL;

        if (*motoboys == NULL) {
            *motoboys = novoMotoboy;
        } else {
            Motoboy *ultimo = *motoboys;
            while (ultimo->prox != NULL) {
                ultimo = ultimo->prox;
            }

            ultimo->prox = novoMotoboy;
        }
    } else {
        aux->contEntregas++;
    }

}

void fazerPedido(FilaDeEntrega *entregas, Cliente *clientes, Pizza *pizzas, Motoboy **motoboys, const int contPizzas, const int contClientes) {
    char numero[15], sabor[30];

    printf("Qual o numero de telefone do cliente que deseja fazer o pedido: ");
    fgets(numero, 15, stdin);
    removerLinha(numero);

    printf("Qual o sabor de pizza deseja comprar: ");
    fgets(sabor, 30, stdin);
    removerLinha(sabor);

    Cliente *cliente = validaCliente(clientes, numero, contClientes);
    Pizza *pizza = validaPizza(pizzas, sabor, contPizzas);

    if (cliente && pizza) {
        Pedido *novoPedido = (Pedido*)malloc(sizeof(Pedido));

        printf("Digite o numero do pedido: ");
        scanf("%d", &novoPedido->numeroPedido);

        printf("Digite o codigo do motoqueiro: ");
        scanf("%d", &novoPedido->codigoMotoboy);

        validaMotoboy(motoboys, novoPedido->codigoMotoboy);
    
        novoPedido->cliente = cliente;
        novoPedido->pizza = pizza;
        novoPedido->situacao = 1;
        novoPedido->prox = NULL;

        if (entregas->tamanho == 0) {
            entregas->primeiro = novoPedido;
            entregas->ultimo = novoPedido;
        } else {
            entregas->ultimo->prox = novoPedido;
            entregas->ultimo = novoPedido;
        }

        entregas->tamanho++;
    } else {
        printf("\nCliente ou Pizza nao cadastrados\n");
    }
}

void despachoPizza(FilaDeEntrega *entregas) {
    if (entregas->tamanho == 0) {
        printf("\nNao ha pizzas para serem despachadas\n");
        return;
    }

    if (entregas->primeiro->situacao == 1) {
        printf("\nPizza %s saindo para entrega ao cliente %s\n", entregas->primeiro->pizza->sabor, entregas->primeiro->cliente->nome);
        entregas->primeiro->situacao = 2;
    } else {
        printf("\nPizza %s ja esta a caminho do cliente %s, por favor espere a entrega\n", entregas->primeiro->pizza->sabor, entregas->primeiro->cliente->nome);
    }
}

void entregarPizza(FilaDeEntrega *entregas) {
    if (entregas->tamanho == 0) {
        printf("\nNao ha pizzas para serem entregues\n");
        return;
    }
    
    if (entregas->primeiro->situacao == 2) {
        printf("\nPizza %s entregue ao cliente %s\n", entregas->primeiro->pizza->sabor, entregas->primeiro->cliente->nome);
        entregas->primeiro->cliente->totalGasto += entregas->primeiro->pizza->valor;
        entregas->primeiro->situacao = 3;
        entregas->primeiro = entregas->primeiro->prox;
        entregas->tamanho--;
    } else {
        printf("\nPizza %s ainda esta em processo de preparo, por favor aguarde\n", entregas->primeiro->pizza->sabor);
    }
}

void mostrarEntregas(FilaDeEntrega *entregas) {
    Pedido *pedidos = entregas->primeiro;

    if (entregas->tamanho == 0) {
        printf("\nNao ha pizzas para serem entregues\n");
        return;
    }

    printf("\nEntregas:\n");
    while (pedidos != NULL) {
        if (pedidos->situacao == 1) {
            printf("Pizza %s ainda esta em processo de preparo, para o cliente %s\n", pedidos->pizza->sabor, pedidos->cliente->nome);
        } else if (pedidos->situacao == 2) {
            printf("Pizza %s ja esta a caminho do cliente %s, por favor espere a entrega\n", pedidos->pizza->sabor, pedidos->cliente->nome);
        } else {
            printf("Pizza %s entregue ao cliente %s\n", pedidos->pizza->sabor, pedidos->cliente->nome);
        }

        pedidos = pedidos->prox;
    }
}

void mostrarTotalGasto(Cliente *clientes, const int contClientes) {
    if (clientes == NULL) {
        printf("\nNenhum cliente cadastrado!\n");
        return;
    }
    
    printf("\nTotal gasto:\n");
    for (int i = 0; i < contClientes; i++) {
        printf("Pelo cliente '%s': %.2fR$\n", clientes[i].nome, clientes[i].totalGasto);
    }
}

void mostrarMotoboys(Motoboy *motoboys) {
    if (motoboys == NULL) {
        printf("\nNenhum motoqueiro cadastrado!\n");
        return;
    }
    
    Motoboy *maisEntregas = motoboys;
    
    printf("\nquantidade de entregas por motoqueiro:\n");
    while (motoboys != NULL) {
        printf("Motoqueiro %d: %d entregas\n", motoboys->codigo, motoboys->contEntregas);

        if (motoboys->contEntregas > maisEntregas->contEntregas) {
            maisEntregas = motoboys;
        }

        motoboys = motoboys->prox;
    }

    printf("\nMotoqueiro com mais entregas: %d\n", maisEntregas->codigo); 
}
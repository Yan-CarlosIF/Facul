#include <stdio.h>
#include "estruturas/q.15.c"

int main() {
    int contPizzas = 0, contClientes = 0, op;
    FilaDeEntrega *entregas = iniciarEntregas();
    Pizza *pizzas = NULL;
    Cliente *clientes = NULL;
    Motoboy *motoboys = NULL;

    do {
        printf("\n1 - Cadastrar Pizza\n2 - Cadastrar Cliente\n3 - Fazer Pedido\n4 - Despachar Pizza\n5 - Receber Pizza\n6 - Mostrar Total Gasto\n7 - Mostrar Entregas\n8 - Mostrar Codigo do Motoqueiro\n9 - Sair\nEscolha uma opcao: ");
        scanf("%d", &op);
        getchar();

        switch (op) {
            case 1:
                cadastrarPizza(&pizzas, &contPizzas);
                break;
            case 2:
                cadastrarCliente(&clientes, &contClientes);
                break;
            case 3:
                fazerPedido(entregas, clientes, pizzas, &motoboys, contPizzas, contClientes);
                break;
            case 4:
                despachoPizza(entregas);
                break;
            case 5:
                entregarPizza(entregas);
                break;
            case 6:
                mostrarTotalGasto(clientes, contClientes);
                break;
            case 7:
                mostrarEntregas(entregas);
                break;
            case 8:
                mostrarMotoboys(motoboys);
                break;
            case 9:
                printf("Saindo...\n");
                free(entregas);
                free(pizzas);
                free(clientes);
                free(motoboys);
                break;
            default:
                printf("Opção Invalida\n");
                break;
        }
    } while (op != 9);
    
    return 0;
}
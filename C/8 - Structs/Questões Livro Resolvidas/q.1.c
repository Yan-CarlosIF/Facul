#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_CONTAS 2

typedef struct 
{
    int numCliente;
    char nomeCliente[100];
    float saldoCliente;
} Conta;

void cadastrarConta(Conta *contas, int *totalContas);
void visualizarCliente(Conta *contas, int *totalContas);
void excluirConta(Conta *contas, int *totalContas);

int main()
{
    Conta contas[MAX_CONTAS];
    int totalContas = 0, op;

    do
    {
        printf("\nDigite:\n1 - Cadastrar Conta\n2 - Visualizar Contas\n3 - excluir conta com menor saldo\n4 - Sair\n");
        scanf("%d", &op);

        switch (op)
        {
            case 1:
                cadastrarConta(contas, &totalContas);
                break;
            case 2:
                visualizarCliente(contas, &totalContas);
                break;
            case 3:
                excluirConta(contas, &totalContas);
                break;
            case 4:
                printf("\nPrograma Encerrado");
                break;
            default:
                printf("\nOpcao inválida!");
        }
    } while (op != 4);

    return 0;
}

void cadastrarConta(Conta *contas, int *totalContas) 
{
    if (*totalContas >= MAX_CONTAS)
    {
        printf("\nTotal de contas atingido");
        return;
    }

    Conta nConta;
    printf("Digite o numero da conta:");
    scanf("%d", &nConta.numCliente);

    for (int i = 0; i < *totalContas; i++)
    {
        if (contas[i].numCliente == nConta.numCliente)
        {
            printf("\nErro ao cadastrar conta, Numero do cliente ja existente\n");
            return;
        }
    }

    printf("Digite o nome do cliente:");
    fflush(stdin);
    gets(nConta.nomeCliente);
    for (int i = 0; i < *totalContas; i++)
    {
        if (strcasecmp(contas[i].nomeCliente, nConta.nomeCliente) == 0)
        {
            printf("\nErro ao cadastrar conta, nome do cliente ja existente\n");
            return;
        }
    }
    printf("Insira o saldo da conta:");
    scanf("%f", &nConta.saldoCliente);

    contas[*totalContas] = nConta;
    (*totalContas)++;
    printf("\nConta cadastrada com sucesso");
}

void visualizarCliente(Conta *contas, int *totalContas)
{
    if (*totalContas == 0)
    {
        printf("\nNenhuma Conta Cadastrada!\n");
        return;
    }

    char nomeSearch[100];
    printf("Digite o nome da conta que deseja procurar: ");
    fflush(stdin);
    gets(nomeSearch);

    bool encontrou = false;

    for (int i = 0; i < *totalContas; i++)
    {
        if (strcasecmp(nomeSearch, contas[i].nomeCliente) == 0)
        {
            encontrou = true;
            printf("\nCliente numero %d", contas[i].numCliente);
            printf("\nNome: %s", contas[i].nomeCliente);
            printf("\nSaldo: %.2f\n", contas[i].saldoCliente);
            break;
        }
    }

    if (!encontrou)
    {
        printf("\ncliente com nome não cadastrado!\n");
    }
}

void excluirConta(Conta *contas, int *totalContas)
{
    if (*totalContas == 0)
    {
        printf("\nNenhuma Conta Cadastrada!\n");
        return;
    }

    int index = 0;

    for (int i = 0; i < *totalContas; i++)
    {
        if (contas[i].saldoCliente < contas[index].saldoCliente)
        {
            index = i;
        }
    }

    printf("\nConta de numero %d e saldo %.2f foi excluida!\n", contas[index].numCliente, contas[index].saldoCliente);

    for (int i = index; i < *totalContas - 1; i++)
    {
        contas[i] = contas[i + 1];
    }

    (*totalContas)--;
}
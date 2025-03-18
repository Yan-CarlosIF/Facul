#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Simulação de um Banco com Listas Ligadas e Fila de Atendimento

// Crie um programa que simule a operação de um banco.
// Estruturas necessárias:
// Clientes: com dados como nome, idade e número da conta.
// Conta: com saldo e histórico de operações (depósitos e retiradas).
// Use uma lista encadeada para armazenar os clientes e uma fila para simular a fila de atendimento.
// Implemente funções para:
// Adicionar e remover clientes.
// Realizar operações bancárias (depósito e retirada).
// Mostrar o saldo e o histórico de operações.
// Após o uso, libere toda a memória alocada.

typedef struct {
    float saldo;    
    char operacoes[1000];
} Conta;

typedef struct Cliente {
    char nome[50];
    int idade;
    int numeroConta;
    Conta conta;
    struct Cliente *prox;
} Cliente;

void addCliente(Cliente **clientes, char *nome, int idade, int numeroConta, float saldo);
void popCliente(Cliente **clientes, char *nome);
void operacoesBancarias(Cliente **clientes, int numRemetente, int numDestinatario);
void mostrarConta(Cliente *clientes);
void freeLista(Cliente **clientes);

int main() {
    Cliente *clientes = NULL;
    int op;

    do {
        printf("\nInsira:\n1 - Cadastrar cliente\n2 - Deletar cliente\n3 - Realizar operacoes bancarias\n4 - Exibir saldo e historico\n5 - Sair\nEscolha uma opcao:");
        scanf("%d", &op);
        getchar();

        switch (op) {
            case 1: {
                float saldo;
                int idade, numConta;
                char nome[50];
            
                printf("\nDigite o nome do cliente:");
                fgets(nome, 50, stdin);
                nome[strcspn(nome, "\n")] = '\0';

                printf("Digite a sua idade:");
                scanf("%d", &idade);

                printf("Digite o numero da conta:");
                scanf("%d", &numConta);

                printf("Digite o seu saldo:");
                scanf("%f", &saldo);

                addCliente(&clientes, nome, idade, numConta, saldo);

                break;
            }
            case 2: {
                char nomeCliente[50];
                printf("\nInsira o nome do cliente que deseja excluir:");
                fgets(nomeCliente, 50, stdin);
                nomeCliente[strcspn(nomeCliente, "\n")] = '\0';

                popCliente(&clientes, nomeCliente);
                break;
            }
            case 3: {
                int numRemetente, numDestinatario;

                printf("\nDigite o numero da conta do remetente:");
                scanf("%d", &numRemetente);

                printf("Digite o numero da conta do destinatario:");
                scanf("%d", &numDestinatario);
                
                operacoesBancarias(&clientes, numRemetente, numDestinatario);
                break;
            }
            case 4:
                mostrarConta(clientes);
                break;
            case 5:
                printf("\nEncerrando o programa...\n");
                freeLista(&clientes);
                break;
            default:
                printf("\nOpcao invalida!\n");
        }
    } while (op != 5);    

    return 0;
}

void addCliente(Cliente **clientes, char *nome, int idade, int numeroConta, float saldo) {
    
    Cliente *novoCliente = (Cliente *)malloc(sizeof(Cliente));
    novoCliente->idade = idade;
    strcpy(novoCliente->nome, nome);
    novoCliente->numeroConta = numeroConta;
    strcpy(novoCliente->conta.operacoes, "\0"); 
    novoCliente->conta.saldo = saldo;
    novoCliente->prox = NULL;

    if (*clientes == NULL) {
        *clientes = novoCliente;
        return;
    } 

    Cliente *aux = *clientes;
    while (aux->prox != NULL) {
        if (aux->numeroConta == numeroConta) {
            printf("Erro: Numero da conta ja existe.\n");
            free(novoCliente);  // Libera o cliente recém-alocado
            return;
        }
        aux = aux->prox;
    }

    if (aux->numeroConta == numeroConta) {
        printf("Erro: Numero da conta ja existe.\n");
        free(novoCliente);  // Libera o cliente recém-alocado
        return;
    }

    aux->prox = novoCliente;
}

void popCliente(Cliente **clientes, char *nome) {
    if (*clientes == NULL) {
        printf("\nErro: Lista vazia!\n");
        return;
    }
    
    Cliente *aux = *clientes;

    if (stricmp(aux->nome, nome) == 0) {
        *clientes = aux->prox;
        free(aux);
        printf("\nCliente excluido com exito!\n");
        return;
    }

    while (aux != NULL && stricmp(aux->prox->nome, nome) != 0) aux = aux->prox;
    
    if (aux != NULL) {
        Cliente *excluido = aux->prox;
        aux->prox = aux->prox->prox;
        free(excluido);
        printf("\nCliente excluido com exito!\n");
    } else {
        printf("\nErro: Cliente nao encontrado!\n");
    }
}

void operacoesBancarias(Cliente **clientes, int numRemetente, int numDestinatario) {
    Cliente *remetente = NULL, *destinatario = NULL, *aux = *clientes;

    while (aux != NULL) {
        if (aux->numeroConta == numRemetente) {
            remetente = aux;
        }

        if (aux->numeroConta == numDestinatario) {
            destinatario = aux;
        } 

        aux = aux->prox;
    }

    if (remetente != NULL && destinatario != NULL) {
        float transferencia;
        printf("Quanto deseja transferir:");
        scanf("%f", &transferencia);

        if (transferencia >= 0 && transferencia <= remetente->conta.saldo) {
            remetente->conta.saldo -= transferencia;
            destinatario->conta.saldo += transferencia;

            char buffer[100]; // Buffer temporário para armazenar a mensagem formatada
            snprintf(buffer, sizeof(buffer), "Transferencia de %.2fR$ para %s feita com sucesso\n", transferencia, destinatario->nome);
            
            if (strcmp(remetente->conta.operacoes, "\0") == 0) {
                strcpy(remetente->conta.operacoes, buffer);
            } else {
                strcat(remetente->conta.operacoes, buffer);
            }

            snprintf(buffer, sizeof(buffer), "Transferencia de %.2fR$ de %s recebida com sucesso\n", transferencia, remetente->nome);

            if (strcmp(destinatario->conta.operacoes, "\0") == 0) {
                strcpy(destinatario->conta.operacoes, buffer);
            } else {
                strcat(destinatario->conta.operacoes, buffer);
            }

            printf("\nTransferencia concluida com exito!\n");
        } else {
            printf("\nSaldo insuficiente!\n");
        }
    } else {
        printf("\nClientes Invalidos!\n");
    }
}

void mostrarConta(Cliente *clientes) {
    if (clientes == NULL) {
        printf("\nErro: Lista vazia!\n");
        return;
    }
    
    int op;

    do {
        printf("\nDeseja exibir todos, ou um cliente em especifico?\n1 - Todos\n2 - Um cliente\nEscolha uma opcao:");
        scanf("%d", &op);
    } while (op < 1 || op > 2);

    Cliente *aux = clientes;
    switch (op) {
        case 1:
            while (aux != NULL) {
                printf("\nConta:\nNome do cliente: %s\nidade: %d\nNumero da conta: %d\nSaldo: %.2fR$\n", aux->nome, aux->idade, aux->numeroConta, aux->conta.saldo);

                if (strcmp(aux->conta.operacoes, "\0") == 0) {
                    printf("\nNenhuma operacao feita!\n");
                } else {
                    printf("\nOperacoes:\n%s", aux->conta.operacoes);
                }
                aux = aux->prox;
            }
            break;
        case 2: {
            int numConta;

            printf("Digite o numero da conta que deseja exibir:");
            scanf("%d", &numConta);

            while (aux != NULL && aux->numeroConta != numConta) aux = aux->prox;
            
            if (aux != NULL) {
                printf("\nConta:\nNome do cliente: %s\nidade: %d\nNumero da conta: %d\nSaldo: %.2fR$\n", aux->nome, aux->idade, aux->numeroConta, aux->conta.saldo);

                if (strcmp(aux->conta.operacoes, "\0") == 0) {
                    printf("\nNenhuma operacao feita!\n");
                    break;
                } else {
                    printf("\nOperacoes:\n%s", aux->conta.operacoes);
                }
            } else {
                printf("\nNumero da conta inexistente!\n");
            }
            break;
        }
    }
}

void freeLista(Cliente **clientes) {
    Cliente *aux = *clientes;
    while (aux != NULL) {
        Cliente *temp = aux;
        aux = aux->prox;
        free(temp);
    }
    *clientes = NULL;
}
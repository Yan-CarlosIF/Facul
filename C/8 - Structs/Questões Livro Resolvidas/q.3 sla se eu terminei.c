#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*Faça um programa que utilize os registros a seguir. 

g) Alterar as informações sobre os clientes — só não pode ser alterado o código do cliente.

h) Mostrar o total de documentos de determinado cliente.

i) Sair. 

Quando forem excluídos clientes ou documentos, os vetores deverão ser reorganizados, ou seja, todas 
as posições não preenchidas dos vetores deverão ficar no final. Exemplo: se for necessário excluir o número 
8 do vetor a seguir, tanto o 9 quanto o 1 deverão ser movidos uma casa para a esquerda e a última posição 
deverá ficar livre para uma nova inclusão.

Vetor inicial
12 5 8 9 1

Vetor modificado com uma 
posição livre ao final
12 5 9 1
*/


 
// Considere que podem existir, no máximo, 15 clientes e 30 documentos. Crie um vetor para clientes e outro para documentos
#define MAX_CLIENTES 15
#define MAX_DOCUMENTOS 30

typedef struct {
    int cod_cliente;
    char nome[50];
    char fone[15];
    char endereco[50];
} Cliente;

typedef struct {
    int num_doc;
    int cod_cliente;
    char data_venc[11];
    char data_pagamento[11];
    float valor;
    float juros;
} Documento;

bool comparaDatas(const char *data_pag, const char *data_venc);
void cadastrarClientes(Cliente *clientes, int *total_clientes);
void cadastrarDocumentos(Documento *documentos, Cliente *clientes, const int total_clientes, int *total_documentos);
void excluirCliente(Documento *documentos, Cliente *clientes, int *total_clientes, const int total_documentos);
void excluirDocumentos(Documento *documentos, Cliente  *clientes, const int total_clientes, int *total_documentos);
void exibirDocumentos(Documento *documentos, Cliente *clientes, const int total_clientes, const int total_documentos);
void exibirClientes(Cliente *clientes, const int total_clientes);

int main() {
    Cliente clientes[MAX_CLIENTES] = {0}; 
    Documento documentos[MAX_DOCUMENTOS] = {0};
    int total_clientes = 0, total_documentos = 0, op;
    
     
    // Crie um menu para a realização de cada uma das operações especificadas a seguir
    do {
        printf("\nDigite:\n1 - Cadastrar Cliente\n");
        printf("2 - Cadastrar Documentos\n"); 
        printf("3 - Excluir Cliente\n");
        printf("4 - Excluir Documentos\n");
        printf("5 - Exibir documentos\n");
        printf("7 - Exibir Clientes\n");
        printf("0 - Sair.\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &op);

        switch (op) {
            case 0:
                printf("\nPrograma Encerrado!\n");
                break;
            case 1:
                cadastrarClientes(clientes, &total_clientes);
                break;
            case 2:
                cadastrarDocumentos(documentos, clientes, total_clientes, &total_documentos);
                break;
            case 3: 
                excluirCliente(documentos, clientes, &total_clientes, total_documentos);
                break;
            case 4:
                excluirDocumentos(documentos, clientes, total_clientes, &total_documentos);
                break;
            case 5:
                exibirDocumentos(documentos, clientes, total_clientes, total_documentos);
                break;
            case 7:
                exibirClientes(clientes, total_clientes);
                break;
            default:
                printf("\nOpcao invalida!\n");
                break;
        }
    } while (op != 0);
    return 0;
}

bool comparaDatas(const char *data_pag, const char *data_venc) {
    if (strcmp(data_venc, data_pag) < 0) {
        return true;
    }
    return false;
}

// a) Cadastrar clientes — não pode existir mais que um cliente com o mesmo código.
void cadastrarClientes(Cliente *clientes, int *total_clientes) {
    int codigo;
    printf("Digite o codigo do cliente:");
    scanf("%d", &codigo);

    if (*total_clientes > 0) {
        for (int i = 0; i < *total_clientes; i++) {
            if (codigo == clientes[i].cod_cliente) {
                printf("\nCodigo do cliente ja existente!\n");
                return;
            }
        }
    }

    clientes[*total_clientes].cod_cliente = codigo;
    printf("Digite o nome do cliente:");
    fflush(stdin);
    gets(clientes[*total_clientes].nome);

    printf("Digite o telefone do cliente:");
    fflush(stdin);
    gets(clientes[*total_clientes].fone);

    printf("Digite o endereco do cliente:");
    fflush(stdin);
    gets(clientes[*total_clientes].endereco);

    (*total_clientes)++;
    printf("\nCliente cadastrado com sucesso!\n");
}

// Sabe-se que um documento só pode ser cadastrado para um cliente que já exista. 
// b) Cadastrar documentos — ao cadastrar um documento, se a data de pagamento for maior que a data de vencimento, 
// calcular o campo ‘juros’ do registro documentos (5% sobre o valor original do documento).
void cadastrarDocumentos(Documento *documentos, Cliente *clientes, const int total_clientes, int *total_documentos) {
    if (total_clientes == 0) {
        printf("\nNenhum Cliente Cadastrado!\n");
        return;
    } 

    int codigo;
    printf("Digite o codigo do cliente:");
    scanf("%d", &codigo);

    for (int i = 0; i < total_clientes; i++) {
        if (codigo == clientes[i].cod_cliente) {
            documentos[*total_documentos].cod_cliente = codigo;

            printf("Digite o numero do documento:");
            scanf("%d", &documentos[*total_documentos].num_doc);
            
            printf("Digite a data de vencimento:");
            fflush(stdin);
            gets(documentos[*total_documentos].data_venc);

            printf("Digite a data de pagamento:");
            fflush(stdin);
            gets(documentos[*total_documentos].data_pagamento);

            printf("Digite o valor do documento:");
            scanf("%f", &documentos[*total_documentos].valor);

            if (comparaDatas(documentos[*total_documentos].data_pagamento, documentos[*total_documentos].data_venc)) {
                documentos[*total_documentos].juros = documentos[*total_documentos].valor * 0.05; 
                // printf("\nTem juros!\n");
            } else {
                documentos[*total_documentos].juros = 0;
                // printf("\nNao tem juros!\n");
            }

            (*total_documentos)++;
            return;
        }
    }

    printf("\nCodigo do cliente inexistente!\n");
}

// c) Excluir clientes — um cliente só poderá ser excluído se não existir nenhum documento associado a ele.
void excluirCliente(Documento *documentos, Cliente *clientes, int *total_clientes, const int total_documentos) {
    int codigo, i;
    bool cliente_encontrado = false;
    printf("Digite o codigo do cliente que deseja excluir:");
    scanf("%d", &codigo);
    

    for (i = 0; i < *total_clientes; i++) {
        if (codigo == clientes[i].cod_cliente) {
            cliente_encontrado = true;
            for (int j = 0; j < total_documentos; j++) {
                if (codigo == documentos[j].cod_cliente) {
                    printf("\nFalha da exclusao, existem documentos atribuidos ao cliente\n");
                    return;
                }
            }
            break;
        }
    }

    if (!cliente_encontrado) {
        printf("\nCliente nao encontrado!\n");
        return;
    }

    for (int j = i; j < *total_clientes - 1; j++) {
        clientes[j] = clientes[j + 1];
    }

    (*total_clientes)--;
    printf("\nCliente excluido com sucesso!\n");
}

// d) Excluir documentos individuais — por meio de seu número. Caso o documento não exista, o programa deverá 
// mostrar a mensagem Documento não encontrado. 

// e) Excluir documentos por cliente — o programa deverá informar o código do cliente e excluir todos os seus 
// documentos. Caso o cliente não exista, deverá mostrar a mensagem Cliente não encontrado. 

// f) Excluir documentos por período — o programa deverá informar a data inicial e a data final e excluir todos os 
// documentos que possuam data de vencimento nesse período.
void excluirDocumentos(Documento *documentos, Cliente  *clientes, const int total_clientes, int *total_documentos) {
    int opcao;

    do {
        printf("\nDigite a forma que deseja excluir o documento:\n");
        printf("1 - Individuais\n2 - Por cliente\n3 - Por periodo\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
    } while (opcao < 1 || opcao > 3);

    switch (opcao) {
        case 1: {
            int num_doc, i;
            bool doc_encontrado = false;
            printf("Digite o numero do documento que deseja excluir:");
            scanf("%d", &num_doc);

            for (i = 0; i < *total_documentos; i++) {
                if (documentos[i].num_doc == num_doc) {
                    doc_encontrado = true;
                    break;
                }
            }

            if (!doc_encontrado) {
                printf("\nDocumento nao encontrado!");
                return;
            }

            for (int j = i; j < *total_documentos - 1; j++) {
                documentos[j] = documentos[j + 1];
            }

            (*total_documentos)--;
            printf("\nDocumento excluido com sucesso!\n");
            break;
        }
        case 2: {
            int codigo, i;
            bool cliente_encontrado = false;
            printf("Digite o codigo do cliente que deseja excluir os documentos:");
            scanf("%d", &codigo);
            

            for (i = 0; i < total_clientes; i++) {
                if (codigo == clientes[i].cod_cliente) {
                    cliente_encontrado = true;
                    for (int j = 0; j < *total_documentos; j++) {
                        if (codigo == documentos[j].cod_cliente) {
                            for (int k = j; k < *total_documentos - 1; k++) {
                                documentos[k] = documentos[k + 1];
                            }
                            (*total_documentos)--;
                        }
                    }
                }
            }

            if (!cliente_encontrado) {
                printf("\nCliente nao encontrado!\n");
                return;
            }

            printf("\nDocumentos do cliente N%d excluido com sucesso!\n", codigo);
            break;
        }     
        case 3: {

        }
            break;
        default:
            break;
    }
}

void exibirDocumentos(Documento *documentos, Cliente *clientes, const int total_clientes, const int total_documentos) {
    int codigo;
    bool cliente_encontrado = false;
    printf("\nDigite o cliente que deseja exibir os documentos:");
    scanf("%d", &codigo);

    for (int i = 0; i < total_clientes; i++) {
        if (clientes[i].cod_cliente == codigo) {
            cliente_encontrado = true;
            for (int j = 0; j < total_documentos; j++) {
                if (documentos[j].cod_cliente == codigo) {
                    printf("documento %d:\ncodigo do documento: %d\nvalor: %.2f\n", i + 1, documentos[j].num_doc, documentos[j].valor);
                }
            }
        }
    }

    if (!cliente_encontrado) {
        printf("\nCliente nao encontrado!\n");
        return;
    }
}

void exibirClientes(Cliente *clientes, const int total_clientes) {
    printf("\nClientes:\n");
    for (int i = 0; i < total_clientes; i++) {
        printf("Nome do cliente %d: %s\n", i + 1, clientes[i].nome);
        printf("Codigo do cliente %d: %d\n\n", i + 1, clientes[i].cod_cliente);
    }
}
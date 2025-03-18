#include <stdio.h>
#include <stdbool.h>

#define MAX_SERVICOS 3
#define DAYS 30
#define MAX_TIPOS 1

// Cadastre os quatro tipos de serviços (código e descrição) que a empresa poderá realizar. Para isso, utilize um vetor de quatro posições.
typedef struct
{
    int codigo;
    char descricao[50];
} Tipos;

// Cada serviço realizado deve ser cadastrado com as seguintes informações: número do serviço, valor do serviço, código do serviço e código do cliente.
typedef struct
{
    int numServico;
    float valor;
    int codigoServico;
    int codigoCliente;
} Servicos;

void cadastrarTipoServico(Tipos *TipoServicos);
void cadastrarServico(Servicos (*historico)[MAX_SERVICOS], Tipos *tiposServicos);
void mostrarServicosPorDia(Servicos (*historico)[MAX_SERVICOS], Tipos *tiposServicos);
void mostrarServicosIntervalo(Servicos (*historico)[MAX_SERVICOS], Tipos *tiposServicos);
void mostrarRelatorio(Servicos (*historico)[MAX_SERVICOS], Tipos *tiposServicos);

int main()
{
    Servicos historico[DAYS][MAX_SERVICOS] = {0};
    Tipos tiposServicos[MAX_TIPOS] = {0};
    int op;

    // O programa deverá mostrar o seguinte menu de opções:
    // 1. Cadastrar os tipos de serviços.
    // 2. Cadastrar os serviços prestados.
    // 3. Mostrar os serviços prestados em determinado dia.
    // 4. Mostrar os serviços prestados dentro de um intervalo de valor.
    // 5. Mostrar um relatório geral (separado por dia), que exiba, inclusive, a descrição do tipo do serviço.
    // 6. Finalizar.
    do
    {
        printf("Digite:\n1 - Cadastrar os tipos de servicos\n");
        printf("2 - Cadastrar os servicos prestados\n");
        printf("3 - Mostrar os servicos prestados em determinado dia\n");
        printf("4 - Mostrar os servicos prestados dentro de um intervalo de valor\n");
        printf("5 - Mostrar um relatorio geral\n");
        printf("6 - Finalizar\n");
        printf("Escolha uma opcao:");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            cadastrarTipoServico(tiposServicos);
            break;
        case 2:
            cadastrarServico(historico, tiposServicos);
            break;
        case 3:
            mostrarServicosPorDia(historico, tiposServicos);
            break;
        case 4:
            mostrarServicosIntervalo(historico, tiposServicos);
            break;
        case 5:
            mostrarRelatorio(historico, tiposServicos);
            break;
        case 6:
            printf("Finalizando o programa...\n");
            break;
        default:
            printf("Opcao invalida!\n");
        }
    } while (op != 6);

    return 0;
}

// Para a opção 1: deve-se cadastrar os tipos de serviços oferecidos pela empresa, com código e descrição.
void cadastrarTipoServico(Tipos *tipoServicos)
{
    printf("\nCadastro dos tipos de servicos:\n");
    for (int i = 0; i < MAX_TIPOS; i++)
    {
        printf("Digite o codigo do servico %d:", i + 1);
        scanf("%d", &tipoServicos[i].codigo);
        printf("Digite a descricao do servico %d:", i + 1);
        getchar();
        gets(tipoServicos[i].descricao);
    }
}

void cadastrarServico(Servicos (*historico)[MAX_SERVICOS], Tipos *tiposServicos)
{
    int dia, contServicos = 0;

    printf("\nDigite o dia que deseja cadastrar (1 a 30): ");
    scanf("%d", &dia);

    if (dia < 1 || dia > 30)
    {
        printf("\nDia invalido!\n");
        return;
    }

    for (int i = 0; i < MAX_SERVICOS; i++)
    {
        if (historico[dia - 1][i].codigoCliente != 0)
        {
            contServicos++;
        }
    }

    if (contServicos >= MAX_SERVICOS)
    {
        printf("\nQuantidade maxima de servicos atingida no dia %d!\n", dia);
        return;
    }

    int i = contServicos;

    printf("Digite o numero do servico:");
    scanf("%d", &historico[dia - 1][i].numServico);
    printf("Digite o valor do servico: ");
    scanf("%f", &historico[dia - 1][i].valor);
    printf("Digite o codigo do servico: ");
    scanf("%d", &historico[dia - 1][i].codigoServico);

    bool servicoValido = false;
    for (int j = 0; j < MAX_TIPOS; j++)
    {
        if (historico[dia - 1][i].codigoServico == tiposServicos[j].codigo)
        {
            servicoValido = true;
            break;
        }
    }

    if (!servicoValido)
    {
        printf("\nCodigo de servico invalido!\n");
        return;
    }

    do
    {
        printf("Digite o codigo do cliente:");
        scanf("%d", &historico[dia - 1][i].codigoCliente);
    } while (historico[dia - 1][i].codigoCliente == 0);

    printf("\nCadastro do servico %d para o dia %d concluido com sucesso!\n", contServicos + 1, dia);
}

// Para a opção 3: o programa deverá receber o dia que se deseja consultar e mostrar os respectivos serviços prestados.
void mostrarServicosPorDia(Servicos (*historico)[MAX_SERVICOS], Tipos *tiposServicos)
{
    int dia;

    printf("\nDigite o dia que deseja consultar:");
    scanf("%d", &dia);

    if (dia < 1 || dia > 30)
    {
        printf("\nDia invalido!\n");
        return;
    }

    printf("\nDia %d:\n", dia);
    for (int i = 0; i < MAX_SERVICOS; i++)
    {
        if (historico[dia - 1][i].codigoCliente != 0)
        {
            printf("\nServico %d:\n", i + 1);
            printf("Numero do servico: %d\n", historico[dia - 1][i].numServico);
            printf("Valor: %.2f\n", historico[dia - 1][i].valor);
            printf("Codigo do cliente: %d\n", historico[dia - 1][i].codigoCliente);
            for (int j = 0; j < MAX_TIPOS; j++)
            {
                if (historico[dia - 1][i].codigoServico == tiposServicos[j].codigo)
                {
                    printf("Tipo do servico: %s\n", tiposServicos[j].descricao);
                    break;
                }
            }
            printf("\n");
        }
    }
}

// Para a opção 4: o programa deverá receber o valor mínimo e o valor máximo e mostrar os serviços prestados que estiverem nesse intervalo.
void mostrarServicosIntervalo(Servicos (*historico)[MAX_SERVICOS], Tipos *tiposServicos)
{
    float min, max;

    printf("Digite o valor minimo:");
    scanf("%f", &min);
    printf("Digite o valor maximo:");
    scanf("%f", &max);

    if (min > max)
    {
        float aux = min;
        min = max;
        max = aux;
    }

    for (int dia = 0; dia < DAYS; dia++)
    {
        for (int i = 0; i < MAX_SERVICOS; i++)
        {
            if (historico[dia][i].codigoCliente != 0 && historico[dia][i].valor >= min && historico[dia][i].valor <= max)
            {
                printf("\nDia %d:\n", dia + 1);
                printf("\nServico %d:\n", i + 1);
                printf("Numero do servico: %d\n", historico[dia][i].numServico);
                printf("Valor: %.2f\n", historico[dia][i].valor);
                printf("Codigo do cliente: %d\n", historico[dia][i].codigoCliente);
                for (int j = 0; j < MAX_TIPOS; j++)
                {
                    if (historico[dia][i].codigoServico == tiposServicos[j].codigo)
                    {
                        printf("Tipo do servico: %s\n", tiposServicos[j].descricao);
                        break;
                    }
                }
                printf("\n");
            }
        }
    }
}

// Para a opção 5: o programa deverá mostrar todos os serviços prestados, conforme o exemplo a seguir.
void mostrarRelatorio(Servicos (*historico)[MAX_SERVICOS], Tipos *tiposServicos)
{
    printf("\nRelatorio:\n");
    for (int dia = 0; dia < DAYS; dia++)
    {
        printf("\nDia %d:\n", dia + 1);
        for (int i = 0; i < MAX_SERVICOS; i++)
        {
            if (historico[dia][i].codigoCliente != 0)
            {
                printf("\nServico %d:\n", i + 1);
                printf("Numero do servico: %d\n", historico[dia][i].numServico);
                printf("Valor: %.2f\n", historico[dia][i].valor);
                printf("Codigo do cliente: %d\n", historico[dia][i].codigoCliente);
                for (int j = 0; j < MAX_TIPOS; j++)
                {
                    if (historico[dia][i].codigoServico == tiposServicos[j].codigo)
                    {
                        printf("Tipo do servico: %s\n", tiposServicos[j].descricao);
                        break;
                    }
                }
                printf("\n");
            }
        }
    }
}
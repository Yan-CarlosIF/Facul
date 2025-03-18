#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int dia;
    int mes;
    int ano;
} Data; // Estrutura criada para armazenar data

typedef struct {
    char nome[50];
    float salario;
    Data dataAdmissao;
    float porcentagemAumento;
} Funcionario;

void inserirInformacoes(Funcionario *func); // Função criada para evitar repeticao de codigo
void addFuncionario(Funcionario **func, int *tam); /// Função para adicionar funcionario
void inserirDataFutura(Funcionario *func, char *nome, const int tam); /// Função para inserir data futura e calcular salario

int main() {
    Funcionario *funcionarios = NULL;

    int tamanho, op;
    
    // Alocar com pelo menos 1 funcionario
    do {
        printf("Digite quantos funcionarios deseja cadastrar:");
        scanf("%d", &tamanho);
    } while (tamanho < 1);
    getchar();
    
    funcionarios = (Funcionario*)malloc(sizeof(Funcionario) * tamanho); // alocação inicial de memoria

    // Receber informações dos funcionarios
    for (int i = 0; i < tamanho; i++) {
        inserirInformacoes(funcionarios + i);
    }
    
    // Menu de opcoes
    do {
        printf("\nDigite:\n0 - Sair\n1 - Inserir novos funcionarios\n2 - Inserir uma data futura\nInsira: ");
        scanf("%d", &op);
        getchar();

        switch (op) {
            case 0:
                printf("\nFinalizando o programa...\n");
                free(funcionarios); // Liberando memoria alocada
                break;
            case 1:
                addFuncionario(&funcionarios, &tamanho);
                break;
            case 2: {
                char nome[50];

                printf("Digite o nome do funcionario que deseja procurar:");
                fgets(nome, 50, stdin);
                nome[strcspn(nome, "\n")] = '\0'; // Função para excluir o '\n' do final da string e trocar por '\0'

                inserirDataFutura(funcionarios, nome, tamanho);     
                break;
            }
            default:    
                printf("\nOpcao invalida");
                break;
        }
    } while(op != 0);
    
    return 0;
}

// Função criada para evitar repeticao de codigo e receber informacoes do funcionario
void inserirInformacoes(Funcionario *func) {
    printf("\nInsira o nome do funcionario:");
    fgets(func->nome, 50, stdin);
    func->nome[strcspn(func->nome, "\n")] = '\0';

    // do-while para receber uma data válida!
    do {
        printf("Insira a data (dd/mm/aaaa) de admissao do funcionario '%s':", func->nome);
        scanf("%d/%d/%d", &func->dataAdmissao.dia, &func->dataAdmissao.mes, &func->dataAdmissao.ano);
    } while (func->dataAdmissao.dia < 1 || func->dataAdmissao.dia > 31 || func->dataAdmissao.mes < 1 || 
             func->dataAdmissao.mes > 12 || func->dataAdmissao.ano < 1 || func->dataAdmissao.ano > 9999);

    printf("Insira o salario do funcionario:");
    scanf("%f", &func->salario);

    printf("Insira a porcentagem de aumento do funcionario:");
    scanf("%f", &func->porcentagemAumento); 
    getchar();
}

void addFuncionario(Funcionario **func, int *tam) {
    int i = *tam; // varivel criada para armazenar o indice do ultimo funcionario
    (*tam)++; // aumenta a quantidade de funcionarios
    *func = (Funcionario*)realloc(*func, sizeof(Funcionario) * (*tam)); // Realoca a memoria para adicionar mais um funcionario

    if (*func == NULL) {
        printf("\nMemoria insuficiente!");
        exit(1); // exit(1) para encerrar o programa imediatamente se a memoria for insuficiente  
    }

    inserirInformacoes(*func + i);
    printf("\n");
}

void inserirDataFutura(Funcionario *func, char *nome, const int tam) {
    int i; // variavel criada fora do for para ser utilizada apos o loop
    
    // procurar o funcionario com o nome desejado
    for (i = 0; i < tam; i++) {
        if (strcasecmp((*(func + i)).nome, nome) == 0) {
            break;  
        }
    }   

    // se o indice for menor que o tamanho, significa que o funcionario foi encontrado
    if (i < tam) {
        float salarioFuturo = (*(func + i)).salario;
        int dia, mes, ano;
        
        // do-while para receber uma data válida!
        do {
            printf("\nDigite uma data (dd/mm/aaaa) futura que deseja saber o salario do funcionario '%s':", (*(func + i)).nome);
            scanf("%d/%d/%d", &dia, &mes, &ano);
        } while (dia < 1 || dia > 31 || mes < 1 || mes > 12 || ano < 1 || ano > 9999);
        
        if ((*(func + i)).dataAdmissao.ano < ano) {
            // Percorre do ano da admissao ate o ano futuro desejado
            for (int j = (*(func + i)).dataAdmissao.ano; j < ano; j++) {
                salarioFuturo += (salarioFuturo * ((*(func + i)).porcentagemAumento / 100));
            }
            printf("\nSalario do funcionario '%s' em %02d/%02d/%d: %.2fR$\n", (*(func + i)).nome, dia, mes, ano, salarioFuturo);
        } else {
            printf("\nData recebida menor que a data de admissao!");
        }
    } else {
        printf("\nFuncionario nao encontrado!\n");
    }
}
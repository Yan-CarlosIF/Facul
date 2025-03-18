#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define SALARIO_MIN 550

typedef struct {
    char nome[50];
    int horasTrabalhadas;
    char turno;
    char categoria;
    float valorHora;
} Funcionario;

void removerLinha(char *str);
bool validaTurno(Funcionario *func);
bool validaCategoria(Funcionario *func);
void cadastrarFuncionario(Funcionario **funcs, int *tam);
float calculaSalario(Funcionario *func);
void exibirFolhaPagamento(Funcionario *funcs, const int tam);

int main() {
    Funcionario *funcionarios = NULL;
    int op, tam = 0;
    
    do {
        printf("\nDigite:\n1 - Cadastrar Funcionarios\n2 - Mostrar Folha de Pagamento\n3 - Sair\n");
        scanf("%d", &op);
        getchar();

        switch (op) {
            case 1:
                // Cadastrar Funcionários
                cadastrarFuncionario(&funcionarios, &tam);
                break;
            case 2:
                // Mostrar Folha de Pagamento
                exibirFolhaPagamento(funcionarios, tam);
                break;
            case 3:
                printf("\nPrograma Encerrado");
                free(funcionarios);
                break;
            default:
                printf("\nOpcao invalida!");
        }
    } while (op != 3);

    return 0;
}

void removerLinha(char *str) {
    str[strcspn(str, "\n")] = '\0';
}

bool validaTurno(Funcionario *func) {
    return func->turno != 'M' && func->turno != 'V' && func->turno != 'N' && func->turno != 'm' && func->turno != 'v' && func->turno != 'n';
}

bool validaCategoria(Funcionario *func) {    
    return func->categoria != 'O' && func->categoria != 'G' && func->categoria != 'o' && func->categoria != 'g';
}

void cadastrarFuncionario(Funcionario **funcs, int *tam) {
    if (*tam == 0) {
        *funcs = (Funcionario*)malloc(sizeof(Funcionario));
    } else {
        *funcs = (Funcionario*)realloc(*funcs, sizeof(Funcionario) * (*tam + 1));
    }


    printf("Digite o nome do funcionario: ");
    fgets((*funcs + *tam)->nome, 50, stdin);
    removerLinha((*funcs + *tam)->nome);

    printf("Insira as informacoes sobre o funcionario '%s':\n", (*funcs + *tam)->nome);
    printf("Numero de horas trabalhas: ");
    scanf("%d", &(*funcs + *tam)->horasTrabalhadas);
    getchar();

    do {
        printf("Turno de trabalho (M - matutino V - vespertino ou N - noturno): ");
        scanf("%c", &(*funcs + *tam)->turno);
        getchar();
    } while (validaTurno((*funcs + *tam)));

    do {
        printf("Categoria (O - operario ou G - gerente): ");
        scanf("%c", &(*funcs + *tam)->categoria);
        getchar();
    } while (validaCategoria((*funcs + *tam)));

    if ((*funcs + *tam)->categoria == 'G' || (*funcs + *tam)->categoria == 'g') {
        if ((*funcs + *tam)->turno == 'n' || (*funcs + *tam)->turno == 'N') {
            (*funcs + *tam)->valorHora = SALARIO_MIN * 0.18;
        } else {
            (*funcs + *tam)->valorHora = SALARIO_MIN * 0.15;
        }
    } else {
        if ((*funcs + *tam)->turno == 'n' || (*funcs + *tam)->turno == 'N') {
            (*funcs + *tam)->valorHora = SALARIO_MIN * 0.13;
        } else {
            (*funcs + *tam)->valorHora = SALARIO_MIN * 0.10;
        }
    }

    (*tam)++;
}

float calculaSalario(Funcionario *func) {
    float salario = func->horasTrabalhadas * func->valorHora;
    
    if (salario <= SALARIO_MIN) {
        salario += salario * 0.2; 
    } else if (salario < 800) {
        salario += salario * 0.15;
    } else {
        salario += salario * 0.05;
    }

    return salario;
}

void exibirFolhaPagamento(Funcionario *funcs, const int tam) {
    float total = 0;

    for (int i = 0; i < tam; i++) {
        printf("\n%d Funcionario: %s", i + 1, funcs[i].nome);
        printf("\nHoras trabalhadas: %d", (funcs + i)->horasTrabalhadas);
        printf("\nValor da hora trabalhada: %.2fR$", (funcs + i)->valorHora);
        printf("\nSalario: %.2fR$\n", calculaSalario(funcs + i));
        total += calculaSalario(funcs + i);
    }

    printf("\nTotal da folha de pagamento: %.2fR$\n", total);
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Pessoa {
    char nome[50];
    char sobrenome[50];
    int idade;
    struct Pessoa *amigo;
} Pessoa;

void preencherPessoas(Pessoa *pessoas, const int tam);
void atribuirAmizade(Pessoa *pessoas, char *pessoa, char *amigo, const int tam);
void exibirPessoas(Pessoa *pessoas, const int tam);

int main() {
    int tam, op;
    Pessoa *pessoas;

    printf("Digite a quantidade de pessoas: ");
    scanf("%d", &tam);
    getchar();

    pessoas = (Pessoa*)malloc(sizeof(Pessoa) * tam);

    preencherPessoas(pessoas, tam);

    do {
        printf("\nDigite:\n1 - Atribuir Amizade\n2 - Exibir Pessoas\n0 - Sair\nInsira: ");
        scanf("%d", &op);
        getchar(); 

        switch (op) {
            case 0:
                free(pessoas);
                break;
            case 1: {
                char nomePessoa[50], nomeAmigo[50];
                printf("Digite o nome da pessoa: ");
                fgets(nomePessoa, 50, stdin);
                nomePessoa[strcspn(nomePessoa, "\n")] = '\0';

                printf("Digite o nome do amigo: ");
                fgets(nomeAmigo, 50, stdin);
                nomeAmigo[strcspn(nomeAmigo, "\n")] = '\0';

                atribuirAmizade(pessoas, nomePessoa, nomeAmigo, tam);
                break;
            }
            case 2:
                exibirPessoas(pessoas, tam);
                break;
            default:
                printf("\nOpcao invalida!\n");
                break;
        }
    } while (op != 0);

    return 0;
}

void preencherPessoas(Pessoa *pessoas, const int tam) {
    for (int i = 0; i < tam; i++) {
        printf("\nDigite o nome da %d pessoa: ", i + 1);
        fgets(pessoas[i].nome, 50, stdin);
        pessoas[i].nome[strcspn(pessoas[i].nome, "\n")] = '\0';

        printf("Digite o sobrenome da %d pessoa: ", i + 1);
        fgets(pessoas[i].sobrenome, 50, stdin);
        pessoas[i].sobrenome[strcspn(pessoas[i].sobrenome, "\n")] = '\0';

        printf("Digite a idade da %d pessoa: ", i + 1);
        scanf("%d", &pessoas[i].idade);
        getchar();  

        pessoas[i].amigo = NULL;
    }
}

void atribuirAmizade(Pessoa *pessoas, char *pessoaNome, char *amigoNome, const int tam) {
    if (stricmp(pessoaNome, amigoNome) == 0) {
        printf("\nUma pessoa nao pode se adicionar como amiga!\n");
        return;
    }

    Pessoa *pessoa = NULL, *amigo = NULL;

    for (int i = 0; i < tam; i++) {
        if (stricmp(pessoas[i].nome, pessoaNome) == 0) {
            pessoa = &pessoas[i];
        }
        if (stricmp(pessoas[i].nome, amigoNome) == 0) {
            amigo = &pessoas[i];
        }
    }

    if (amigo != NULL && pessoa != NULL) {
        pessoa->amigo = amigo;
    } else {
        printf("\nPessoa(s) nao encontrada(s)!\n");
    }
}

void exibirPessoas(Pessoa *pessoas, const int tam) {
    printf("\nLista de pessoas:\n");
    for (int i = 0; i < tam; i++) {
        printf("\nPessoa %d:\n", i + 1);
        printf("Nome: %s %s\n", pessoas[i].nome, pessoas[i].sobrenome);
        printf("Idade: %d\n", pessoas[i].idade);

        if (pessoas[i].amigo != NULL) {
            printf("Melhor amigo: %s\n", pessoas[i].amigo->nome);
        } else {
            printf("Melhor amigo: Nenhum\n");
        }
    }
}

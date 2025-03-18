#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Amigos {
    struct Pessoa *amigo;
    struct Amigos *prox;
} Amigos;

typedef struct Pessoa {
    char nome[50];
    char sobrenome[50];
    int idade;
    Amigos *listaAmigos;
} Pessoa;

void preencherPessoas(Pessoa *pessoas, const int tam);
void addListaAmigos(Amigos **lista, Pessoa *amigo);
void atribuirAmizade(Pessoa *pessoas, char *pessoa, char *amigo, const int tam);
void exibirPessoas(Pessoa *pessoas, const int tam);

int main() {
    int tam, op;
    Pessoa *pessoas;
    

    printf("Digite a quantidade de pessoas:");
    scanf("%d", &tam);
    getchar();
    pessoas = (Pessoa*)malloc(sizeof(Pessoa) * tam);
    
    preencherPessoas(pessoas, tam);

    do {
        printf("\nDigite:\n1 - Atribuir Amizade\n2 - Exibir Pessoas\n0 - Sair\nInsira:");
        scanf("%d", &op);

        switch (op) {
            case 0: 
                free(pessoas);
                break;
            case 1: {
                char nomePessoa[50], nomeAmigo[50];
                printf("Digite o nome da pessoa: ");
                fgets(nomePessoa, 50, stdin);
                nomePessoa[strcspn(nomePessoa, '\n')] = '\0';

                printf("Digite o nome do amigo: ");
                fgets(nomeAmigo, 50, stdin);
                nomeAmigo[strcspn(nomeAmigo, '\n')] = '\0';

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

        pessoas[i].listaAmigos = NULL;
    }
}

void addListaAmigos(Amigos **lista, Pessoa *amigo) {
    Amigos *novoNo = (Amigos*)malloc(sizeof(Amigos));
    novoNo->amigo = amigo;
    novoNo->prox = NULL;
    
    if (*lista == NULL) {
        *lista = novoNo;
    } else {
        Amigos *temp = *lista;
        while (temp->prox != NULL) temp = temp->prox;

        temp->prox = novoNo;
    }
    printf("\nAmizade atribuida com sucesso!\n");
}

void atribuirAmizade(Pessoa *pessoas, char *pessoa, char *amigo, const int tam) {
    if (stricmp(pessoa, amigo) == 0) {
        printf("\nUma pessoa não consegue se adicionar como amigo!\n");
        return;
    }
    
    Pessoa *p = NULL, *a = NULL;
    int i;
    
    for (i = 0; i < tam; i++) {
        if (stricmp(pessoas[i].nome, pessoa) == 0) {
            p = &pessoas[i];
        }

        if (stricmp(pessoas[i].nome, amigo) == 0) {
            a = &pessoas[i];
        }
    }

    if (a != NULL && p != NULL) {
        addListaAmigos(&p->listaAmigos, a);
    } else {
        printf("\nPessoas inexistentes!\n");
    }
}

void exibirPessoas(Pessoa *pessoas, const int tam) {   
    printf("\nLista pessoas:\n");
    for (int i = 0; i < tam; i++) {
        printf("\nPessoa %d:\n", i + 1);
        printf("Nome: '%s'\nidade: %d\n", pessoas[i].nome, pessoas[i].idade);
        if (pessoas[i].listaAmigos != NULL) {
            Amigos *temp = pessoas[i].listaAmigos;
            printf("Amigos:\n");
            while (temp != NULL) {
                printf("'%s'\n", temp->amigo->nome);
                temp = temp->prox;
            }
        }
    }
}
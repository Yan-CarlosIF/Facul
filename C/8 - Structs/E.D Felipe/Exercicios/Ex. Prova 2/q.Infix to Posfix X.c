#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Estrutura de um nó da pilha
typedef struct Nodo {
    char dado;              // Dado armazenado no nó
    struct Nodo *proximo;   // Ponteiro para o próximo nó
} Nodo;

// Estrutura da pilha
typedef struct {
    Nodo *topo;             // Ponteiro para o topo da pilha
} Pilha;

// Função para inicializar a pilha, define o topo como NULL
void inicializarPilha(Pilha *pilha) {
    pilha->topo = NULL;
}

// Verifica se a pilha está vazia
int estaVazia(Pilha *pilha) {
    return pilha->topo == NULL;
}

// Empilha um elemento no topo da pilha
void empilhar(Pilha *pilha, char c) {
    Nodo *novoNodo = (Nodo *)malloc(sizeof(Nodo)); // Aloca memória para um novo nó
    if (novoNodo == NULL) {
        printf("Erro: Falha na alocação de memória!\n");
        exit(1); // Encerra o programa em caso de erro
    }
    novoNodo->dado = c;           // Armazena o dado no nó
    novoNodo->proximo = pilha->topo; // Faz o novo nó apontar para o antigo topo
    pilha->topo = novoNodo;       // Atualiza o topo da pilha
}

// Desempilha um elemento do topo da pilha
char desempilhar(Pilha *pilha) {
    if (estaVazia(pilha)) {
        printf("Erro: Pilha vazia!\n");
        exit(1); // Encerra o programa se a pilha estiver vazia
    }
    Nodo *nodoRemovido = pilha->topo; // Armazena o nó a ser removido
    char dado = nodoRemovido->dado;  // Armazena o dado do nó
    pilha->topo = nodoRemovido->proximo; // Atualiza o topo da pilha
    free(nodoRemovido);              // Libera a memória do nó removido
    return dado;                     // Retorna o dado
}

// Retorna o elemento no topo da pilha sem removê-lo
char topo(Pilha *pilha) {
    if (estaVazia(pilha)) {
        return '\0'; // Retorna caractere nulo se a pilha estiver vazia
    }
    return pilha->topo->dado; // Retorna o dado do topo
}

// Funções auxiliares
int precedencia(char operador) {
    switch (operador) {
        case '^': return 3;
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
        default: return 0;
    }
}

int ehOperador(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

void infixaParaPosfixa(const char *infixa, char *posfixa) {
    Pilha pilha;
    inicializarPilha(&pilha);
    int j = 0;

    for (int i = 0; infixa[i] != '\0'; i++) {
        char c = infixa[i];

        if (isspace(c)) {
            continue; // Ignorar espaços em branco
        }

        if (isalnum(c)) {
            posfixa[j++] = c; // Adicionar operandos diretamente à saída
        } else if (c == '(') {
            empilhar(&pilha, c);
        } else if (c == ')') {
            while (!estaVazia(&pilha) && topo(&pilha) != '(') {
                posfixa[j++] = desempilhar(&pilha);
            }
            if (!estaVazia(&pilha) && topo(&pilha) == '(') {
                desempilhar(&pilha); // Remover '('
            }
        } else if (ehOperador(c)) {
            while (!estaVazia(&pilha) && precedencia(topo(&pilha)) >= precedencia(c)) {
                posfixa[j++] = desempilhar(&pilha);
            }
            empilhar(&pilha, c);
        }
    }

    // Esvaziar a pilha restante
    while (!estaVazia(&pilha)) {
        posfixa[j++] = desempilhar(&pilha);
    }

    posfixa[j] = '\0'; // Finalizar a string
}

int main() {
    char infixa[] = "a*(b+c)*(d-g)*h\0", posfixa[100];

    // printf("Digite a expressão infixa: ");
    // fgets(infixa, sizeof(infixa), stdin);
    // infixa[strcspn(infixa, "\n")] = '\0'; // Remover o '\n' do final

    infixaParaPosfixa(infixa, posfixa);

    printf("Expressão pós-fixa: %s\n", posfixa);

    return 0;
}


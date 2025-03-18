
#include <stdio.h>
#include <stdlib.h>

// Estrutura do nó
typedef struct Lista {
    int data;
    struct Lista* next;
} Lista;

// Função para criar um novo nó
Lista* criarNo(int data) {
    Lista* novoNo = (Lista*)malloc(sizeof(Lista));
    if (novoNo == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }
    novoNo->data = data;
    novoNo->next = NULL;
    return novoNo;
}

// Função para inserir um novo nó no final da lista
void inserirNoFinal(Lista** head, int data) {
    Lista* novoNo = criarNo(data);
    if (*head == NULL) {
        *head = novoNo;
    } else {
        Lista* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = novoNo;
    }
}

// Função para exibir os elementos da lista
void exibirLista(Lista* head) {
    if (head == NULL) {
        printf("A lista está vazia.\n");
        return;
    }
    Lista* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Função para remover o primeiro elemento da lista
void removerPrimeiro(Lista** head) {
    if (*head == NULL) {
        printf("A lista já está vazia.\n");
        return;
    }
    Lista* temp = *head;
    *head = (*head)->next;
    free(temp);
    printf("Primeiro elemento removido.\n");
}

// Função para liberar toda a memória alocada pela lista
void liberarLista(Lista** head) {
    Lista* temp;
    while (*head != NULL) {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
    printf("Memória liberada.\n");
}

int main() {
    Lista* lista = NULL;

    inserirNoFinal(&lista, 10);
    inserirNoFinal(&lista, 20);
    inserirNoFinal(&lista, 30);

    printf("Lista após inserção:\n");
    exibirLista(lista);

    removerPrimeiro(&lista);
    printf("Lista após remover o primeiro elemento:\n");
    exibirLista(lista);

    liberarLista(&lista);
    return 0;
}

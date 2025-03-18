#include <stdio.h>
#include <stdlib.h>

typedef struct teste {
    int x;
    struct teste *next;
} teste;

void insert(teste **lista, int valor) {
    teste *element = (teste*)malloc(sizeof(teste));
    if (element == NULL) {
        printf("Erro de alocação de memória.\n");
        return;
    }
    element->x = valor; // Exemplo de inicialização
    element->next = *lista;
    *lista = element;
}

void displayList(teste *list) {
    if (list == NULL) {
        printf("List is empty.\n");
        return;
    }

    teste *element = list;

    while (element != NULL) {
        printf("%d -> ", element->x);
        element = element->next;
    }
    printf("NULL\n");
}

int main() {
    teste *lista = NULL;

    insert(&lista, 1);
    insert(&lista, 2);
    insert(&lista, 3);

    displayList(lista);
    return 0;
}
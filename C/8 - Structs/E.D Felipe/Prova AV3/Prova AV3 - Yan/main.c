#include "./estruturas/lista.c"

// Você precisa de uma lista que permita realizar verificação de itens tanto do começo ao final, 
// quanto do final ao começo. Estas são as listas duplamente ligadas. Apresente as estruturas e 
// funções atualizadas para que isto seja possível,no caso de uma lista de inteiros.

int main() {
    // criando uma lista duplamente encadeada
    DoublyLinkedList *lista = initList();

    // adicionando novos itens com o push
    push(lista, 1);
    push(lista, 2);
    push(lista, 3);

    // adicionando novos itens nos indices desejados com o add 
    add(lista, 1, lista->size);
    add(lista, 2, lista->size);
    add(lista, 3, 1);
    add(lista, 4, 0);

    // deletando itens nos indices desejados com del
    del(lista, 0);
    del(lista, 1);
    del(lista, 1);

    // exibe a lista do inicio ao fim passando true na booleana de 'inicio ao fim'
    printList(lista, true);

    // exibe a lista do fim ao inicio passando false na booleana de 'inicio ao fim'
    printList(lista, false);

    // liberando memoria alocada para a lista e seus nó's
    freeList(lista);
    return 0;
}
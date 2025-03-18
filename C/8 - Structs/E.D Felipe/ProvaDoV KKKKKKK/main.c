#include "estruturas/aluno.c"

int main() {
    ListaAlunos *lista = initList();

    push(lista, "Yan", "BCC", 20, 1234);
    push(lista, "Luiz", "ADS", 20, 1235);
    push(lista, "Ermerson", "Foda-se", 20, 1236);

    exibirLista(lista);
    modificarDados(lista, 1236);
    exibirLista(lista);

    deletarAluno(lista, 1235);
    exibirLista(lista);
    deletarAluno(lista, 999);
    modificarDados(lista, 999);

    printf("\nAluno encontrado: %s\n", buscarAluno(lista, 1234)->nome);

    freeLista(lista);
    exibirLista(lista);
    return 0;
}
#include "./estruturas/listaentregas.c"

int main() {
  printf("Bem Vindo a lista de entregas!\n");
  Entregas *lista = initList();

  while (1) {
    int op = menu();
    switch (op) {
      case 0:
        printf("\nFinalizando o programa...\n");
        freeList(lista);
        break;
      case 1: {
        Entrega entrega;

        printf("Digite o nome do destinatario: ");
        fgets(entrega.nomeDestinatario, 50, stdin);
        entrega.nomeDestinatario[strcspn(entrega.nomeDestinatario, "\n")] = '\0';

        printf("Digite o endereco da entrega: ");
        fgets(entrega.endereco, 50, stdin);
        entrega.endereco[strcspn(entrega.endereco, "\n")] = '\0';

        entrega.id = lista->size;

        add(lista, receberIndice("adicionar"), entrega);
      } break;
      case 2:
        del(lista, receberIndice("deletar"));
        break;
      case 3:
        set(lista, receberIndice("atualizar"));
        break;
      case 4: {
        Entrega *entrega = get(lista, receberIndice("buscar"));

        if (entrega != NULL) {
          printf("\nID: %d\n", entrega->id);
          printf("Destinatario: %s\n", entrega->nomeDestinatario);
          printf("Endereco: %s\n\n", entrega->endereco);
        } else {
          printf("Indice invalido!\n\n");
        }
      } break;
      case 5:
        sort(lista);
        break;
      case 6:
        printList(lista);
        break;
      default:
        printf("\nOpcao invalida!\n");
        break;
    }

    if (op == 0) break;
  }
  return 0;
}
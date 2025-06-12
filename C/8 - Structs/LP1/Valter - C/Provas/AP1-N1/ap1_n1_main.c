#include "../../Lista-Generica/estruturas/lista-generica.c"

typedef struct {
  char descricao[100];
  char local_encontrado[50];
  char data[11];
  char tipo[30];
  int devolvido;
} ObjetoPerdido;

void removerBarraN(char* str) { str[strcspn(str, "\n")] = '\0'; }

ObjetoPerdido* inputObject() {
  ObjetoPerdido* newObj = (ObjetoPerdido*)malloc(sizeof(ObjetoPerdido));

  printf("Insira a descricao do objeto: ");
  fgets(newObj->descricao, 100, stdin);
  removerBarraN(newObj->descricao);

  printf("Insira o local que foi encontrado: ");
  fgets(newObj->local_encontrado, 50, stdin);
  removerBarraN(newObj->local_encontrado);

  printf("Insira a data que esse objeto foi encontrado: ");

  int dia, mes, ano;

  do {
    printf("dia (1 - 30): ");
    scanf("%d", &dia);
  } while (dia < 1 || dia > 30);

  do {
    printf("mes (1 - 12): ");
    scanf("%d", &mes);
  } while (mes < 1 || mes > 12);

  do {
    printf("ano (2020 - 2026): ");
    scanf("%d", &ano);
  } while (ano < 2020 || ano > 2026);

  sprintf(newObj->data, "%02d/%02d/%d", dia, mes, ano);

  getchar();

  printf("Insira o tipo do objeto: ");
  fgets(newObj->tipo, 30, stdin);
  removerBarraN(newObj->tipo);

  do {
    printf("Esse objeto foi devolvido (1 - para sim, 0 - para nao): ");
    scanf("%d", &newObj->devolvido);
  } while (newObj->devolvido < 0 || newObj->devolvido > 1);

  getchar();

  return newObj;
}

void printObject(void* obj) {
  ObjetoPerdido* objParse = (ObjetoPerdido*)obj;

  printf("\nDescricao: %s", objParse->descricao);
  printf("\nlocal_encontrado: %s", objParse->local_encontrado);
  printf("\ntipo: %s", objParse->tipo);
  printf("\ndata: %s", objParse->data);
  printf("\nfoi devolvido: %s\n\n", objParse->devolvido ? "Sim" : "Nao");
}

int comparaData(void* obj1, void* obj2) {
  const ObjetoPerdido* obj1parse = (ObjetoPerdido*)obj1;
  const ObjetoPerdido* obj2parse = (ObjetoPerdido*)obj2;

  const int resultadoData = strcmp(obj1parse->data, obj2parse->data) > 0;

  if (strcmp(obj1parse->descricao, obj2parse->descricao) == 0 &&
      strcmp(obj1parse->data, obj2parse->data) == 0) {
    return 999;
  }

  return resultadoData;
}

int procuraPelaDescricao(void* obj1, void* descricao) {
  ObjetoPerdido* obj1parse = (ObjetoPerdido*)obj1;
  char* descricaoParse = (char*)descricao;

  return strcmp(obj1parse->descricao, descricaoParse) == 0;
}

int main() {
  Node* list = initList();

  ObjetoPerdido* obj1 = inputObject();
  ObjetoPerdido* obj2 = inputObject();

  list = listInsert(list, obj1, comparaData);
  list = listInsert(list, obj2, comparaData);

  ObjetoPerdido* objetoProcurado = listSearch(list, "oi", procuraPelaDescricao);

  if (objetoProcurado) {
    printf("\n\nObjeto achado!: ");
    printObject(objetoProcurado);

    int op;

    if (objetoProcurado->devolvido == 0) {
      do {
        printf(
            "Voce deseja marcar o objeto como devolvido? (1 - sim, 0 - nao): ");
        scanf("%d", &op);
      } while (op < 0 || op > 1);

      objetoProcurado->devolvido = 1;
    }

    printf("\nLista apos procura do objeto: ");
    listPrint(list, printObject);
  } else {
    printf("\nobjeto nao foi achado!\n");
  }

  list = listRemove(list, "oi", procuraPelaDescricao);

  printf("lista Apos exclusao:");

  listPrint(list, printObject);

  freeList(list);

  free(objetoProcurado);
  free(obj1);
  free(obj2);

  return 0;
}
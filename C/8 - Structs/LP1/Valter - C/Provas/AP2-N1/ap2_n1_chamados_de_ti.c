#include "../../Lista-Generica/estruturas/lista-generica.c"

typedef struct {
  int id_chamado;  // índice do chamado: chave primária.
  int id_usuario;  // índice que designa o usuário que abriu o chamado: chave
                   // estrangeira
  char solicitante[100];  // Nome do usuário que abriu o chamado
  char setor[50];         // Local do atendimento: "Biblioteca", "LabInfo1"
  char data[11];          // Formato "DD/MM/AAAA"
  char problema[100];     // Ex: "Impressora não imprime", "Sem internet"
  int resolvido;          // 0 = pendente, 1 = resolvido
} AtendimentoTI;

int verificar(void* item1, void* item2) {
  return ((AtendimentoTI*)item2)->id_chamado <
         ((AtendimentoTI*)item1)->id_chamado;
}
int listSize(Node* list);
AtendimentoTI* inputAtendimento(Node* list);
void imprime(void* item);
void* readline(char* line);
int todosNaoResolvidos(void* item);
int findPerId(void* item1, void* item2);
char* writeLine(void* info);
int main() {
  Node* list = initList();

  // 1° Questão
  list = listFileLoad(list, "banco_de_dados_chamados.txt", readline);

  printf("\nLista carregada:\n ");
  listPrint(list, imprime);

  // 2° Questão
  printf("\nChamados nao resolvidos:\n ");
  listMap(list, imprime, todosNaoResolvidos);

  // 3° Questão
  AtendimentoTI* new = inputAtendimento(list);
  listInsert(list, new, verificar);

  printf("\nLista atualizada:\n ");
  listPrint(list, imprime);

  // 4° Questão
  int id_chamado;
  do {
    printf("Digite o id_chamado que deseja procurar: ");
    scanf("%d", &id_chamado);
  } while (id_chamado < 0 || id_chamado > listSize(list));

  AtendimentoTI* procurado = listSearch(list, (void*)id_chamado, findPerId);

  printf("\n\nChamado encontrado:\n ");
  imprime(procurado);

  printf("\nDeletando chamados 1, 2 e 3...");
  list = listRemove(list, (void*)1, findPerId);
  list = listRemove(list, (void*)2, findPerId);
  list = listRemove(list, (void*)3, findPerId);

  printf("\nLista Apos Remocao:\n ");
  listPrint(list, imprime);

  listFileSave(list, "banco_de_dados_chamados2.txt", writeLine);

  list = freeList(list);

  return 0;
}

char* writeLine(void* info) {
  const AtendimentoTI* parsedInfo = (AtendimentoTI*)info;
  char* line = (char*)malloc(sizeof(121));

  sprintf(line, "%d;%d;%s;%s;%s;%s;%d\n", parsedInfo->id_chamado,
          parsedInfo->id_usuario, parsedInfo->solicitante, parsedInfo->setor,
          parsedInfo->data, parsedInfo->problema, parsedInfo->resolvido);

  return line;
}

int findPerId(void* item1, void* item2) {
  return (int)item2 == ((AtendimentoTI*)item1)->id_chamado;
}

void imprime(void* item) {
  const AtendimentoTI* parsedItem = (AtendimentoTI*)item;

  printf("\nId_Chamado: %d", parsedItem->id_chamado);
  printf("\nId_Usuario: %d", parsedItem->id_usuario);
  printf("\nSolicitante: %s", parsedItem->solicitante);
  printf("\nsetor: %s", parsedItem->setor);
  printf("\ndata: %s", parsedItem->data);
  printf("\nproblema: %s", parsedItem->problema);
  printf("\nresolvido: %s\n", parsedItem->resolvido ? "Sim" : "Nao");
}

int listSize(Node* list) {
  int size = 0;

  while (list != NULL) {
    list = list->next;
    size++;
  }

  return size;
}

AtendimentoTI* inputAtendimento(Node* list) {
  // id_usuario, solicitante, setor, data e problema
  AtendimentoTI* newItem = (AtendimentoTI*)malloc(sizeof(AtendimentoTI));

  printf("\nDigite o id_usuario: ");
  scanf("%d", &newItem->id_usuario);
  getchar();

  printf("\nDigite o solicitante(nome): ");
  gets(newItem->solicitante);

  printf("\nDigite o setor: ");
  gets(newItem->setor);

  printf("\nDigite a data: ");
  gets(newItem->data);

  printf("\nDigite o problema: ");
  gets(newItem->problema);

  newItem->resolvido = 0;
  newItem->id_chamado = listSize(list) + 1;

  return newItem;
}

void* readline(char* line) {
  AtendimentoTI* newItem = (AtendimentoTI*)malloc(sizeof(AtendimentoTI));

  sscanf(line, "%d;%d;%99[^;];%49[^;];%12[^;];%99[^;];%d", &newItem->id_chamado,
         &newItem->id_usuario, newItem->solicitante, newItem->setor,
         newItem->data, newItem->problema, &newItem->resolvido);

  return newItem;
}

int todosNaoResolvidos(void* item) {
  const AtendimentoTI* parsedItem = (AtendimentoTI*)item;

  return parsedItem->resolvido == 0;
}
#include "./estruturas/tree.h"

typedef struct atendimento {
  int id_chamado;         // índice do chamado: chave primária.
  int id_usuario;         // índice que designa o usuário que abriu o chamado
  char solicitante[100];  // Nome do usuário que abriu o chamado
  char setor[50];         // Local do atendimento: "Biblioteca", "LabInfo1"
  char data[11];          // Formato "DD/MM/AAAA"
  char problema[100];     // Ex: "Impressora não imprime", "Sem internet"
  int resolvido;          // 0 = pendente, 1 = resolvido
} AtendimentoTI;

typedef struct avaliacao {
  int id_chamado;        // chave estrangeira para a tabela atendimento.
  int satisfacao;        // 1 a 5
  char comentario[200];  // Comentário acerca do atendimento.
} AvaliacaoTI;

int filteredIndexes[50];  // Array global pra pegar os ids que a satisfacao <= 3
int size = 0;             // Tamanho do array

int compare_id(void* item1, void* item2);
int compare_satisfaction_index(void* item1, void* item2);
void* read_atendimento(char* line);
void* read_avaliacao(char* line);
void print_registro(void* item);
int avaliacoes_less_than_3(void* item);
Node* copy_avaliacao(void* item);
void push_indexes(void* item);
Node* search_chamado_by_id(Node* root, int id_chamado);
void print_chamados_in_order(Node* chamados, int* ids, int size);

int main() {
  Node* chamados = tree_create_empty();
  Node* avaliacoes = tree_create_empty();

  chamados = 
      tree_load_from_file("banco_de_dados_chamados.csv", read_atendimento, compare_id);

  avaliacoes = 
      tree_load_from_file("banco_de_dados_satisfacao.csv", read_avaliacao, compare_id);

  // Imprimir todos os registros
  tree_map(chamados, print_registro);

  // 1. Filtrar avaliações com satisfação ≤ 3 em ordem crescente
  Node* filteredAvaliacoes =
      tree_filter(avaliacoes, avaliacoes_less_than_3, copy_avaliacao, compare_satisfaction_index);

  // 2. Coletar IDs dos chamados com baixa satisfação
  tree_map(filteredAvaliacoes, push_indexes);

  // 3. Imprimir chamados correspondentes
  printf("\n\nChamados com satisfacao <= 3: \n");
  print_chamados_in_order(chamados, filteredIndexes, size);

  // Liberar memória
  tree_free(chamados);
  tree_free(avaliacoes);
  tree_free(filteredAvaliacoes);

  return 0;
}

void print_registro(void* item) {
  const AtendimentoTI* parsedItem = (AtendimentoTI*)item;

  Node* avaliacoes = 
      tree_load_from_file("banco_de_dados_satisfacao.csv", read_avaliacao, compare_id);

  Node* found = search_chamado_by_id(avaliacoes, parsedItem->id_chamado);
  const AvaliacaoTI* avaliacao = (AvaliacaoTI*)found->info;

  printf("\n[Chamado ID %d]", parsedItem->id_chamado);
  printf("\nSolicitante: %s | Setor: %s | Data: %s", parsedItem->solicitante, parsedItem->setor, parsedItem->data);
  printf("\nProblema: %s", parsedItem->problema);
  printf("\nSatisfacao: %d | Comentario: %s", avaliacao->satisfacao, avaliacao->comentario);
  printf("\n--------------------------------------------------------------\n");

  tree_free(avaliacoes);
}

void push_indexes(void* item) {
  filteredIndexes[size++] = ((AvaliacaoTI*)item)->id_chamado;
}

int compare_satisfaction_index(void* item1, void* item2) {
  return ((AvaliacaoTI*)item1)->satisfacao < ((AvaliacaoTI*)item2)->satisfacao;
}

Node* search_chamado_by_id(Node* root, int id_chamado) {
  if (root == NULL) return NULL;

  AtendimentoTI* atendimento = (AtendimentoTI*)root->info;

  if (atendimento->id_chamado == id_chamado) {
    return root;
  } else if (id_chamado < atendimento->id_chamado) {
    return search_chamado_by_id(root->lst, id_chamado);
  } else {
    return search_chamado_by_id(root->rst, id_chamado);
  }
}

// Função auxiliar para imprimir chamados na ordem dos filteredIndexes
void print_chamados_in_order(Node* chamados, int* ids, int size) {
  for (int i = 0; i < size; i++) {
    Node* found = search_chamado_by_id(chamados, ids[i]);
    if (found != NULL) {
      print_registro(found->info);
    }
  }
}

int avaliacoes_less_than_3(void* item) {
  return ((AvaliacaoTI*)item)->satisfacao <= 3;
}

Node* copy_avaliacao(void* item) {
  AvaliacaoTI* copy = (AvaliacaoTI*)malloc(sizeof(AvaliacaoTI));
  AvaliacaoTI* parsedItem = (AvaliacaoTI*)item;

  copy->id_chamado = parsedItem->id_chamado;
  copy->satisfacao = parsedItem->satisfacao;
  strcpy(copy->comentario, parsedItem->comentario);

  return tree_create_node(copy, NULL, NULL);
}

int compare_id(void* item1, void* item2) {
  return ((AtendimentoTI*)item1)->id_chamado <
         ((AtendimentoTI*)item2)->id_chamado;
}

void* read_atendimento(char* line) {
  AtendimentoTI* newItem = (AtendimentoTI*)malloc(sizeof(AtendimentoTI));

  sscanf(line, "%d;%d;%99[^;];%49[^;];%12[^;];%99[^;];%d", &newItem->id_chamado,
         &newItem->id_usuario, newItem->solicitante, newItem->setor,
         newItem->data, newItem->problema, &newItem->resolvido);

  return newItem;
}

void* read_avaliacao(char* line) {
  AvaliacaoTI* newItem = (AvaliacaoTI*)malloc(sizeof(AvaliacaoTI));

  sscanf(line, "%d;%d;%199[^.]", &newItem->id_chamado, &newItem->satisfacao, newItem->comentario);

  return newItem;
}
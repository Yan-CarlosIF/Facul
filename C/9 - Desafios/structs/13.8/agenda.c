#include "./agenda.h"
#define MAX_SIZE 15
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char *MESES[] = {"Janeiro",  "Fevereiro", "Março",    "Abril",
                       "Maio",     "Junho",     "Julho",    "Agosto",
                       "Setembro", "Outubro",   "Novembro", "Dezembro"};

int menu() {
  int op;
  printf(
      "\n1. Cadastrar pessoa na agenda de aniversariantes (nome, dia e mes do "
      "aniversario).\n");
  printf("2. Excluir pessoa a partir do nome.\n");
  printf("3. Alterar dia ou mes a partir do nome.\n");
  printf("4. Consultar aniversariantes de uma data (dia e mes).\n");
  printf("5. Consultar aniversariantes por mes.\n");
  printf("6. Consultar aniversariantes pela letra inicial do nome.\n");
  printf("7. Mostrar toda a agenda ordenada pelo nome.\n");
  printf("8. Mostrar toda a agenda ordenada por mes.\n");
  printf("9. Sair.\n");
  printf("A agenda pode suportar ate 15 pessoas.\n");
  printf("Escolha uma opcao: ");

  scanf("%d", &op);
  while (getchar() != '\n');
  return op;
}

void exibirData(struct Data data) {
  printf("Dia: %02d/%02d", data.dia, data.mes);
}

void receberDia(int *dia) {
  do {
    scanf("%d", dia);
  } while (*dia < 1 || *dia > 31);
}

void receberMes(int *mes) {
  do {
    scanf("%d", mes);
  } while (*mes < 1 || *mes > 12);
}

Agenda *initAgenda() {
  Agenda *newAgenda = (Agenda *)malloc(sizeof(Agenda));
  if (newAgenda == NULL) {
    printf("Erro ao alocar memória.\n");
    exit(1);
  }

  newAgenda->head = NULL;
  newAgenda->end = NULL;
  newAgenda->size = 0;

  return newAgenda;
}

Pessoa *createPessoa(Pessoa pessoa) {
  Pessoa *newPessoa = (Pessoa *)malloc(sizeof(Pessoa));
  if (newPessoa == NULL) {
    printf("Erro ao alocar memória.\n");
    exit(1);
  }

  newPessoa->data = pessoa.data;
  newPessoa->data.exibirData = exibirData;
  strcpy(newPessoa->nome, pessoa.nome);
  newPessoa->prox = NULL;

  return newPessoa;
}

void add(Agenda *agenda, Pessoa pessoa) {
  if (agenda->size >= MAX_SIZE) {
    printf("\nAgenda cheia!\n");
    return;
  }

  if (agenda->head == NULL) {
    agenda->head = createPessoa(pessoa);
    agenda->end = agenda->head;
  } else {
    agenda->end->prox = createPessoa(pessoa);
    agenda->end = agenda->end->prox;
  }

  agenda->size++;
  printf("\nPessoa cadastrada com sucesso!\n");
}

void cadastrarPessoa(Agenda *agenda) {
  Pessoa pessoa;

  printf("Digite o nome da pessoa: ");
  fgets(pessoa.nome, 50, stdin);
  pessoa.nome[strcspn(pessoa.nome, "\n")] = '\0';

  printf("Digite o dia do aniversario da pessoa: ");
  receberDia(&pessoa.data.dia);

  printf("Digite o mes do aniversario da pessoa: ");
  receberMes(&pessoa.data.mes);

  add(agenda, pessoa);
}

void excluirPessoa(Agenda *agenda) {
  if (agenda->size == 0) {
    printf("\nAgenda vazia!\n");
    return;
  }

  char nome[50];
  printf("Digite o nome da pessoa que deseja excluir: ");
  fgets(nome, 50, stdin);
  nome[strcspn(nome, "\n")] = '\0';

  Pessoa *temp = agenda->head;

  if (strcasecmp(temp->nome, nome) == 0) {
    agenda->head = temp->prox;
    printf("\nAniversariante '%s' excluido com sucesso!\n", temp->nome);
    free(temp);
    agenda->size--;
    return;
  }

  while (temp != NULL) {
    if (strcasecmp(temp->prox->nome, nome) == 0) {
      Pessoa *excluido = temp->prox;
      temp->prox = temp->prox->prox;

      if (temp->prox == agenda->end) {
        agenda->end = temp;
      }

      printf("\nAniversariante '%s' excluido com sucesso!\n", excluido->nome);
      free(excluido);
      agenda->size--;
      return;
    }

    temp = temp->prox;
  }

  printf("\nPessoa nao encontrada!\n");
}

Pessoa *get(Agenda *agenda, char *nome) {
  if (agenda->size == 0) return NULL;

  Pessoa *temp = agenda->head;
  while (temp != NULL) {
    if (strcasecmp(temp->nome, nome) == 0) return temp;
    temp = temp->prox;
  }

  printf("\nPessoa nao encontrada!\n");
  return NULL;
}

void set(Agenda *agenda) {
  printf("Digite o nome da pessoa que deseja alterar: ");
  char nome[50];
  fgets(nome, 50, stdin);
  nome[strcspn(nome, "\n")] = '\0';

  Pessoa *pessoa = get(agenda, nome);

  if (pessoa != NULL) {
    printf("Digite o novo dia de aniversario de '%s': ", pessoa->nome);
    receberDia(&pessoa->data.dia);

    printf("Digite o novo mes de aniversario de '%s': ", pessoa->nome);
    receberMes(&pessoa->data.mes);

    printf("\nAniversariante '%s' alterado com sucesso!\n", pessoa->nome);
  } else {
    printf("\nPessoa nao encontrada!\n");
  }
}

void consultarPorDiaEmes(Agenda *agenda) {
  if (agenda->size == 0) {
    printf("\nAgenda vazia!\n");
    return;
  }

  Data novaData;
  printf("Digite o dia que deseja consultar: ");
  receberDia(&novaData.dia);

  printf("Digite o mes que deseja consultar: ");
  receberMes(&novaData.mes);

  int encontrado = 0;
  Pessoa *temp = agenda->head;
  while (temp != NULL) {
    if (temp->data.dia == novaData.dia && temp->data.mes == novaData.mes) {
      encontrado++;
      if (encontrado == 1) printf("\nLista de aniversariantes:\n");

      printf("Nome: '%s', ", temp->nome);
      temp->data.exibirData(temp->data);
      printf("\n");
    }
    temp = temp->prox;
  }

  if (!encontrado) printf("\nNenhum aniversariante encontrado!\n");
}

void consultarPorMes(Agenda *agenda) {
  if (agenda->size == 0) {
    printf("\nAgenda vazia!\n");
    return;
  }

  int mes;

  printf("Digite o mes que deseja consultar (1 a 12): ");
  receberMes(&mes);

  int encontrado = 0;
  Pessoa *temp = agenda->head;
  while (temp != NULL) {
    if (temp->data.mes == mes) {
      encontrado++;
      if (encontrado == 1)
        printf("\nLista de aniversariantes do mes %s:\n", MESES[mes - 1]);

      printf("Nome: '%s', ", temp->nome);
      temp->data.exibirData(temp->data);
      printf("\n");
    }
    temp = temp->prox;
  }

  if (!encontrado)
    printf("\nNenhum aniversariante encontrado no mes %s!\n", MESES[mes - 1]);
}

void consultarPorLetraInicial(Agenda *agenda) {
  if (agenda->size == 0) return;

  printf("Digite a primeira letra do nome: ");
  char letra;
  scanf(" %c", &letra);

  int encontrado = 0;
  Pessoa *temp = agenda->head;
  while (temp != NULL) {
    if (tolower(temp->nome[0]) == tolower(letra)) {
      encontrado++;
      if (encontrado == 1)
        printf("\nLista de aniversariantes com a inicial '%c':\n", letra);

      printf("Nome: '%s', ", temp->nome);
      temp->data.exibirData(temp->data);
      printf("\n");
    }
    temp = temp->prox;
  }

  if (!encontrado) printf("\nNenhum aniversariante encontrado!\n");
}

void ordenarPorNome(Agenda *agenda) {
  if (agenda->size == 0) {
    printf("\nAgenda vazia!\n");
    return;
  }

  Pessoa *atual = agenda->head, *sortedList = NULL;

  while (atual != NULL) {
    Pessoa *prox = atual->prox;

    if (sortedList == NULL ||
        tolower(sortedList->nome[0]) >= tolower(atual->nome[0])) {
      atual->prox = sortedList;
      sortedList = atual;
    } else {
      Pessoa *temp = sortedList;

      while (temp->prox != NULL &&
             tolower(temp->prox->nome[0]) < tolower(atual->nome[0]))
        temp = temp->prox;

      atual->prox = temp->prox;
      temp->prox = atual;
    }
    atual = prox;
  }

  printf("\nAgenda ordenada:\n");
  while (sortedList != NULL) {
    printf("Nome: '%s', ", sortedList->nome);
    sortedList->data.exibirData(sortedList->data);
    printf("\n");
    sortedList = sortedList->prox;
  }
}

void ordenarPorMes(Agenda *agenda) {
  if (agenda->size == 0) return;

  for (int i = 0; i < 12; i++) {
    int encontrado = 0;
    Pessoa *temp = agenda->head;

    while (temp != NULL) {
      if (temp->data.mes == i + 1) {
        encontrado++;
        if (encontrado == 1)
          printf("\nLista de aniversariantes de %s:\n", MESES[i]);
        printf("Nome: '%s', ", temp->nome);
        temp->data.exibirData(temp->data);
        printf("\n");
      }
      temp = temp->prox;
    }
  }
}

void freeList(Agenda *agenda) {
  if (agenda->size == 0) return;

  Pessoa *temp = agenda->head;
  while (temp != NULL) {
    Pessoa *deleted = temp;
    temp = temp->prox;
    free(deleted);
  }

  free(agenda);
}
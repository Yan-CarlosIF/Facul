#ifndef AGENDA_H
#define AGENDA_H

typedef struct Data {
  int dia;
  int mes;
  void (*exibirData)(struct Data data);
} Data;

typedef struct Pessoa {
  char nome[50];
  Data data;
  struct Pessoa *prox;
} Pessoa;

typedef struct {
  Pessoa *head;
  Pessoa *end;
  int size;
} Agenda;

int menu();
void exibirData(struct Data data);
void receberDia(int *dia);
void receberMes(int *mes);
Agenda *initAgenda();
Pessoa *createPessoa(Pessoa pessoa);
void add(Agenda *agenda, Pessoa pessoa);
void cadastrarPessoa(Agenda *agenda);
void excluirPessoa(Agenda *agenda);
Pessoa *get(Agenda *agenda, char *nome);
void set(Agenda *agenda);
void consultarPorDiaEmes(Agenda *agenda);
void consultarPorMes(Agenda *agenda);
void consultarPorLetraInicial(Agenda *agenda);
void ordenarPorNome(Agenda *agenda);
void ordenarPorMes(Agenda *agenda);
void freeList(Agenda *agenda);
#endif
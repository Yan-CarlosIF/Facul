#include "./ligacao.h"

#include <stdio.h>

void receberHora(Hora *h) {
  do {
    printf("Digite a hora: ");
    scanf("%d", &h->hora);
  } while (h->hora < 0 || h->hora > 23);

  do {
    printf("Digite o minuto: ");
    scanf("%d", &h->minuto);
  } while (h->minuto < 0 || h->minuto > 59);
}

void receberLigacao(Ligacao *l) {
  printf("Digite a hora inicial da ligacao:\n");
  receberHora(&l->horaInicial);

  printf("\nDigite a hora final da ligacao:\n ");
  receberHora(&l->horaFinal);

  printf("Digite o custo por minuto: ");
  scanf("%f", &l->custoPorMinuto);
}

int calcularDesconto(Ligacao l) {
  if (l.horaInicial.hora >= 0 && l.horaFinal.hora <= 9) {
    return 1;
  } else if (l.horaInicial.hora >= 9 && l.horaInicial.minuto >= 1 &&
             l.horaFinal.hora <= 18) {
    return 2;
  } else if (l.horaInicial.hora >= 18 && l.horaInicial.minuto >= 1 &&
             l.horaFinal.hora <= 21) {
    return 3;
  } else if (l.horaInicial.hora >= 21 && l.horaInicial.minuto >= 1 &&
             l.horaFinal.hora <= 23) {
    return 4;
  } else {
    return 5;
  }
}

int transformarEmMinutos(Ligacao l) {
  int resultado = (l.horaFinal.hora - l.horaInicial.hora) * 60 +
                  l.horaFinal.minuto - l.horaInicial.minuto;
  return resultado;
}

void calcularPreco(int minutos, Ligacao ligacao, float desconto) {
  printf("\nDesconto de %.f%%\n", desconto * 100);

  float precoNormal = minutos * ligacao.custoPorMinuto;
  float precoDesconto =
      minutos * (ligacao.custoPorMinuto * desconto ? desconto : 1);

  printf("\nPreco sem desconto: R$ %.2f", precoNormal);
  printf("\nPreco com desconto: R$ %.2f\n", precoDesconto);
}

void calcularIntervaloMaior(int minutos, Ligacao ligacao) {
  
}
#ifndef LIGACAO_H
#define LIGACAO_H

typedef struct {
  int hora, minuto;
} Hora;

typedef struct {
  Hora horaInicial, horaFinal;
  float custoPorMinuto;
} Ligacao;

void receberHora(Hora *h);
void receberLigacao(Ligacao *ligacao);
int calcularDesconto(Ligacao l);
int transformarEmMinutos(Ligacao l);
void calcularPreco(int minutos, Ligacao ligacao, float desconto);
void calcularIntervaloMaior(int minutos, Ligacao ligacao);
#endif
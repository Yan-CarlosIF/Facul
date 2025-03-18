#include <stdio.h>

// Faça um programa que receba um número entre 1 e 10.000 e mostre o valor digitado por extenso. 
// digite um número: 10.500 -> número inválido 
// digite um número: 130 -> cento e trinta 
// digite um número: 5 -> cinco 
// digite um número: 1.259 -> um mil e duzentos e cinquenta e nove

void imprimeUnidade(int unidade);
void imprimeDezena(int dezena, int unidade);
void imprimeCentena(int centena, int dezena, int unidade);
void imprimeMilhar(int milhar, int centena, int dezena, int unidade);

int main() {
  int numero;
  printf("Digite um número entre 1 e 10.000: ");
  scanf("%d", &numero);
    
  if (numero < 1 || numero > 10000) {
    printf("Número inválido\n");
    return 1;
  }
    
  if (numero == 10000) {
    printf("dez mil\n");
    return 0;
  }
    
  int milhar = numero / 1000;
  int centena = (numero % 1000) / 100;
  int dezena = (numero % 100) / 10;
  int unidade = numero % 10;
    
  if (milhar > 0) {
    imprimeMilhar(milhar, centena, dezena, unidade);
  }
    
  if (centena > 0) {
    imprimeCentena(centena, dezena, unidade);
  }
    
  if (dezena > 0) {
    imprimeDezena(dezena, unidade);
  } else if (unidade > 0) {
    imprimeUnidade(unidade);
  }
    
  printf("\n");
  return 0;
}
    
void imprimeUnidade(int unidade) {
  switch (unidade) {
    case 1: printf("um"); break;
    case 2: printf("dois"); break;
    case 3: printf("três"); break;
    case 4: printf("quatro"); break;
    case 5: printf("cinco"); break;
    case 6: printf("seis"); break;
    case 7: printf("sete"); break;
    case 8: printf("oito"); break;
    case 9: printf("nove"); break;
  }
}
    
void imprimeDezena(int dezena, int unidade) {
  if (dezena == 1) {
    switch (unidade) {
      case 0: printf("dez"); break;
      case 1: printf("onze"); break;
      case 2: printf("doze"); break;
      case 3: printf("treze"); break;
      case 4: printf("quatorze"); break;
      case 5: printf("quinze"); break;
      case 6: printf("dezesseis"); break;
      case 7: printf("dezessete"); break;
      case 8: printf("dezoito"); break;
      case 9: printf("dezenove"); break;
    }
  } else {
    switch (dezena) {
      case 2: printf("vinte"); break;
      case 3: printf("trinta"); break;
      case 4: printf("quarenta"); break;
      case 5: printf("cinquenta"); break;
      case 6: printf("sessenta"); break;
      case 7: printf("setenta"); break;
      case 8: printf("oitenta"); break;
      case 9: printf("noventa"); break;
    }
    if (unidade > 0) {
      printf(" e ");
      imprimeUnidade(unidade);
    }
  }
}

void imprimeCentena(int centena, int dezena, int unidade) {
  if (centena == 1 && dezena == 0 && unidade == 0) {
    printf("cem");
  } else if (centena == 1) {
    printf("cento");
  } else {
    switch (centena) {
      case 2: printf("duzentos"); break;
      case 3: printf("trezentos"); break;
      case 4: printf("quatrocentos"); break;
      case 5: printf("quinhentos"); break;
      case 6: printf("seiscentos"); break;
      case 7: printf("setecentos"); break;
      case 8: printf("oitocentos"); break;
      case 9: printf("novecentos"); break;
    }
  }
  if (dezena > 0 || unidade > 0) {
    printf(" e ");
  }
}

void imprimeMilhar(int milhar, int centena, int dezena, int unidade) {
  if (milhar == 1) {
    printf("mil");
  } else {
    imprimeUnidade(milhar);
    printf(" mil");
  }
  if (centena > 0 || dezena > 0 || unidade > 0) {
    printf(" e ");
  }
}
#include "./structs/13.17/ligacao.c"

int main() {
  Ligacao ligacao;

  receberLigacao(&ligacao);

  int minutos = transformarEmMinutos(ligacao);

  switch (calcularDesconto(ligacao)) {
    case 1:
      calcularPreco(minutos, ligacao, 0.5);
      break;
    case 2:
      calcularPreco(minutos, ligacao, 0);
      break;
    case 3:
      calcularPreco(minutos, ligacao, 0.3);
      break;
    case 4:
      calcularPreco(minutos, ligacao, 0.4);
      break;
    case 5:

    default:
      break;
  }

  return 0;
}
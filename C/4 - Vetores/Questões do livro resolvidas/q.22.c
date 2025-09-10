#include <stdio.h>
#define ACCOUNTS 2

int accountExists(int *codes, int size, int code) {
  if (size == 0) return 0;

  for (int i = 0; i < size; i++) {
    if (codes[i] == code) return 1;
  }

  return 0;
}

int main() {
  int codes[ACCOUNTS];
  float balances[ACCOUNTS];

  for (int i = 0; i < ACCOUNTS; i++) {
    int code;
    do {
      printf("Insira o codigo da %d conta:", i + 1);
      scanf("%d", &code);
    } while (accountExists(codes, i + 1, code));
    codes[i] = code;

    printf("Insira o saldo da conta %d:", codes[i]);
    scanf("%f", &balances[i]);
  }

  int op;

  do {
    printf("1. Efetuar deposito\n2. Efetuar saque\n");
    printf(
        "3. Consultar o ativo bancário, ou seja, o somatório dos saldos de "
        "todos os clientes\n");
    printf("4. Finalizar Programa\n");
    scanf("%d", &op);

    switch (op) {
      case 1: {
        int code;
        printf("Insira o codigo da conta:");
        scanf("%d", &code);

        if (!accountExists(codes, ACCOUNTS, code)) {
          printf("Conta nao encontrada\n");
          break;
        }

        float deposit;
        printf("Insira o valor do deposito:");
        scanf("%f", &deposit);

        deposit = deposit < 0 ? deposit * -1 : deposit;
        int i;
        for (i = 0; code != codes[i]; i++);

        balances[i] += deposit;
        break;
      }
      case 2: {
        int code;
        printf("Insira o codigo da conta:");
        scanf("%d", &code);

        if (!accountExists(codes, ACCOUNTS, code)) {
          printf("Conta nao encontrada\n");
          break;
        }

        float withdraw;
        printf("Insira o valor do saque:");
        scanf("%f", &withdraw);

        withdraw = withdraw < 0 ? withdraw * -1 : withdraw;
        int i;
        for (i = 0; code != codes[i]; i++);

        if (withdraw > balances[i]) {
          printf("Saldo insuficiente\n");
          break;
        }

        balances[i] -= withdraw;
        break;
      }
      case 3: {
        float sum = 0;
        for (int i = 0; i < ACCOUNTS; i++) sum += balances[i];
        printf("somatorio: %.2f\n", sum);
        break;
      }
      case 4:
        break;
      default:
        printf("opção inválida");
    }
  } while (op != 4);

  return 0;
}
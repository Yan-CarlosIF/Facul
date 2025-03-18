#include <stdio.h>

int fatorial(int num) {
    if (num == 0) {
        return 1;
    } else {
        return num * fatorial(num - 1);
    }
}

int main() {
    int num;

    do {
        printf("Digite um numero:");
        scanf("%d", &num);

        printf("\nFatorial de %d: %d\n", num, fatorial(num));
    } while (num >= 0);

    return 0;
}

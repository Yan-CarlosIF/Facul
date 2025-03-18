#include <stdio.h>
#include <stdlib.h>

int main() {
    float n1, n2, n3;
    printf("Digite um numero:");
    scanf("%f", &n1);
    printf("Digite outro numero:");
    scanf("%f", &n2);
    printf("Digite outro numero:");
    scanf("%f", &n3);

    if (n1 < n2 && n2 < n3) {
        printf("O maior entre eles e %f", n3);
    } else if (n2 < n1 && n1 < n3) {
        printf("O maior entre eles e %f", n3);
    } else if (n3 < n1 && n1 < n2) {
        printf("O maior entre eles e %f", n2);
    } else if (n1 < n3 && n3 < n2) {
        printf("O maior entre eles e %f", n2);
    } else if (n3 < n2 && n2 < n1) {
        printf("O maior entre eles e %f", n1);
    } else if (n2 < n3 && n2 < n1) {
        printf("O maior entre eles e %f", n3);
    } else {
        printf("Os numeros sao iguais");
    }

    return 0;
}
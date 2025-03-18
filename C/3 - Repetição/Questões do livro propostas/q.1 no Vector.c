#include <stdio.h>

void ordemCrescente(int *a, int *b, int *c, int *d);
void ordemDecrescente(int *a, int *b, int *c, int *d);
void imprimir(int *a, int *b, int *c, int *d);

int main() {
    int a, b, c, d;
    
    for (int i = 0; i < 5; i++) {
        printf("Digite os numeros do grupo %d: ", i + 1);
        scanf("%d %d %d %d", &a, &b, &c, &d);

        imprimir(&a, &b, &c, &d);

        printf("\n");
    }
    
    return 0;   
}

void ordemCrescente(int *a, int *b, int *c, int *d) {
    int aux;
    if (*a > *b) { aux = *a; *a = *b; *b = aux; }
    if (*a > *c) { aux = *a; *a = *c; *c = aux; }
    if (*a > *d) { aux = *a; *a = *d; *d = aux; }
    if (*b > *c) { aux = *b; *b = *c; *c = aux; }
    if (*b > *d) { aux = *b; *b = *d; *d = aux; }
    if (*c > *d) { aux = *c; *c = *d; *d = aux; }
}

void ordemDecrescente(int *a, int *b, int *c, int *d) {
    int aux;
    if (*a < *b) { aux = *a; *a = *b; *b = aux; }
    if (*a < *c) { aux = *a; *a = *c; *c = aux; }
    if (*a < *d) { aux = *a; *a = *d; *d = aux; }
    if (*b < *c) { aux = *b; *b = *c; *c = aux; }
    if (*b < *d) { aux = *b; *b = *d; *d = aux; }
    if (*c < *d) { aux = *c; *c = *d; *d = aux; }
}

void imprimir(int *a, int *b, int *c, int *d) {
    printf("Grupo na ordem recebida: %d %d %d %d\n", *a, *b, *c, *d);
    ordemCrescente(a, b, c, d);
    printf("Grupo na ordem crescente: %d %d %d %d\n", *a, *b, *c, *d);
    ordemDecrescente(a, b, c, d);
    printf("Grupo na ordem decrescente: %d %d %d %d\n", *a, *b, *c, *d);
}
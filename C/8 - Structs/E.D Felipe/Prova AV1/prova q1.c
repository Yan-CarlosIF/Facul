#include <stdio.h>
#include <stdlib.h>

// Escreva um programa em C para tratar uma sequencia de numeros inteiros. O usuário entrará primeiro um numero inteiro que corresponde
// a quantos numeros ele pretende inserir no sistema. Você deve ser capaz de ler e armazenar em memoria cada um dos números. 
// Após a leitura exiba a sequência e permita ao usuário informar se deseja inserir mais numeros, por informar um tamanho adicional,
// via numero inteiro. Caso o valor seja maior que 0, aumente o espaço em memoria e leia estes numeros adicionais. Caso o usuário informe 0,
// agora permita que ele infome um valor minimo e um valor maximo que ele deseja visualizar dos dados inseridos, e busque nos dados e apresente os
// valores que se enquadrem. Tambem apresente quantos numeros ficaram de fora do criterio. Por exemplo:
// 1.1.  5
// 1.2.  1
// 1.3.  5
// 1.4.  6
// 1.5.  2
// 1.6.  3
// 1.7.  1 5 6 2 3
// 1.8.  0
// 1.9.  3
// 1.10. 5

// espera-se que o usuário ao final veja na tela: 5 3 3 

int main() {
    int *numeros = NULL, tamanho;

    printf("Digite quantos numeros pretende inserir no sistema: ");
    scanf("%d", &tamanho);

    numeros = (int *)malloc(tamanho * sizeof(int));

    printf("\nDigite %d numeros:\n", tamanho);
    for (int i = 0; i < tamanho; i++) {
        scanf("%d", (numeros + i));
    }

    printf("\nSequencia de numeros:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", *(numeros + i));
    }

    int novoTamanho;
    do {
        printf("\nDeseja inserir mais numeros? (1 para sim, 0 para verificar intervalos,-1 para nao): ");
        scanf("%d", &novoTamanho);

        if (novoTamanho > 0) {
            int *temp = realloc(numeros, (novoTamanho + tamanho) * sizeof(int));

            if (temp == NULL) {
                printf("\nErro ao alocar memoria!\n");
                return 1;
            }
            numeros = temp;

            printf("\nDigite mais %d numeros:\n", novoTamanho - tamanho);
            for (int i = tamanho; i < novoTamanho; i++) {
                scanf("%d", (numeros + i));
            }

            tamanho = novoTamanho;
        } else if (novoTamanho == 0) {
            int min, max, fora = 0;

            printf("\nDigite o valor minimo: ");
            scanf("%d", &min);
            printf("Digite o valor maximo: ");
            scanf("%d", &max);

            printf("\nNumeros dentro do intervalo: ");
            for (int i = 0; i < tamanho; i++) {
                if (*(numeros + i) >= min && *(numeros + i) <= max) {
                    printf("%d ", *(numeros + i));  
                } else {
                    fora++;
                }
            }

            printf("\nQuantidade de numeros fora do intervalo: %d\n", fora);    
        }
    } while (novoTamanho != -1);

    free(numeros);
    return 0;
}
#include <stdio.h>

int main() {
    int i,j,vetor1[5],vetor2[10],matriz[4][3],maior,menor,mult,matrizR[4][3],soma_paresLinha[4] = {0},cont1_5[3] = {0};
    printf("Digite 5 numeros:\n");
    for (i = 0; i < 5; i++) {
        scanf("%d",&vetor1[i]);
        if (i == 0) {
            maior = vetor1[i];
        } else if (maior < vetor1[i]) {
            maior = vetor1[i];
        }
    }   

    printf("\nDigite mais 10 numeros:\n");
    for (i = 0; i < 10; i++) {
        scanf("%d",&vetor2[i]);
        if (i == 0) {
            menor = vetor2[i];
        } else if (maior > vetor2[i]) {
            menor = vetor2[i];
        }
    }
    mult = menor*maior;
    
    printf("\nPreencha uma matriz 4x3:\n");
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 3; j++) {
            printf("Digite o elementos [%dx%d] da matriz:",i+1,j+1);
            scanf("%d",&matriz[i][j]);
        }
    }
    
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 3; j++) {
            matrizR[i][j] = matriz[i][j] + mult;
        }
    }

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 3; j++) {
            if (matrizR[i][j]%2 == 0) {
                soma_paresLinha[i] += matrizR[i][j];
            }
        }
    }

    for (j = 0; j < 3; j++) {
        for (i = 0; i < 4; i++) {
            if (matrizR[i][j] > 1 && matrizR[i][j] < 5) {
                cont1_5[i]++;
            }
        }
    }

    printf("\nMatriz Resultante:\n");
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d ",matrizR[i][j]);
        }
        printf("\n");
    }
    printf("\nSoma dos Pares em cada linha:\n");
    for (i = 0; i < 4; i++) {
        printf("Linha %d = %d\n",i+1,soma_paresLinha[i]);
    }
    printf("\nQuantidade de numeros entre 1 e 5 em cada coluna:\n");
    for (i = 0; i < 3; i++) {
        printf("Coluna %d = %d\n",i+1,cont1_5[i]);
    }
    return 0;
}
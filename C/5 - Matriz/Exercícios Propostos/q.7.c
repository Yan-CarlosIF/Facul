// Elabore um programa que preencha uma matriz M de ordem 4 X 6 e uma segunda matriz N de ordem 6 X 4
// calcule e imprima a soma das linhas de M com as colunas de N. 

#include <stdio.h>
#include <stdbool.h>
#define lines 4
#define coluns 6

void imprimeMatriz(const int rows, const int cols, int M[rows][cols]){
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", M[i][j]);
        }
        printf("\n");
    }  
}

int main() {
    int M[lines][coluns], N[coluns][lines], sum[lines][coluns];

    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < coluns; j++) {
            printf("Digite o valor [%dx%d] da matriz M:", i+1, j+1);
            scanf("%d", &M[i][j]);
        }
    }

    for (int i = 0; i < coluns; i++) {
        for (int j = 0; j < lines; j++) {
            printf("Digite o valor [%dx%d] da matriz N:", i+1, j+1);
            scanf("%d", &N[i][j]);
            sum[j][i] = M[j][i] + N[i][j];
        }
        
    }

    printf("\nMatriz M:\n");
    imprimeMatriz(lines, coluns, M);
    
    printf("\nMatriz N:\n");
    imprimeMatriz(coluns, lines, N);
    
    printf("\nMatriz Resultante:\n");
    imprimeMatriz(lines, coluns, sum);
    
    return 0;
}
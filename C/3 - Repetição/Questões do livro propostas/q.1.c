#include <stdio.h>

int main() {
    int grupos[5][4];

    char nomes[4] = {'A', 'B', 'C', 'D'};
    
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            printf("Digite um numero %c do grupo %d: ", nomes[j], i + 1);
            scanf("%d", &grupos[i][j]);
        }
        printf("\n");

        printf("Grupo %d na ordem recebida: ", i + 1);
        for (int j = 0; j < 4; j++) {
            printf("%d ", grupos[i][j]);
        }

        printf("\nGrupo %d na ordem crescente: ", i + 1);
        for (int j = 0; j < 4; j++) {
            for (int k = j; k < 4; k++) {
                if (grupos[i][j] > grupos[i][k]) {
                    int aux = grupos[i][j];
                    grupos[i][j] = grupos[i][k];
                    grupos[i][k] = aux;
                }
            }
            printf("%d ", grupos[i][j]);
        }

        printf("\nGrupo %d na ordem decrescente: ", i + 1);
        for (int j = 0; j < 4; j++) {
            for (int k = j; k < 4; k++) {
                if (grupos[i][j] < grupos[i][k]) {
                    int aux = grupos[i][j];
                    grupos[i][j] = grupos[i][k];
                    grupos[i][k] = aux;
                }
            }
            printf("%d ", grupos[i][j]);
        }
        printf("\n\n");
    }
    
    return 0;   
}
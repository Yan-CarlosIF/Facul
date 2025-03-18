#include <stdio.h>
#include <string.h>

int main() {
    const int cidades = 5;
    int i,j;
    char nomes_cid[cidades][30];
    float distancia_cid[cidades][cidades],consumo;

    for (i = 0; i < cidades; i++) {
        printf("\nDigite o nome da %d cidade:",i+1);
        fflush(stdin);
        fgets(nomes_cid[i],sizeof(nomes_cid[i]),stdin);
        nomes_cid[i][strcspn(nomes_cid[i],"\n")] = '\0';
    }
    printf("\n");
    for (i = 0; i < cidades; i++) {
        for (j = 0; j < cidades; j++) {
            if (i == j) {
                distancia_cid[i][j] = 0;
            } else {
                printf("Digite a Distancia da cidade %d para a cidade %d:",i+1,j+1);
                scanf("%f",&distancia_cid[i][j]);
            }
        }
        printf("\n");
    }

    printf("\nDigite o consumo de combustivel por Km:");
    scanf("%f",&consumo);
    printf("\nPercursos que nao ultrapassam os 250 Km:\n");
    for (i = 0; i < cidades; i++) {
        for (j = 0; j < cidades; j++) {
            if (i == j) {

            } else if (distancia_cid[i][j] <= 250) {
                printf("\nPercurso da cidade %s para %s de %.1f Km\n",nomes_cid[i],nomes_cid[j],distancia_cid[i][j]);
            }
        }
    }
    printf("\nTodos os Percursos:\n");
    for (i = 0; i < cidades; i++) {
        for (j = 0; j < cidades; j++) {
            if (i == j){ 

            } else {
                printf("\nPercurso da cidade %s para %s de %.1f Km, consome %.1f litros de Gasolina\n",nomes_cid[i],nomes_cid[j],distancia_cid[i][j],distancia_cid[i][j]/(float)consumo);
            }
        }
    }
    return 0;
}
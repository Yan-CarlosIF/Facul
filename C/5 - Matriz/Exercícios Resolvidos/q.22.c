#include <stdio.h>

int main() {
    const int armazem = 5;
    const int prod = 3;
    int i,j,arm_maior = 0,arm_menor;
    float estoque[armazem][prod],cont_arm[4] = {0},maior_est = 0,menor_est,custo_total[3] = {0},custo_totalarm[4] = {0};

    for (i = 0; i < armazem; i++) {
        for (j = 0; j < 3; j++) {
            if (i < 4) {
                printf("Digite o estoque do %d produto no %d armazem:",j+1,i+1);
                scanf("%f",&estoque[i][j]);
                cont_arm[i] += estoque[i][j];
                if (j == 1) {
                    if (maior_est < estoque[i][j]) {
                        maior_est = estoque[i][j];
                        arm_maior = i + 1;
                    }
                }
            } else {
                printf("Digite o preço do %d produto nos armazens:",j+1);
                scanf("%f",&estoque[i][j]);
            }
        }
        printf("\n");
    }

    for (i = 0; i < armazem - 1; i++) {
        if (i == 0) {
            menor_est = cont_arm[i];
            arm_menor = i+1;
        } else if (menor_est > cont_arm[i]) {
            menor_est = cont_arm[i];
            arm_menor = i+1;
        }
    }

    printf("\nA quantidade de produtos no estoque de cada armazém:\n");
    for (i = 0; i < armazem - 1; i++) {
        printf("Armazem %d:\nQuantidade %.f\n",i+1,cont_arm[i]);
        printf("\n");
    }

    printf("\nO armazem que possui o maior estoque do produto 2 é o armazem de numero %d\n",arm_maior);
    printf("\nO armazem que possui o menor menor estoque é o armazem de numero %d\n",arm_menor);

    for (j = 0; j < prod; j++){
        for (i = 0; i < armazem - 1; i++){
            custo_total[j] += estoque[i][j];
        }
        custo_total[j] *= estoque[4][j];
    }

    printf("\nO custo total de cada produto:\n");
    for (i = 0; i < prod; i++) {
        printf("Produto %d:\nCusto = %.2f\n",i+1,custo_total[i]);
        printf("\n");
    }
    
    j = 0;
    for (i = 0; i < armazem; i++) {
        custo_totalarm[i] = cont_arm[i] * estoque[4][j];
        j++;
    }

    printf("\nO custo total de cada armazem:\n");
    for (i = 0; i < prod; i++) {
        printf("Armazem %d:\nCusto = %.2f\n",i+1,custo_totalarm[i]);
        printf("\n");
    }
    return 0;
}
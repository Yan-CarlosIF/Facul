#include <stdio.h>

int main() {
    const int lin = 4;
    const int col = 4;
    int i,j,m[lin][col],soma_lin[lin],soma_col[col],soma_diap=0,soma_dias=0,igual,somas=0;

    for (i = 0; i < lin; i++) {
        for (j = 0; j < col; j++) {
            printf("Digite [%dx%d] da matriz",i+1,j+1);
            scanf("%d",&m[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < lin; i++) {
        soma_lin[i] = 0;
        for (j = 0; j < col; j++) {
            soma_lin[i]+=m[i][j];
        }
    }

    for (i = 0; i < col; i++) {
        soma_col[i] = 0;
        for (j = 0; j < lin; j++) {
            soma_col[i]+=m[i][j];
        }
    }

    for (i = 0; i < lin; i++){
        soma_diap+=m[i][i];
    }

    for (i = 0; i < lin; i++){
        soma_dias+=m[i][lin - 1 - i];
    }

    igual = 1;
    for (i = 0; i < lin; i++) { 
        if (soma_lin[i] != soma_col[i]) {
            igual = 0;
        }
    }
    if (igual){
        somas = soma_lin[i-1];
    }
    if (somas != soma_diap && somas != soma_dias) {
        igual = 0;
    }
    
    if (igual) {
        printf("\nA matriz eh quadrado magico!\n");
    } else {
        printf("\nA matriz nao eh quadrado magico\n");
    }
    
    return 0;
}
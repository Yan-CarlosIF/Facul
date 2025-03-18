#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    float n;
    printf("Digite um valor != de 0:");
    scanf("%f",&n);
    while (n>0)
    {
        printf("\no quadrado %f",pow(n,2));
        printf("\no cubo %f",pow(n,3));
        printf("\na raiz quadrada %f\n",sqrt(n));
        printf("\nDigite outro valor:\nCaso deseje finalizar o programa digite um valor negativo ou 0!\n");
        scanf("%f",&n);
    }
    return 0;
}
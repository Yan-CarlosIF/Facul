#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,n,cont,contg=0;
    for (i = 1; i <=10; i++){
        cont=0;
        printf("\nDigite o %d numero:",i);
        scanf("%d",&n);
        for (int j=1; j<=n;j++){
        if (n%j==0){
            cont++;
        }
        }
        if (cont==2){
            contg++;
        }
    }
    printf("\nQuantidade de numeros primos: %d",contg);
    return 0;
}
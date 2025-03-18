#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,n,somapri=0,somapar=0,contpri=0;
    for (i = 1; i <=10; i++)
    {
        printf("\nDigite o %d numero:",i);
        scanf("%d",&n);
        if (n%2==0)
        {
            somapar+=n;
        }
        for (int j=1; j<=n;j++){
            if (n%j==0){
                contpri++;
            }
        }
    }
    printf("\nSoma dos numeros pares: %d",somapar);
    printf("\nSoma dos numeros primos: %d",somapri);
    return 0;
}
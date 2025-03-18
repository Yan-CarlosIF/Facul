#include <stdio.h>
#define tam 9

int main()
{
    int numeros[tam];
    printf("Digite %d numeros inteiros\n", tam);
    for (int i = 0; i < tam; i++)
    {
        scanf("%d",&numeros[i]);
    }

    for (int i = 0; i < tam; i++)
    {
        int cont = 0;
        
        for (int j = 1; j <= numeros[i]; j++) {
            if (numeros[i] % j == 0) {
                cont++;
            }
        }

        if (cont == 2) {
            printf("O numero %d eh primo e esta da %d posicao do array\n", numeros[i], i + 1); 
        }
    }

    return 0;
}
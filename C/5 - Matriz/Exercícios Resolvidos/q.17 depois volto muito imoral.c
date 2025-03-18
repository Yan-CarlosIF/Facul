#include <stdio.h>
#include <stdbool.h>
#define tam 3

int main()
{
    int numero, matriz[tam][tam], diagoPL = 0, acimaL = 0, acimaC = 1, abaixoL = 1, abaixoC = 0, limiteA = 1, limiteB = 0;
    bool cheio5 = false, cheio11 = false, cheio13 = false;

    for (int i = 0; i < tam * tam; i++)
    {
        do
        {
            cheio5 = false;
            cheio11 = false;
            cheio13 = false;
            printf("Digite o numero %d da matriz:", i + 1);
            scanf("%d", &numero);

            if (diagoPL >= tam)
            {
                printf("Diagonal principal totalmente preenchida!\n");
                cheio5 = true;
            }
            if (limiteA >= tam)
            {
                printf("Nao existe espaco acima da diagonal principal!\n");
                cheio11 = true;
            }
            if (limiteB >= tam - 1)
            {
                printf("Nao existe espaco abaixo da diagonal principal!\n");
                cheio13 = true;
            }
            printf("\n %d | %d | %d \n", cheio5, cheio11, cheio13);
        } while ((numero <= 0) || (numero % 5 != 0 && numero % 11 != 0 && numero % 13 != 0) || (cheio5 != 0 && cheio11 != 0 && cheio13 != 0));

        if (numero % 5 == 0 && diagoPL < tam)
        {
            matriz[diagoPL][diagoPL] = numero;
            diagoPL++;
        }
        else if (numero % 11 == 0 && limiteA < tam)
        {
            matriz[acimaL][acimaC] = numero;
            acimaC++;
            if (acimaC >= tam)
            {
                limiteA++;
                acimaC = limiteA;
                acimaL++;
            }
        }
        else if (numero % 13 == 0 && limiteB < tam - 1)
        {
            matriz[abaixoL][abaixoC] = numero;
            abaixoC--;
            if (abaixoC < 0)
            {
                limiteB++;
                abaixoC = limiteB;
                abaixoL++;
            }
        }
    }

    printf("\nMatriz:\n");
    for (int i = 0; i < tam; i++)
    {
        for (int j = 0; j < tam; j++)
        {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}

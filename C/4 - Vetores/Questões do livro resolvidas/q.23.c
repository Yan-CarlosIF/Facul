#include <stdio.h>
#define tam 24
int main()
{
    int i,janela[tam],corredor[tam],cond,n_poltrona,teste=0;
    char poltrona;
    for (i=0;i<tam;i++)
    {
        janela[i]=0;
        corredor[i]=0;
    }
    do
    {
        printf("\nInsira:\n1 - Vender passagem\n2 - Mostrar mapa de ocupacao do onibus\n3 - encerrar o programa\n:");
        scanf("%d",&cond);
        switch (cond)
        {
        case 1:
            teste=0;
            for (i=0;i<tam;i++)
            {
                if (janela[i])
                {
                    teste++;
                }
                if (corredor[i])
                {
                    teste++;
                }
            }
            if (teste==tam+tam)
            {
                printf("\nOnibus lotado!\n");
            }
            else
            {
            printf("\nVoce escolheu comprar uma passagem!\n");
            do
            {
                printf("\nVoce deseja viajar na janela ou no corredor?\nINSIRA J - janela e C - corredor\n:");
                fflush(stdin);
                poltrona = fgetc(stdin); 
            } while (poltrona != 'J' && poltrona != 'j' && poltrona != 'C' && poltrona != 'c');
            do{
            printf("\nQual o numero da poltrona\nde 1 a 24:");
            scanf("%d",&n_poltrona);
            } while (n_poltrona < 1 || n_poltrona > tam);
            
            if (poltrona == 'J' || poltrona == 'j')
            {
                if (!janela[n_poltrona-1])
                {
                    janela[n_poltrona-1]=1;
                    printf("\nVenda efetivada!\n");
                }
                else if (janela[n_poltrona-1])
                {
                    printf("\nPoltrona ocupada!\n");
                }
            }
            if (poltrona == 'C' || poltrona == 'c')
            {
                if (!corredor[n_poltrona-1])
                {
                    corredor[n_poltrona-1]=1;
                    printf("\nVenda efetivada!\n");
                }
                else if (corredor[n_poltrona-1])
                {
                    printf("\nPoltrona ocupada!\n");
                }
            }
            }
            break;
        case 2:
            printf("\nVoce escolheu mostrar mapa de ocupacao\n\n");
            printf("Janela:                           Corredor:\n");
            for (i=0;i<tam;i++)
            {

                if (janela[i]==0)
                {
                    printf("%d - Descupado",i+1);
                }
                if (janela[i]==1)
                {
                    printf("%d - Ocupado",i+1);
                }
                if (corredor[i]==0)
                {
                    printf("                     %d - Descupado",i+1);
                }
                if (corredor[i]==1)
                {
                    printf("                     %d - Ocupado",i+1);
                }
                printf("\n");
            }
            break;
        default:;
        }
    } while (cond != 3);
    return 0;
}
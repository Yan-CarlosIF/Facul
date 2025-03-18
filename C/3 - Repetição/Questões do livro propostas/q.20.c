#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,p1,p2,p3;
    float n1,n2,n3;
    do
    {
        printf("\nNo menu de opcoes digite oque deseja executar:\n1 - Media aritmetica\n2 - Media ponderada\n3 - Sair do programa\n:");
        scanf("%d",&i);
        switch(i)
        {
            case 1:
            printf("\nDigite a nota 1:");
            scanf("%f",&n1);
            printf("\nDigite a nota 2:");
            scanf("%f",&n2);
            printf("\nA Media aritmetica: %.1f",(n1+n2)/2);
            break;
            case 2:
            printf("\nDigite a nota 1 e seu peso com um espaco entre eles:");
            scanf("%f %d",&n1,&p1);
            printf("\nDigite a nota 2 e seu peso com um espaco entre eles:");
            scanf("%f %d",&n2,&p2);
            printf("\nDigite a nota 3 e seu peso com um espaco entre eles:");
            scanf("%f %d",&n3,&p3);
            printf("\nMedia ponderada: %.1f",((n1*p1)+(n2*p2)+(n3*p3))/(p1+p2+p3));
            break;
            default:;
        }
        
    }while(i!=3);
    return 0;
}
#include <stdio.h>

int main()
{
    float n1,n2,n3,n4,e1,e2,mp,mf,nr;

    printf("Digite a nota da N1:");
    scanf("%f",&n1);
    printf("\nDigite a nota da N2:");
    scanf("%f",&n2);
    e1=(n1+n2)/2;
    printf("\nDigite a nota da N3:");
    scanf("%f",&n3);
    printf("\nDigite a nota da N4:");
    scanf("%f",&n4);
    e2=(n3+n4)/2;
    mp=((e1*2)+(e2*3))/5;
    if (mp>=7)
    {
        printf("\nSua nota da media parcial foi %.2f e voce esta APROVADO!",mp);
    }
    else if (mp<3)
    {
        printf("\nSua nota da media parcial foi %.2f e voce esta REPROVADO!",mp);
    }
    else   
    {
        printf("\nSua nota da media parcial foi %.2f e voce esta de RECUPERACAO!",mp);
        printf("\nDigite a nota da recuperacao:");
        scanf("%f",&nr);
        mf=(mp+nr)/2;
        
            if (mf>=5)
            {
            printf("\nSua nota da media final foi %.2f e voce esta de APROVADO!",mf); 
            }
            else
            {
            printf("\nSua nota da media final foi %.2f e voce esta de REPROVADO!",mf);
            }
    }

    return 0;
}
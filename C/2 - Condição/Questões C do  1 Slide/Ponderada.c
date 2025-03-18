#include<stdio.h>

int main()
{
    float n1,n2,e1,n3,n4,e2,p1,p2,p3,mp,nr,mf;
    printf("nota 1:");
    scanf("%f", &n1);
    
    printf("nota 2:");
    scanf("%f", &n2);
    
    printf("\nSelecione o peso da nota 1 e 2:");
    scanf("%f", &p1);
    
    printf("\n\nnota 3:");
    scanf("%f", &n3);
    
    printf("nota 4:");
    scanf("%f", &n4);
    
    printf("\nSelecione o peso da nota 3 e 4:");
    scanf("%f", &p2);
    
    e1=(n1+n2)/2;
    e2=(n3+n4)/2;
    p3=p1+p2;
    mp=((e1*2)+(e2*3))/p3;
    
    printf("\n\nM�dia Aritm�tica Ponderada: %.1f",mp);

    if (mp>=7)
    {
       printf("\naprovado");
    }
    else if (mp<3)
    {
        printf("\nreprovado");
    }
    else
    {
        printf("\nrecuperacoaoca");
        scanf("%f",&nr);
        mf=(nr+mp)/2;
        if (mf>=5)
        {
            printf("\naprovado");
        }
        else
        {
            printf("\nreprovado");
        }
    }
    
    return 0;
}

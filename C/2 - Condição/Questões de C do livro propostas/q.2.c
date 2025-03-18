#include <stdio.h>
#include <stdlib.h>

int main()
{
    float n1,n2,m;
    printf("Digite sua primeira nota:\n");
    scanf("%f",&n1);
    printf("Digite sua segunda nota:\n");
    scanf("%f",&n2);

    m=(n1+n2)/2;

    if (m>=7)
    {
        printf("Sua media e %.2f e voce esta aprovado!",m);
    }
    else if (m>=3)
    {
        printf("Sua media e %.2f e voce ira fazer o exame final!",m);
    }
    else
    {
        printf("Sua media e %.2f e voce esta reprovado!",m);
    }
    
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,idade,op,cont_o=0,cont_r=0,cont_b=0;
    float media_o=0;
    for (i = 1; i <=15 ; i++)
    {
        printf("\nDigite a idade do %d espectador:",i);
        scanf("%d",&idade);
        do
        {
        printf("\nDigite a opiniao do %d espectador:\n1 - otimo\n2 - bom\n3 - regular\n:",i);
        scanf("%d",&op);
        }while(op != 1 && op != 2 && op != 3);
        if (op==3)
        {
            media_o+=idade;
            cont_o++;
        }
        if (op==1)
        {
            cont_r++;
        }
        if (op==2)
        {
            cont_b++;
        }
    }
    printf("\nMedia das idades das pessoas que respoderam otimo: %.1f",media_o/cont_o);
    printf("\nA quantidade de pessoas que responderam regular: %d",cont_r);
    printf("\nA percentagem de pessoas que responderam bom, entre todos os espectadores analisados: %.1f",(cont_b/(float)15)*100);
    return 0;
}
#include<stdio.h>
#include<stdlib.h>

int main()
{
    #define des 200
    int vendas=120,vendmax;
    float preco,lucro,lucromax,pmax;
    preco=5;
    while(preco>=1)
    {
        printf("O preco do ingresso eh %.2f e o numero de vendas eh %d\n",preco,vendas);
        lucro=(preco*vendas)-des;
        printf("O lucro esperado para o preco de %.2f, eh de %.2f\n\n",preco,lucro);
        if(preco==5)
        {
            lucromax=lucro;
            pmax=preco;
            vendmax=vendas;
        }
        if(lucromax<lucro)
        {
            lucromax=lucro;
            pmax=preco;
            vendmax=vendas;
        }
        vendas+=26;
        preco-=0.5;
    }
    printf("\nO lucro maximo eh: %.2f",lucromax);
    printf("\nO preco do lucro maximo eh: %.2f",pmax);
    printf("\nO numero de vendas para o maior lucro eh: %d",vendmax);
    return 0;
}
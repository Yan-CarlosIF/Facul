#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int dado()
{
    return (1 + rand() % 6);
}

int main()
{
    int i,x,cont[6]={0};
    srand((unsigned)time(NULL));
    for (i = 0; i < 1000; i++)
    {
        x = dado();
        cont[x-1]++;
    }
    printf("Contagem dos lancamentos de dado:\n");
    for (i = 0; i < 6; i++)
    {
        printf("Numero %d :%d\n",i+1,cont[i]);
        
    }
    printf("\n");
    for (i = 0; i < 6; i++)
    {
        printf("Porcentagem do numero %d: %.1f\n",i+1,(cont[i]*100)/(float)1000);
        
    }
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

int main()
{
    float s;
    printf("Digite seu salario:");
    scanf("%f",&s);

    if (s<500)
    {
        printf("\nseu salario com reajuste eh de:%.2f\n",s+(s*0.30));
    }
    else
    {
        printf("\nvoce nao tem direito a aumento!\n");
    }
    return 0;
}
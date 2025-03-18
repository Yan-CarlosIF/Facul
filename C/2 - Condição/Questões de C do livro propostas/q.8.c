#include <stdio.h>

int main()
{
    float s;
    printf("Digite seu salario:");
    scanf("%f",&s);

    if (s>300)
    {
        printf("\nSeu salario com reajuste eh de: %.2f\n",s+(s*0.15));
    }
    else
    {
        printf("\nSeu salario com reajuste eh de: %.2f\n",s+(s*0.35));
    }
    return 0;
}
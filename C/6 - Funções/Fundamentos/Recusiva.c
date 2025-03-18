#include <stdio.h>

int fatorial(int num)
{
    if (num == 0)
    {
        return 1;
    } 
	else 
	{
        return num * fatorial(num - 1);
        /* if num == 3
           3 * return 2
           2 * return 1
           1 * return 1
           0 == 1   */
    }

    return num;
}

int main()
{  
    int num, resultado;

    printf("Digite um numero:");
    scanf("%d", &num);

    resultado = fatorial(num);

    printf("\nFatorial de %d: %d", num, resultado);
    
    return 0;
}



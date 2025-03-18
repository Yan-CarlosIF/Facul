#include <stdio.h>

float sequencia(int n)
{
    float S = 1;
    for (float i = 1; i <= n; i++)
    {
        S = S + 1/i;
    }

    return S;
}

int main()
{
    int n;

    do {
        printf("Digite um numero:");
        scanf("%d", &n);
    } while (n < 0);

    float result = sequencia(n);

    printf("\nResultado da sequencia: %f\n", result);
    return 0;
}

#include <stdio.h>

int maior(int a,int b)
{
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

int main()
{
    int A,B;

    printf("Digite um numero:");
    scanf("%d",&A);

    printf("Digite outro numero:");
    scanf("%d",&B);

    int maior_n = maior(A,B);
    printf("\nO maior: %d",maior_n);

    return 0;
}
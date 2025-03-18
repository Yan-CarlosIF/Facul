#include <stdio.h>

int main()
{
    int x = 10;

    #define TAM x

    printf("%d\n", TAM);
    return 0;
}
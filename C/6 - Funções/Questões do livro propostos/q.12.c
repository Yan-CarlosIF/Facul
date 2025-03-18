#include <stdio.h>

int exponencia(int n, int z)
{   
    int x = 1;
    for (int i = 0; i < z; i++)
    {
        x *= n;
    }

    return x;
}

int main()
{
    printf("%d", exponencia(2, 3));
    return 0;
}
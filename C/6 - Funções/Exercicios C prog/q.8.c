#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int dado()
{
    return (1 + rand() % 6);
}
int main(void)
{
    int n_dado;
    srand((unsigned)time(NULL));
    n_dado = dado();
    printf("O numero sorteado do dado eh : %d",n_dado);
    return 0;
}
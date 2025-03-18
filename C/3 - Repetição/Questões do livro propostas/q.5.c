#include<stdio.h>
#include<stdlib.h>

int main()
{
    int i,j,m;
    for (i = 1; i <=10 ; i++)
    {
        printf("A tabuada de %d:\n",i);
        for (j = 1; j<=10 ; j++)
        {
            m=i*j;
            printf("%d x %d = %d\n",i,j,m);
        }
        printf("\n");
    }
    return 0;
}
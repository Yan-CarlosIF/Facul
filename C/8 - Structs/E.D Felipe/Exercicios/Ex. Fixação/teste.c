#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i = 4, j = 3;
    int *pi = &i, *pj = &j;

    	j = pi == pj;
    return 0;
}
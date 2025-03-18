#include <stdio.h>

int main()
{
    int i,n1=0,n2=1,r,n;
    scanf("%d",&n);
    for(i=0;i<5;i++)
    {
        r=n1+n2;
        printf("%d\n",r);
        n1=n2;
        n2=r;
    }
    return 0;
}
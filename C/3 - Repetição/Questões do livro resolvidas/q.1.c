#include <stdio.h>
#include <time.h>
int main()
{  
    int i;
    float s=1000,a=1.5/100,sn;
    struct tm*dha;
    time_t t;
    time (&t);
    dha = localtime(&t);
    for (i = 2006; i <= dha->tm_year+1900; i++)
    {
        sn=s+s*a;
        a*=2;
    }
    printf("em %d ele vai ter o salario de %.2f",dha->tm_year+1900,sn);
    return 0;
}

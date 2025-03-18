#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int i,ano;
    float s=1000,a,sn;
    a=s*0.015;
    struct tm *dha;
	time_t m;

	time (&m);
	dha = localtime(&m);
	ano = dha->tm_year+1900;
    printf("No ano 2005 seu salario era de %.2f\n",s);
    for(i=2006;i<=ano;i+=1)
    {
        sn=s+a;
        printf("No ano %d seu salario era de %.2f\n",i,sn);
        a*=2;
    }
    return 0;
}
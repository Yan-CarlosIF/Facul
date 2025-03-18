#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n,i,f;

	printf("Digite um numero:");
	scanf("%d",&n);
	f=1;
	for(i=1;i<=n;i++)
	{
		f=f*i;
		printf("%d-%d\n",i,f);
	}

	return 0;
}

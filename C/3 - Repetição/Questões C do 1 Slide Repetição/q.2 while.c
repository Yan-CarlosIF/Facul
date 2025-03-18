#include <stdlib.h>
#include <stdio.h>

int main()
{
	int i,x;
	printf("Digite um numero:");
	scanf("%d",&x);
	i=1;
	while(x>1)
	{
		i*=x;
		x--;
	}
	printf("%d",i);
	return 0;
}
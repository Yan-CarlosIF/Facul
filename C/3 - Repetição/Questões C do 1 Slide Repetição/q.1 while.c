#include <stdio.h>

int main()
{
	int i;
	float s=1000,pa=0.015;
	i=2006;
	printf("no ano %d seu salario era:%.2f\n",i-1,s);
	while(i<=2024)
	{
		i++;
		printf("no ano %d seu salario era:%.2f\n",i-1,s+(s*pa));
		pa*=2;
	}
	return 0;
}

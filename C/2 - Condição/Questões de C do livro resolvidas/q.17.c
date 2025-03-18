#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    float a,b,c,x1,x2,d,rd;
    printf("Insira valor de A:");
    scanf("%f",&a);
    printf("Insira valor de B:");
    scanf("%f",&b);
    printf("Insira valor de C:");
    scanf("%f",&c);
	
    d=(b*b)-(4*a*c);
    x1=(-b+sqrt(d))/(2*a);
    x2=(-b-sqrt(d))/(2*a);
    
    if(d<0)
    {
        printf("nao existe raiz real");
    }
    else if(d==0)
    {
        printf("so existe uma raiz real!\nentao x1:%.2f",(-b)/(2*a));
    }
        else
        {
        	printf("\nO delta e %.2f\n",d);
            printf("\nx1:%.2f",x1);
            printf("\nx2:%.2f",x2);
        }
    return 0;
}

#include <stdio.h>
#include <math.h>

void equacao(float a,float b,float c,float delta,float x1,float x2)
{
    delta=(b*b)-(4*a*c);
    printf("Delta = %.1f",delta);
    x1 = (-b - sqrt(delta))/(2*a);
    x2 = (-b + sqrt(delta))/(2*a);
    printf("\nX1 = %.1f\nX2 = %.1f",x1,x2);
}

int main()
{
    float a,b,c,delta,x1,x2;
    printf("Digite o valor de A,B e C:");
    scanf("%f %f %f",&a,&b,&c);
    
    equacao(a,b,c,delta,x1,x2);
    
    return 0;
}
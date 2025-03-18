#include<stdio.h>

int main()
{
    float a,b,c,x;
    printf("Nota 1:");
    scanf("%f", &a);
    printf("Nota 2:");
    scanf("%f", &b);
    printf("Nota 3:");
    scanf("%f", &c);
    x=(a+b+c)/3;
    printf("Média aritmética: %.1f",x);
    return 0;
}

#include<stdio.h>

int main()
{
    float s,a,va,sa;
    
    printf("Sal�rio Base:");
    scanf("%f", &s);
    
    printf("\nAo digitar a porcentagem de aumento colocar 0. a frente!"); 
    
    printf("\n\nAumento:");
    scanf("%f", &a);
    
    va=s*a;
    sa=s+va;
    
    printf("\nValor do aumento:%.2f",va);
    printf("\nSal�rio com aumento:%.2f",sa);
    return 0;
}

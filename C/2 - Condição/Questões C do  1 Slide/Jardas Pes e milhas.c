#include<stdio.h>

int main()
{
    float po,p,j,m;
    
    printf("Digite a medida em pes que deseja transferir:");
    scanf("%f", &p);
    
    j=p/3;
    m=j/1760;
    po=p*12;
    
    printf("\n\nMedida em Jardas:%.3f",j);
    printf("\n\nMedida em polegadas:%.3f",po);
    printf("\n\nMedida em milhas:%.3f",m);
    return 0;
}

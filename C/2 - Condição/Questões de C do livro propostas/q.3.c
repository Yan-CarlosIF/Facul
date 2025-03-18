#include <stdio.h>
#include <stdlib.h>

int main()
{
    float n1,n2;
    printf("Digite um numero:");
    scanf("%f",&n1);
    printf("Digite outro numero:");
    scanf("%f",&n2);

    if(n1<n2){
        printf("O menor entre eles e %f",n1);
    }
    else if(n2<n1){
        printf("O menor entre eles e %f",n2);
    }
    else{
        printf("Os dois numeros sao iguais");
    }
    return 0;
}
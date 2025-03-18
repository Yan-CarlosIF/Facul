#include <stdio.h>
#include <stdlib.h>

int main()
{
    float x,y,z;
    printf("digite o valor de x");
    scanf("%f",&x);
    printf("digite o valor de y");
    scanf("%f",&y);
    printf("digite o valor de z");
    scanf("%f",&z);

    if(x==y && y==z && x==z)
    {
        printf("Triangulo equilatero");
    }
    else
    {
        if(x==y || x==z || y==z)
        {
            printf("Triangulo isoceles");
        }
        else
        {
            if(x!=y && x!=z && y!=z)
           {
               printf("Triangulo Escaleno");
           }
        }
    }
    return 0;
}

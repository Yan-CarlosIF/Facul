#include <stdio.h>
#include <stdio.h>

int main()
{
    float s;
    printf("salario inicial:");
    scanf("%f",&s);

    if(s>1200)
    {
        printf("Novo salario:%.2f",s+100);
    }
    else
    {
        if(s>600)
        {
            printf("Novo salario:%.2f",(s*0.12)+s+100);
        }
        else
        {
            if(s>500)
            {
                printf("Novo salario:%.2f",(s*0.12)+s+150);
            }
            else
            {
                printf("Novo salario:%.2f",(s*0.05)+s+150);
            }
        }
    }
    return 0;
}

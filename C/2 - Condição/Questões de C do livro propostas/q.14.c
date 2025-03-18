#include <stdio.h>

int main()
{
    float s;
    printf("Digite seu salario:");
    scanf("%f",&s);

    if (s<=300)
    {
        printf("\nSeu novo salario eh %.2f\n",s+(s/2));
    }
    else
    {
        if (s<=500)
        {
            printf("\nSeu novo salario eh %.2f\n",s+(s*0.40));
        }
        else
        {
            if (s<=700)
            {
                printf("\nSeu novo salario eh %.2f\n",s+(s*0.30));    
            }
            else
            {
                if (s<=800)
                {
                    printf("\nSeu novo salario eh %.2f\n",s+(s/5));
                }
                else
                {
                    if (s<=1000)
                    {
                        printf("\nSeu novo salario eh %.2f\n",s+(s*0.10));
                    }
                    else
                    {
                        printf("\nSeu novo salario eh %.2f\n",s+(s*0.05));
                    }
                }
            }
        }
    }
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

int main()
{
    float a,p;
    printf("Digite sua altura:");
    scanf("%f",&a);
    printf("\nDigite seu peso:");
    scanf("%f",&p);

    if (a<1.20 && p<=60)
    {
        printf("Sua altura e %.2f,e seu peso %.3f,voce esta classificado como A!",a,p);
    }
    else
    {
        if (a<1.20 && p<=90)
        {
            printf("Sua altura e %.2f,e seu peso %.3f,voce esta classificado como D!",a,p);
        }
        else
        {
            if (a<1.20 && p>90)
            {
                printf("Sua altura e %.2f,e seu peso %.3f,voce esta classificado como G!",a,p);
            }
            else
            {
                if (a<=1.70 && p<=60)
                {
                    printf("Sua altura e %.2f,e seu peso %.3f,voce esta classificado como B!",a,p);
                }
                else
                {
                    if (a<=1.70 && p<=90)
                    {
                        printf("Sua altura e %.2f,e seu peso %.3f,voce esta classificado como E!",a,p);    
                    }
                    else
                    {
                        if (a<=1.70 && p>90)
                        {
                            printf("Sua altura e %.2f,e seu peso %.3f,voce esta classificado como H!",a,p);
                        }
                        else
                        {
                            if (a>1.70 && p<=60)
                            {
                                printf("Sua altura e %.2f,e seu peso %.3f,voce esta classificado como C!",a,p);
                            }
                            else
                            {
                                if (a>1.70 && p<=90)
                                {
                                    printf("Sua altura e %.2f,e seu peso %.3f,voce esta classificado como F!",a,p);
                                }
                                else
                                {
                                    printf("Sua altura e %.2f,e seu peso %.3f,voce esta classificado como I!",a,p);
                                }
                            }  
                        }
                    }
                }
            }  
        }
    }
    return 0;
}
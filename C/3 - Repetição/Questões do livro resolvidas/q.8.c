#include <stdio.h>
#include <stdlib.h>

int main()
{
    int nt,n1=2,n2=7,n3=3,i;
    printf("Digite o n de termos:");
    scanf("%d",&nt);
    printf("\n%d\n",n1);
    printf("%d\n",n2);
    printf("%d\n",n3);
    i=3;
    while(i<=nt)
    {
        if(i!=nt){
            printf("%d\n",n1*=2);
            i++;
        }
        if(i!=nt){
            printf("%d\n",n2*=3);
            i++;
        }
        if(i!=nt){
            printf("%d\n",n3*=4);
            i++;
        }
    }
    return 0;
}

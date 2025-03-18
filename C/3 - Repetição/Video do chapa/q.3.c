#include <stdio.h>

int main(){
    int n1,n2,i;
    printf("Digite o primeiro numero:");
    scanf("%d",&n1);
    printf("Digite o segundo numero:");
    scanf("%d",&n2);
    if (n2>n1)
    {
        for (i=n1;i<=n2;i++)
        {
            printf("%d\n",i);
        }
    }
    else if (n1>n2)
    {
        int aux = n2;
        n2 = n1;
        n1 = aux;
        for (i=n1;i<=n2;i++)
        {
            printf("%d\n",i);
        }
    }
    return 0;
}
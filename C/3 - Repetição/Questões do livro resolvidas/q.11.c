#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x,cont=0;
    do{
        printf("Digite um numero OBRIGATORIAMENTE maior que 1\n:");
        scanf("%d",&x);
    } while(x<2);
    for(int i=1;i<=x;i++){
        if(x%i==0){
            printf("%d\n",cont++);
        }
    }
    if (cont==2){
        printf("\nO numero %d eh primo\n",x);
    }
    else{
        printf("\nO numero %d nao eh primo\n",x);
    }
    return 0;
}
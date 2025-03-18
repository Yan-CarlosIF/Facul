#include<stdio.h>
#include<stdlib.h>

int main(){
    int i,numeros,soma=0,cont_n=0,maior_n=0,menor_n=0,media_par=0,cont_par=0,cont_impar=0;
    i=1;
    while(numeros!=30000)
    {
        printf("\nDigite um numero:");
        scanf("%d",&numeros);
        soma+=numeros;
        if(i==1)
        {
            maior_n=numeros;
            menor_n=numeros;
        }        
        if(maior_n<numeros && numeros!=30000)
        {
            maior_n=numeros;
        }
        if(menor_n>numeros && numeros!=30000)
        {
            menor_n=numeros;
        }
        if(numeros%2==0 && numeros!=30000)
        {
            media_par+=numeros;
            cont_par++;
        }
        if(numeros%2!=0)
        {
            cont_impar++;
        }
        cont_n++;
        i++;
        printf("\nSe deseja encerrar a entrada de dados digite 30000\n");
        scanf("%d",&numeros);
   }
   if (soma==0)
   {
        printf("\nNao foi recebido nenhum numero");
   }
   else
   {
    printf("\nSoma dos numeros digitados: %d",soma);
    printf("\nQuantidade de numeros digitos: %d",cont_n);
    printf("\nMedia dos numeros digitados: %.1f",soma/(float)cont_n);
    printf("\nMaior numero digitado: %d",maior_n);
    printf("\nMenor numero digitado: %d",menor_n);
    printf("\nMedia dos numeros pares: %.1f",(media_par/(float)cont_par));
    printf("\nA porcentagem dos numeros impares entre todos os numeros digitados: %.1f%%",(cont_impar/(float)cont_n)*100);
   }
    return 0;
}
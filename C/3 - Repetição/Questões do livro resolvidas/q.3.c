#include <stdio.h>

int main(){
    int i,vl,n,f;
    printf("Insira quantos valores devem ser lidos:");
    scanf("%d",&vl);
    for (i = 0; i < vl; i++){
        printf("Digite um numero que deseja saber o fatorial:");
        scanf("%d",&n);
        f=1;
        for (int j = 1; j <= n; j++){
            f*=j;
        }
        printf("O Fatorial do numero %d eh %d\n",n,f);
    }
    return 0;
}
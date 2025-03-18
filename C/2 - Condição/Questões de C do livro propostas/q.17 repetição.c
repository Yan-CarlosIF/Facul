#include <stdio.h>
#include <stdlib.h>

int main(){
    int senha,i;
    printf("Digite a senha:");
    scanf("%d",&senha);
    
    for (i = 1;senha != 4531; i++){
        printf("\nAcesso negado! senha incorreta!\n");
        printf("Digite a senha novamente:");
        scanf("%d",&senha);
    }
    printf("\nAcesso concedido,senha correta!\n");
    system("\nPAUSE");
    return 0;
}
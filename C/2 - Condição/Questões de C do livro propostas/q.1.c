#include <stdio.h>
#include <stdlib.h>

int main() {
    float n1, n2, n3, n4;

    printf("Digite a primeira nota:\n");
    scanf("%f", &n1);

    printf("Digite a segunda nota:\n");
    scanf("%f", &n2);

    printf("Digite a terceira nota:\n");
    scanf("%f", &n3);

    printf("Digite a quarta nota:\n");
    scanf("%f", &n4);
    
    float media_aritmetica = (n1 + n2 + n3 + n4) / 4;
    
    printf("Media Aritmetica:%f\n", media_aritmetica);
    if(media_aritmetica >= 7) {
        printf("Aprovado!\n");
    } else {
        printf("Reprovado!\n");
    }
    return 0;
}
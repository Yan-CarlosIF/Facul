#include <stdio.h>
#include <stdlib.h>

int main(){
    int c;
    float s,va;
    printf("Digite o codigo do cargo\n1 para escrituario\n2 para secretario\n3 para caixa\n4 para gerente\n5 para diretor\n");
    scanf("%d",&c);
    printf("\nDigite o salario atual:");
    scanf("%f",&s);

    switch(c){
        case 1:
            va=s*0.50;
            printf("\nO seu cargo e escrituario, o aumento do seu salario foi de %.2f, e seu novo salario � %.2f\n",va,va+s);
            break;
        case 2:
            va=s*0.35;
            printf("\nO seu cargo e secretario, o aumento do seu salario foi de %.2f, e seu novo salario � %.2f\n",va,va+s);
            break;
        case 3:
            va=s*0.20;
            printf("\nO seu cargo e caixa, o aumento do seu salario foi de %.2f, e seu novo salario � %.2f\n",va,va+s);
            break;
        case 4:
            va=s*0.10;
            printf("\nO seu cargo e gerente, o aumento do seu salario foi de %.2f, e seu novo salario � %.2f\n",va,va+s);
            break;
        case 5:
            va=s*0.00;
            printf("\nO seu cargo e diretor, o aumento do seu salario foi de %.2f, e seu novo salario � %.2f\n",va,va+s);
            break;
        default:printf("voce digitou um codigo nao atribuido!");
    }
    return 0;
}

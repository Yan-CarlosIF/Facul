#include <stdio.h>

int main()
{
    float p,pa,vi,np;
    int c;
    char s;
    printf("Digite o preco do produto:");
    scanf("%f",&p);
    do{
    printf("Digite a categoria do produto\n1 - Limpeza 2 - Alimentacao 3 - Vestuario\n");
    scanf("%d",&c);
    } while(c != 1 && c != 2 && c != 3);
    do{
    printf("Digite a situacao\nR - Necessita de refrigeracao\nN - Nao necessita de refrigeracao\n");
    fflush(stdin);
    scanf("%c",&s);
    } while(s != 'R' && s != 'r' && s != 'N' && s != 'n');

    if (p<=25){
        switch (c){
        case 1:
            pa=p*0.05;
            break;
        case 2:
            pa=p*0.08;
            break;
        case 3:
            pa=p*0.10;
            break;
        default:;
        }
    }
    else{
        switch (c){
        case 1:
            pa=p*0.12;
            break;
        case 2:
            pa=p*0.15;
            break;
        case 3:
            pa=p*0.18;
            break;
        default:printf("\nCategoria do produto invalida!");
        break;
        }
    }
    
    if (c==2 || s=='r'|| s=='R'){
        vi=p*0.05;
    }
    else{
        vi=p*0.08;
    }
    np=p+pa-vi;
    if (np<=50){
        printf("\nO novo preco do produto eh %.2f e eh classificado como barato",np);
    }
    else if (np<120){
        printf("\nO novo preco do produto eh %.2f e eh classificado como normal",np);
    }
    else{
        printf("\nO novo preco do produto eh %.2f e eh classificado como caro",np);
    }
    return 0;
}
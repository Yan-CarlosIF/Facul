#include <stdio.h>

int main(){
    float a;
    char sexo;
    printf("Digite seu sexo\nM - para masculino F - para feminino\n");
    scanf("%c",&sexo);
    printf("\nDigite sua altura:");
    scanf("%f",&a);

    if (sexo=='M'||sexo=='m'){
        printf("\nseu peso ideal eh %.3f KG",(72.7*a)/2);
    }
    else if (sexo=='F'||sexo=='f'){
        printf("\nseu peso ideal eh %.3f KG",(62.1*a)/2);
    }
    else{
        printf("\nSexo digitado nao existe, digite M ou F");
    }
    
    return 0;
}
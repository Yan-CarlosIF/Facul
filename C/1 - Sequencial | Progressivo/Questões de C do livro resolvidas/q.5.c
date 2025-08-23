// Faça um programa que receba o salário de um funcionário e o percentual de aumento, calcule e mostre 
// o valor do aumento e o novo salário.

#include <stdio.h>

int main() {
    float salario, percentual_de_aumento;

    printf("Insira o salário do funcionario: ");
    scanf("%f", &salario);
    
    printf("Insira o percentual de aumento: ");
    scanf("%f", &percentual_de_aumento);

    printf("Valor do aumento: %.2fR$\n", salario * (percentual_de_aumento / 100));
    
    return 0;
}
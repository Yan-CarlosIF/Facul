#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i=1,idade,menor,maior,cont_m200=0,id_menors;
    float salario,m_salario=0,menor_s;
    char sexo,sexom;
    do
    {
        printf("\nDigite a idade do %d habitante:",i);
        scanf("%d",&idade);
        do{
        printf("\nDigite o sexo do %d habitante\nM - Masculino\nF - Feminino\n:",i);
        fflush(stdin);
        scanf("%c",&sexo);
        } while(sexo != 'M' && sexo !='F');
        printf("\nDigite o salario do %d habitante:",i);
        scanf("%f",&salario);
        if (i==1)
        {
            maior=idade;
            menor=idade;
            menor_s=salario;
            id_menors=idade;
            sexom=sexo;
        }
        if (maior < idade)
        {
            maior=idade;
        }
        if (menor > idade)
        {
            menor=idade;
        }
        if (menor_s > salario)
        {
            menor_s=salario;
            id_menors=idade;
            sexom=sexo;
        }
        if (salario <=200 && sexo == 'F')
        {
            cont_m200++;
        }
        m_salario+=salario;
        printf("\nSe deseja encerrar a entrada de dados digite um numero de negativo:");
        scanf("%d",&idade);
        i++;
    } while(idade>=0);
    printf("\nMedia dos salários do grupo: %.2f",m_salario/i);
    printf("\nA maior idade do grupo %d\nA menor idade do grupo %d",maior,menor);
    printf("\nA quantidade de mulheres com salario ate R$ 200,00: %d",cont_m200);
    if (sexom=='F')
    {
        printf("\nA pessoa que possui o menor salario de %.2f tem a idade de %d e eh do sexo Feminino",menor_s,id_menors);
    }
    else
    {
        printf("\nA pessoa que possui o menor salario de %.2f tem a idade de %d e eh do sexo Masculino",menor_s,id_menors);
    }
    return 0;
}
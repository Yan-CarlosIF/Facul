#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,cont_r=0,cont_e=0,cont_a=0;
    float n1,n2,m,mtotal,mclasse;
    for (i = 1; i <=6; i++)
    {
        printf("\nDigite sua primeira nota:");
        scanf("%f",&n1);
        printf("\nDigite sua segunda nota:");
        scanf("%f",&n2);
        m=(n1+n2)/2;
        mtotal+=m;
        if (m<3)
        {
            printf("\nNota do aluno %d foi de %.2f e ele esta Reprovado",i,m);
            cont_r++;
        }
        else if (m>=7)
        {
            printf("\nNota do aluno %d foi de %.2f e ele esta Aprovado",i,m);
            cont_a++;
        }
        else
        {
            printf("\nNota do aluno %d foi de %.2f e ele esta no Exame final",i,m);
            cont_e++;
        }
    }
    mclasse=mtotal/6;
    printf("\nO total de alunos aprovados: %d",cont_a);
    printf("\nO total de alunos no exame final: %d",cont_e);
    printf("\nO total de alunos reprovados: %d",cont_r);
    printf("\n Media da classe: %.1f",mclasse);
    return 0;
}
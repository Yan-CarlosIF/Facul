#include <stdio.h>
#define alunos 3
#define provas 3

int main()
{
    int i,j,q1=0,q2=0,q3=0,prova[alunos];
    float notas[alunos][provas],menor[alunos];
    for (i=0;i<alunos;i++)
    {
        prova[i]=0;
        for (j=0;j<provas;j++)
        {
            do {
            printf("Digite a nota da prova %d do %d aluno:",j+1,i+1);
            scanf("%f",&notas[i][j]);
            } while (notas[i][j] > 10 || notas[i][j] < 0);
            if (j==0)
            {
                menor[i]=notas[i][j];
                prova[i]=j+1;
            }
            else if (menor[i] > notas[i][j])
            {
                menor[i] = notas[i][j];
                prova[i]=j+1;
            }
        }
        if (prova[i]==1)
        {
            q1++;
        }
        if (prova[i]==2)
        {
            q2++;
        }
        if (prova[i]==3)
        {
            q3++;
        }
        printf("\n");
    }
    printf("Relatorio:\n");
    for (i=0;i<alunos;i++)
    {
        printf("O aluno %d teve a menor nota da prova %d, nota = %.2f\n",i+1,prova[i],menor[i]);
    }
    printf("\nA quantidade de alunos que tiraram a menor nota na:\n1 prova - %d\n2 prova - %d\n3 prova - %d",q1,q2,q3);
    return 0;
}
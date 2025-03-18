#include <stdio.h>
#include <string.h>
/*Faça um programa para corrigir provas de múltipla escolha. Cada prova tem oito questões e cada 
questão vale um ponto. O primeiro conjunto de dados a ser lido é o gabarito da prova. Os outros da
dos são os números dos alunos e as respostas que deram às questões. Existem dez alunos matriculados. 
Calcule e mostre:
 ■ o número e a nota de cada aluno;
 ■ a porcentagem de aprovação, sabendo-se que a nota mínima é 6.*/
#define questoes 2
#define alunos 2
int main()
{
    int i,alunos_n[alunos],cont_aprov=0;
    float nota[alunos];
    char gab[questoes],res[questoes];
    for (i=0;i<questoes;i++)
    {
        do
        {
        printf("Digite o gabarito da questao %d:\nAlternativas A,B,C ou D\n:",i+1);
        fflush(stdin);
        scanf("%c",&gab[i]);
        } while (gab[i]!='a' && gab[i]!='b' && gab[i]!='c' && gab[i]!='d');
    }
    printf("\n");
    for (i=0;i<alunos;i++)
    {
        nota[i]=0;
        printf("Digite o numero do aluno %d:",i+1);
        scanf("%d",&alunos_n[i]);
        for (int j=0;j<questoes;j++)
        {
            do{
                printf("Digite a resposta do aluno %d da questao %d:",alunos_n[i],j+1);
                fflush(stdin);
                scanf("%c",&res[j]);
                if (res[j]==gab[j])
                {
                    nota[i] += 10 / questoes;
                }
            } while(res[j]!='a' && res[j]!='b' && res[j]!='c' && res[j]!='d');
        }
    }
    printf("\n");
    for (i=0;i<alunos;i++)
    {
        printf("Nota do aluno de numero %d: %.1f\n",alunos_n[i],nota[i]);
        if(nota[i]>=6)
        {
            cont_aprov++;
        }
    }
    float porcent=(cont_aprov*100)/(float)alunos;
    printf("\nPorcentagem de aprovacao sabendo que a media eh 6: %.1f%%",porcent);
    return 0;
}
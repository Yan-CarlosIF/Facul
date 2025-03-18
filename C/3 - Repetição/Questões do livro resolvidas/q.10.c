#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,j,id,cont_j18=0,cont_j80=0;
    float a,p,cont_mi1=0,cont_mi2=0,cont_mi3=0,cont_mi4=0,cont_mi5=0,cont_ma=0;

    for (i = 1;i<=5; i++)
    {
        for (j = 1; j<=11; j++)
        {
            printf("\nIdade do jogador %d do time %d:",j,i);
            scanf("%d",&id);
            if (id<18)
            {
                cont_j18++;
            }
            printf("\nPeso do jogador %d do time %d:",j,i);
            scanf("%f",&p);
            if (p>80)
            {
                cont_j80++;
            }
            printf("\nAltura do jogador %d do time %d:",j,i);
            scanf("%f",&a);
            cont_ma+=a;
            if (i==1)
            {
                cont_mi1+=id;
            }
            if (i==2)
            {
                cont_mi2+=id;
            }
            if (i==3)
            {
                cont_mi3+=id;
            }
            if (i==4)
            {
                cont_mi4+=id;
            }
            if (i==5)
            {
                cont_mi5+=id;
            }
        }
    }
    printf("\n\nA quantidade de jogadores com idade inferior a 18 anos: %d",cont_j18);
    printf("\nA média das idades dos jogadores do time 1:%.1f",cont_mi1/11);
    printf("\nA média das idades dos jogadores do time 2:%.1f",cont_mi2/11);
    printf("\nA média das idades dos jogadores do time 3:%.1f",cont_mi3/11);
    printf("\nA média das idades dos jogadores do time 4:%.1f",cont_mi4/11);
    printf("\nA média das idades dos jogadores do time 5:%.1f",cont_mi5/11);
    printf("\n\nA média das alturas de todos os jogadores do campeonato:%.2f",cont_ma/55);
    printf("\nA porcentagem de jogadores com mais de 80 kg entre todos os jogadores do campeonato:%.1f",(cont_j80/(float)55)*100);
    system("\nPAUSE");
    return 0;
}
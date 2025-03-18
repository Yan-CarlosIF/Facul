#include <stdio.h>
#include <stdlib.h>

int main(){
    int i;
    float sc,sj;
    printf("Digite o salario de Carlos:");
    scanf("%f",&sc);
    sj=sc/3;
    i=1;
    while (sj < sc)
    {
        sc+=(sc*0.02);
        sj+=(sj*0.05);
        i++;
    }
    printf("em %d meses o salario de joão %.2f ultrapassara o de carlos %.2f",i,sj,sc);
    return 0;
}
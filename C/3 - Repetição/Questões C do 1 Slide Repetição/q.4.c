#include <stdio.h>

int main()
{   
    int i,nvei,nacid,c,ncm,ncme,macid=0,meacid=0,cont=0;
    float tvei=0,c_m2=0;
    i=1;
    while (i<=5)
    {
        printf("\nCodigo da cidade:");
        scanf("%d",&c);
        printf("\nNumero de veiculos de passeio:");
        scanf("%d",&nvei);
        printf("\nNumero de acidentes de transito com vitimas:");
        scanf("%d",&nacid);
        i++;
        tvei+=nvei;
        if (macid < nacid)
        {
            macid=nacid;
            ncm=c;
        }
        else
        {
           meacid = nacid;
            ncme=c;
        }
        if (nvei<2000)
        {
            cont++;
            c_m2+=nacid;
        } 
    }
        printf("\nO maior numero de acidentes foi na cidade %d com %d\nO menor numero de acidentes foi na cidade %d com %d\n",ncm,macid,ncme,meacid);
        printf("\nMedia de veiculos nas cinco cidades juntas:%f",tvei/(float)5);
        printf("\nMedia de acidentes em cidades com menos de 2000 veiculos de passeio:%f",c_m2/(float)cont);
    return 0;
}
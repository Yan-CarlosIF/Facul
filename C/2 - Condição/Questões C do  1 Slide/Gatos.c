#include <stdio.h>

    int main(){
    float ps,pg,qg,p,q,g=2,pk;
    
    printf("Digite o peso do saco de ra��o em kg:");
    scanf("%f", &ps);
    
    printf("\nQuanto de ra��o � dada para os gatos em gramas:");
    scanf("%f", &qg);
    
    pg=ps*1000;
    p=pg-((qg*5)*g);
    pk=p/1000;
    
    printf("\nRestara ");printf("%.1f",p);printf(" gramas ou ");printf("%.3f",pk);printf(" kilos no saco.");
    return 0;
}

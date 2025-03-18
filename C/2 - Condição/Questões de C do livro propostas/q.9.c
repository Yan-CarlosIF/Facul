#include <stdio.h>

int main()
{
    float sm,vc;
    printf("Digite o saldo medio:");
    scanf("%f",&sm);

    if (sm>400)
    {
        vc=sm*0.30;
        printf("\nO saldo medio eh de %.2f e o valor do credito eh de %.2f\n",sm,vc);
    }
    else if (sm>300)
    {
        vc=sm*0.25;
        printf("\nO saldo medio eh de %.2f e o valor do credito eh de %.2f\n",sm,vc);
    }
    else if (sm>200)
    {
        vc=sm*0.20;
        printf("\nO saldo medio eh de %.2f e o valor do credito eh de %.2f\n",sm,vc);
    }
    else
    {
        vc=sm*0.10;
        printf("\nO saldo medio eh de %.2f e o valor do credito eh de %.2f\n",sm,vc);
    }
    return 0;
}
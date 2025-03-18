#include <stdio.h>
void valor(int x)
{
    printf("Digite um valor:");
    scanf("%d",&x);
    if (x==0){
        printf("\nEle eh nulo!\n");
    }
    else if (x>0){
        printf("\nEle eh positivo!\n");
    }
    else{
        printf("\nEle eh negativo!\n");
    }
}
int main(){
    int x=0;

    valor(x);
    
    return 0;
}
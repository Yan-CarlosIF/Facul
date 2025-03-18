#include <stdio.h>

void valor(int x) {
    printf("Digite um valor:");
    scanf("%d",&x);
    if (x == 0) {
        printf("\nEle eh nulo!\n");
    }
}
int main() {
    int x=0;

    valor(x);
    
    return 0;
}

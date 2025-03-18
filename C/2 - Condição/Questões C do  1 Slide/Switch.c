#include <stdio.h>

int main() {
    int codigo;
    scanf("%d",&codigo);

    switch (codigo) {
        case 10: case 9:
            printf("Cuida beberes");
            break;
        case 8: case 7:
            printf("OIAI A PUTARIA");
            break;
        default:printf("OOO");
    }
}
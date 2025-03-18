#include <stdio.h>
#include <string.h>

int main() {
    char str1[20], str2[20];

    printf("Digite string 1:");
    fgets(str1, sizeof(str1), stdin);
    printf("Digite string 2:");
    fgets(str2, sizeof(str2), stdin);

    if (stricmp(str1, str2) == 0) {
        printf("\nstrings sao iguais!");
    } else {
        printf("\nstrings sao diferentes!");
    }

    return 0;
}

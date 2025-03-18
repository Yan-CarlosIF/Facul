#include <stdio.h>
#include <string.h>

float medias(float n1, float n2, float n3, char letra);

int main()
{
    float nota1, nota2, nota3;
    char letra;

    printf("Digite a 1ra nota:");
    scanf("%f", &nota1);
    printf("Digite a 2ra nota:");
    scanf("%f", &nota2);
    printf("Digite a 3ra nota:");
    scanf("%f", &nota3);

    do {
        printf("Digite:\nA - Media Aritmetica\nP - Media Ponderada\n");
        fflush(stdin);
        scanf("%c", &letra);
    } while (letra != 'P' && letra != 'p' && letra != 'A' && letra != 'a');

    float media = medias(nota1, nota2, nota3, letra);

    printf("\nMedia das notas: %.1f", media);
    return 0;
}

float medias(float n1, float n2, float n3, char letra)
{
    if (letra == 'P' || letra == 'p')
    {
        return ((n1 * 5) + (n2 * 3) + (n3 * 2)) / (5 + 3 + 2);
    }
    else if (letra == 'A' || letra == 'a')
    {
        return (n1 + n2 + n3) / 3;
    }
}
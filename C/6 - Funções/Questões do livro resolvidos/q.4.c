#include <stdio.h>

void transformaHoras(int seg);

int main()
{
    int segundos;

    printf("Digite um tempo em segundos:");
    scanf("%d", &segundos);

    transformaHoras(segundos);
    return 0;
}

void transformaHoras(int seg)
{
    int horas = seg / 3600;
    int min = (seg % 3600) / 60;
    int segs = ((seg % 3600) % 60);

    printf("\n%d segundos = %d horas, %d minutos e %d segundos\n", seg, horas, min, segs);
}


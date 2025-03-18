#include <stdio.h>
#include <string.h>
#define alunos 3
#define provas 2
int main() {
    int i,j;
    float notas[alunos][provas],media[alunos] = {0};
    char nomes[alunos][40];

    for (i = 0; i < alunos; i++) {
        printf("\nDigite o nome do %d aluno:",i+1);
        fgets(nomes[i],sizeof(nomes[i]),stdin);
        nomes[i][strcspn(nomes[i],"\n")] = '\0';
        for (j = 0; j < provas; j++) {
            do {
                printf("Digite a %d nota do aluno %s:",j+1,nomes[i]);
                scanf("%f",&notas[i][j]);
            } while (notas[i][j] < 0 || notas[i][j] > 10);
            media[i] += notas[i][j];
        }
        media[i] /= provas;
        while (getchar() != '\n');
    }

    for (i = 0; i < alunos; i++) {
        printf("\nO %d aluno %s, teve uma media de %.2f e está ",i+1,nomes[i],media[i]);
        if (media[i] >= 7) {
            printf("Aprovado\n");
        } else if (media[i] >= 3) {
            printf("Exame final\n");
        } else {
            printf("Reprovado\n");
        }
    }
    return 0;
}
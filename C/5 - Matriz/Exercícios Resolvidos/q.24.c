#include <stdio.h>

#define turmas 3
#define alunos 8
#define provas 4
int main() {
    int i,j,k;
    float notas[turmas][alunos][provas],media_aluno[turmas][alunos] = {0},media_turma[turmas] = {0};

    for (i = 0; i < turmas; i++) {
            printf("\n%d turma:\n",i+1);
        for (j = 0; j < alunos; j++) {
            printf("\nAluno %d:\n",j+1);
            for (k = 0; k < provas; k++) {
                printf("Digite a %d nota:",k+1);
                scanf("%f",&notas[i][j][k]);
                media_aluno[i][j] += notas[i][j][k];
            }
            media_aluno[i][j] /= provas;
            media_turma[i] += media_aluno[i][j];
        }
        media_turma[i] /= alunos;
    }
    printf("\nMedias dos Alunos e das Turmas:\n");
    for (i = 0; i < turmas; i++) {
        printf("\nTurma %d:\n",i+1);
        for (j = 0; j < alunos; j++) {
            printf("Media do %d aluno: %.1f\n",j+1,media_aluno[i][j]);
        }
        printf("\nMedia da %d turma: %.1f\n",i+1,media_turma[i]);
    }
    return 0;
}
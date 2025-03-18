#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define MAP_SIZE 2
#define WALL 178

typedef struct {
    int coordL, coordC;
    char personagem;
} Personagem;

typedef struct {
    int left, right, up, down;
    char walls[3][3];
} Casa;

void initPersonagem(Personagem *p);
void initMapa(Casa mapa[MAP_SIZE][MAP_SIZE], Personagem p);
void exibirMapa(Casa mapa[MAP_SIZE][MAP_SIZE], int atual, bool completo);
void formarCasa(Casa *casa);
bool verificarSaida(Casa mapa[MAP_SIZE][MAP_SIZE]);

int main() {
    Casa mapa[MAP_SIZE][MAP_SIZE];
    Personagem person;
    initPersonagem(&person);
    initMapa(mapa, person);

    for (int i = 0; i < MAP_SIZE; i++) {
        for (int j = 0; j < MAP_SIZE; j++) {
            exibirMapa(mapa, i, false);
            printf("Casa %d da linha %d:\n", j + 1, i + 1);

            printf("Parede esquerda? (1 para sim, 0 para nao): ");
            scanf("%d", &mapa[i][j].left);

            printf("Parede direita? (1 para sim, 0 para nao): ");
            scanf("%d", &mapa[i][j].right);

            printf("Parede cima? (1 para sim, 0 para nao): ");
            scanf("%d", &mapa[i][j].up);

            printf("Parede baixo? (1 para sim, 0 para nao): ");
            scanf("%d", &mapa[i][j].down);

            formarCasa(&mapa[i][j]);
        }
    }

    // if (!verificarSaida(mapa)) {
    //     printf("\nLabirinto nao possui saida!\n");
    //     exit(1);
    // }

    // bool saiu = false;
    char direction;
    int casaL = 0, casaC = 0;

    do {
        exibirMapa(mapa, 0, 1);
        printf("Para qual lado deseja andar:\nW - Cima\nA - Esquerda\nS - Baixo\nD - Direita\n");
        scanf(" %c", &direction);  // Lê a entrada do usuário
        char direc = tolower(direction);

        switch (direc) {
            case 'w':
                if (person.coordL == 0 && casaL == 0) {
                    printf("Parede acima! Você não pode sair do mapa!\n");
                } else if (mapa[casaL][casaC].up) {
                    printf("Parede acima!\n");
                } else {
                    mapa[casaL][casaC].walls[person.coordL][person.coordC] = ' ';
                    person.coordL--;

                    if (person.coordL < 0) {
                        if (casaL > 0) {
                            casaL--;
                            person.coordL = 2;
                        } else {
                            person.coordL = 0;
                        }
                    }
                    mapa[casaL][casaC].walls[person.coordL][person.coordC] = '*';
                }
                break;

            case 'a':
                if (person.coordC == 0 && casaC == 0) {
                    printf("Parede à esquerda! Você não pode sair do mapa!\n");
                } else if (mapa[casaL][casaC].left) {
                    printf("Parede à esquerda!\n");
                } else {
                    mapa[casaL][casaC].walls[person.coordL][person.coordC] = ' ';
                    person.coordC--;

                    if (person.coordC < 0) {
                        if (casaC > 0) {
                            casaC--;
                            person.coordC = 2;
                        } else {
                            person.coordC = 0;
                        }
                    }
                    mapa[casaL][casaC].walls[person.coordL][person.coordC] = '*';
                }
                break;

            case 's':
                if (person.coordL == 2 && casaL == MAP_SIZE - 1) {
                    printf("Parede abaixo! Você não pode sair do mapa!\n");
                } else if (mapa[casaL][casaC].down) {
                    printf("Parede abaixo!\n");
                } else {
                    mapa[casaL][casaC].walls[person.coordL][person.coordC] = ' ';
                    person.coordL++;

                    if (person.coordL > 2) {
                        if (casaL < MAP_SIZE - 1) {
                            casaL++;
                            person.coordL = 0;
                        } else {
                            person.coordL = 2;
                        }
                    }
                    mapa[casaL][casaC].walls[person.coordL][person.coordC] = '*';
                }
                break;

            case 'd':
                if (person.coordC == 2 && casaC == MAP_SIZE - 1) {
                    printf("Parede à direita! Você não pode sair do mapa!\n");
                } else if (mapa[casaL][casaC].right) {
                    printf("Parede à direita!\n");
                } else {
                    mapa[casaL][casaC].walls[person.coordL][person.coordC] = ' ';
                    person.coordC++;

                    if (person.coordC > 2) {
                        if (casaC < MAP_SIZE - 1) {
                            casaC++;
                            person.coordC = 0;
                        } else {
                            person.coordC = 2;
                        }
                    }
                    mapa[casaL][casaC].walls[person.coordL][person.coordC] = '*';
                }
                break;

            default:
                printf("Direção inválida!\n");
                break;
        }

        // Verifica se o jogador alcançou a saída
        if ((casaL == 0 && person.coordL == 0) ||
            (casaL == MAP_SIZE - 1 && person.coordL == 2) ||
            (casaC == 0 && person.coordC == 0) ||
            (casaC == MAP_SIZE - 1 && person.coordC == 2)) {
            exibirMapa(mapa, 0, 1);
            printf("Parabéns, você encontrou a saída!\n");
            break;
        }

    } while (1);
    
    return 0;
}

void initPersonagem(Personagem *p) {
    p->coordL = 1;
    p->coordC = 1;
    p->personagem = '*';
}

void initMapa(Casa mapa[MAP_SIZE][MAP_SIZE], Personagem p) {
    for (int i = 0; i < MAP_SIZE; i++) {
        for (int j = 0; j < MAP_SIZE; j++) {
            mapa[i][j].left = 0;
            mapa[i][j].right = 0;
            mapa[i][j].up = 0;
            mapa[i][j].down = 0;

            // inicia todas as paredes com espaco
            for (int k = 0; k < 3; k++) {
                for (int l = 0; l < 3; l++) {
                    mapa[i][j].walls[k][l] = ' ';
                }
            }
        }
    }

    mapa[0][0].walls[1][1] = p.personagem;
}

void exibirMapa(Casa mapa[MAP_SIZE][MAP_SIZE], int atual, bool completo) {
    int exibicao;
    if (!completo) {
        exibicao = atual + 1;
    } else {
        exibicao = MAP_SIZE;
    }

    printf("\nMapa:\n");
    for (int i = 0; i < exibicao; i++) {
        // Exibe todas as parades da primeira linha
        for (int j = 0; j < MAP_SIZE; j++) {
            for (int k = 0; k < 3; k++) {
                printf("%c", mapa[i][j].walls[0][k]);
            }
        }
        printf("\n");
        // Exibe todas as parades da segunda linha
        for (int j = 0; j < MAP_SIZE; j++) {
            for (int k = 0; k < 3; k++) {
                printf("%c", mapa[i][j].walls[1][k]);
            }
        }
        printf("\n");
        // Exibe todas as parades da terceira linha
        for (int j = 0; j < MAP_SIZE; j++) {
            for (int k = 0; k < 3; k++) {
                printf("%c", mapa[i][j].walls[2][k]);
            }
        }
        printf("\n");
    }
}  

void formarCasa(Casa *casa) {
    // Parede da esquerda
    if (casa->left) {
        for (int i = 0; i < 3; i++) {
            casa->walls[i][0] = WALL;
        }
    } 

    // Parede da direita
    if (casa->right) {
        for (int i = 0; i < 3; i++) {    
            casa->walls[i][2] = WALL;
        }
    }

    // Parede de cima
    if (casa->up) {
        for (int i = 0; i < 3; i++) {    
            casa->walls[0][i] = WALL;
        }
    }

    // Parede de baixo
    if (casa->down) {
        for (int i = 0; i < 3; i++) {    
            casa->walls[2][i] = WALL;
        }
    }

    // Parede central
    if (casa->left && casa->right && casa->up && casa->down) {
        casa->walls[1][1] = WALL;
    }
}

bool verificarSaida(Casa mapa[MAP_SIZE][MAP_SIZE]) {
    // Verifica se tem uma saida na esquerda
    for (int i = 0; i < MAP_SIZE; i++) {
        for (int j = 0; j < 0; j++) {
            for (int k = 0; k < 3; k++) {
                if (mapa[i][j].walls[k][0] == ' ') return true;
            }
        }
    }

    // Verifica se tem uma saida em cima
    for (int i = 0; i < 1; i++) {
        for (int j = 0; j < MAP_SIZE; j++) {
            for (int k = 0; k < 3; k++) {
                if (mapa[i][j].walls[0][k] == ' ') return true;
            }
        }
    }

    // Verifica se tem uma saida na direita
    for (int i = 0; i < MAP_SIZE; i++) {
        for (int j = 2; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                if (mapa[i][j].walls[k][2] == ' ') return true;
            }
        }
    }

    // Verifica se tem uma saida em baixo
    for (int i = 2; i < 3; i++) {
        for (int j = 0; j < MAP_SIZE; j++) {
            for (int k = 0; k < 3; k++) {
                if (mapa[i][j].walls[2][k] == ' ') return true;
            }
        }
    }

    return false;
}
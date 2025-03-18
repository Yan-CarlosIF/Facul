#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Escreva um programa em C para tratamento de dados, conforme descrito a seguir. O usuário deverá digitar um texto de tamanho desconhecido.
// Você deve ler o texto até que o usuario digite a sequência "FIM". reserve memória dinamicamente conforme o usuário digitar teclas de espaço.
// Após o usuário indicar o fim da digitação apresente as informações: quantas letras(excluindo os espacos) foram digitadas, 
// quantas palavras com quatro letras ou mais foram digitadas e qual a maior palavra digitada. 

void palavraMaior(char *texto, char *maiorPalavra, const int tamanho);

int main() {
    char *texto = NULL, palavras[1000], maiorPalavra[100];
    int tamanhoTexto = 0, i = 1;

    while (1) {
        printf("Digite um texto: ");
        scanf("%[^\n]", palavras);
        getchar();

        int tamanhoPalavra = strlen(palavras);
        tamanhoTexto += tamanhoPalavra;

        if (i == 1) {
            texto = (char *)malloc((tamanhoTexto + 2) * sizeof(char));
            strcpy(texto, palavras);
        } else {
            texto = (char *)realloc(texto, (1 + i + tamanhoTexto) * sizeof(char));
            strcat(texto, " ");
            strcat(texto, palavras);
        }

        if (strcasecmp(&palavras[tamanhoPalavra - 3], "FIM") == 0) {
            break;
        }
        
        i++;    
    }

    palavraMaior(texto, maiorPalavra, tamanhoTexto);
    printf("Texto: %s\n\n", texto);
    printf("Maior palavra: %s\n\n", maiorPalavra);

    int qtdLetras = 0, qtdPalavrasMais4 = 0;
    // Contagem de letras
    for (int i = 0; i < tamanhoTexto; i++) {
        if (isalpha(texto[i])) {
            qtdLetras++;
        }
    }

    printf("Quantidade de letras: %d\n\n", qtdLetras);

    // Contagem de palavras com mais de 4 letras
    int cont = 0;
    for (int i = 0; i < tamanhoTexto; i++) {
        if (isalpha(texto[i])) {
            cont++;
        } else if (cont > 0) {
            if (cont >= 4) {
                qtdPalavrasMais4++;
            }
            cont = 0;
        }

        if (cont >= 4) {
            qtdPalavrasMais4++;
        }
    }

    printf("Quantidade de palavras com mais de 4 letras: %d\n\n", qtdPalavrasMais4);

    free(texto);
    return 0;
}

void palavraMaior(char *texto, char *maiorPalavra, const int tamanho) {
    char palavraAtual[100] = "";
    int tamanhoAtual = 0, maiorTamanho = 0;

    for (int i = 0; i < tamanho; i++) {
        if (isalpha(texto[i])) {
            palavraAtual[tamanhoAtual++] = texto[i];
        } else {
            palavraAtual[tamanhoAtual] = '\0';
            if (tamanhoAtual > maiorTamanho) {
                maiorTamanho = tamanhoAtual;
                strcpy(maiorPalavra, palavraAtual);
            }
            tamanhoAtual = 0;
            palavraAtual[0] = '\0';
        }
    }

    if (tamanhoAtual > maiorTamanho) {
        palavraAtual[tamanhoAtual] = '\0';   
        strcpy(maiorPalavra, palavraAtual);        
    }
}
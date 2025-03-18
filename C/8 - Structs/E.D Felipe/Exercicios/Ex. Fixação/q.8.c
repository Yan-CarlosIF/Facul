#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Crie uma estrutura que represente um "Livro", contendo os campos titulo e autor (do tipo char*). Depois, 
// declare um ponteiro para essa estrutura, aloque dinamicamente memória para a estrutura 
// e preencha os campos com informações fornecidas pelo usuário. Imprima as informações usando o ponteiro.

typedef struct {
    char *titulo;
    char *autor;
} Livro;

int main() {
    Livro *livro = (Livro*)malloc(sizeof(Livro));

    livro->autor = (char*)malloc(sizeof(char) * 50);
    livro->titulo = (char*)malloc(sizeof(char) * 50);

    printf("Digite o nome do autor do livro: ");
    fgets(livro->autor, 50, stdin);
    livro->autor[strcspn(livro->autor, "\n")] = '\0';

    printf("Digite o titulo do livro: ");
    fgets(livro->titulo, 50, stdin);
    livro->titulo[strcspn(livro->titulo, "\n")] = '\0';

    printf("\nLivro\nAutor: %s\nTitulo: %s\n", livro->autor, livro->titulo);
    
    free(livro->autor);
    free(livro->titulo);
    free(livro);
    return 0;
}
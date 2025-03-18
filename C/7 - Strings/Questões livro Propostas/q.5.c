/*
Faça um programa que receba duas cadeias de caracteres e verifique se a primeira cadeia digitada é permutação da segunda cadeia,
ou seja, se todos os caracteres da primeira cadeia estão presentes na segunda cadeia, mesmo que em posições diferentes.
Exemplo:
“abccde” é uma permutação de “cbadce”, mas não é de “abcdef” nem de “abcde”
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

bool isPermutation(char *frase1, char *frase2);

int main()
{
    char frase1[100] = "abccde", frase2[100] = "cbadce";

    printf("\n%s\n", isPermutation(frase1, frase2) ? "true" : "false");
    return 0;
}

bool isPermutation(char *frase1, char *frase2)
{
    // Se as strings não tiverem o mesmo comprimento, não podem ser permutações
    if (strlen(frase1) != strlen(frase2))
    {
        return false;
    }

    // Vetores para contar as ocorrências de cada caractere
    int count1[256] = {0}; // ASCII tem 256 possíveis caracteres
    int count2[256] = {0};

    // Contar a ocorrência de cada caractere em frase1
    for (int i = 0; frase1[i] != '\0'; i++)
    {
        count1[(unsigned char)frase1[i]]++;
    }

    // Contar a ocorrência de cada caractere em frase2
    for (int i = 0; frase2[i] != '\0'; i++)
    {
        count2[(unsigned char)frase2[i]]++;
    }

    // Comparar as contagens de caracteres
    for (int i = 0; i < 256; i++)
    {
        if (count1[i] != count2[i])
        {
            return false;
        }
    }

    return true;
}

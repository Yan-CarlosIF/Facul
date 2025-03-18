/* Faça um programa que receba uma frase e mostre as letras que se repetem, junto com o número de
repetições.
Exemplo: A PROVA FOI ADIADA

■ A letra A apareceu 5 vezes.
■ A letra O apareceu 2 vezes.
■ A letra I apareceu 2 vezes.
■ A letra D apareceu 2 vezes. */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

int main()
{
    char frase[50];

    printf("Digite uma frase:");
    gets(frase);

    for (int i = 0; i < strlen(frase); i++)
    {
        int cont = 0;
        if (tolower(frase[i]) >= 'a' && tolower(frase[i]) <= 'z')
        {
            bool testada = false;
            for (int j = 0; j < i; j++)
            {
                if (tolower(frase[i]) == tolower(frase[j]))
                {
                    testada = true;
                }
            }

            if (!testada)
            {
                for (int j = 0; j < strlen(frase); j++)
                {
                    if (tolower(frase[i]) == tolower(frase[j]))
                    {
                        cont++;
                    }
                }
            }
        }

        if (cont > 1)
        {
            printf("A letra '%c' apareceu %d vez(s)\n", frase[i], cont);
        }
    }
}

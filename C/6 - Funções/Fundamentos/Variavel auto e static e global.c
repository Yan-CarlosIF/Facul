#include <stdio.h>

int gVariavelGlobal = 2;

int main()
{
	printf("Global = %d\n", gVariavelGlobal);
    teste();
    teste();
    teste();

    return 0;
}

void teste()
{
    // Variaveis criadas no escopo da função
    int variavelLocalAutomatica = 2; // recria ela cada vez que a função é chamada
    variavelLocalAutomatica *= 2; 

    static int variavelLocalEstatica = 2; // variavel estatica se mantem ao longo da função
    variavelLocalEstatica *= 2; 

    gVariavelGlobal *= 2;
    
    printf("Local Auto = %d\n", variavelLocalAutomatica);
    printf("Local Static = %d\n", variavelLocalEstatica);
    printf("Global = %d\n", gVariavelGlobal);
}

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "../../E.D/Pilhas/PilhaInteiros - Yan/pilha.c"

bool isBalanced(char *str, Pilha *stack);

int main() {
    Pilha *pilha = inicializarPilha();
    char str[] = "(a+b*(2-c)-2+a)*2";
    char str2[] = "[(])";

    if (isBalanced(str, pilha)) {
        printf("Balanceado\n");
    } else {
        printf("Nao balanceado\n");
    }

    if (isBalanced(str2, pilha)) {
        printf("Balanceado\n");
    } else {
        printf("Nao balanceado\n");
    }

    return 0;
}

bool isBalanced(char *str, Pilha *stack) {
    int size = strlen(str);
    
    for (int i = 0; i < size; i++) {
        if (str[i] == '(' || str[i] == '{' || str[i] == '[') {
            push(stack, str[i]);
        } else if (str[i] == ')' || str[i] == '}' || str[i] == ']') {
            if (stack->tamanho == 0) {
                return false;
            }

            char topo = pop(stack);

            if ((str[i] == ')' && topo != '(') || 
                (str[i] == '}' && topo != '{') ||
                (str[i] == ']' && topo != '['))
                return false;
        }
    }
    return stack->tamanho == 0;
}
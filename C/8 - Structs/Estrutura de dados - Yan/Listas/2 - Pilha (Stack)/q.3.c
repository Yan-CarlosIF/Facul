#include <stdio.h>
#include <stdlib.h>
#include "yanStack.h"
#include "yanStack.c"

int main() {
    Stack *stackDoYan = createStack();

    push(stackDoYan, 1);
    push(stackDoYan, 2);
    push(stackDoYan, 3);

    printf("Last item: %d\n", peek(stackDoYan));
    printf("Tamanho: %d\n", size(stackDoYan));
    return 0;
}
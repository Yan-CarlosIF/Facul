#include <stdlib.h>
#include <stdio.h>

int main(){
    float f,c;
    for (f=40;f<=70;f++){
        c=(5/(float)9)*(f-32);
        printf("F = %.1f - C = %.1f\n",f,c);
    }
    return 0;
}
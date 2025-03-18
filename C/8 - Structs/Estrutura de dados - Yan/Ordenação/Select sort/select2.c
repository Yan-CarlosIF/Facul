#include <stdio.h>

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int tam = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < tam; i++) {
        int maior = i;
        for (int j = i + 1; j < tam; j++) {
            if (arr[maior] < arr[j]) {
                maior = j;
            }
        }

        int aux = arr[i];
        arr[i] = arr[maior];
        arr[maior] = aux;
        printf("%d ", arr[i]);
    }
    
    return 0;
}
#include <stdio.h>

int main() {
    int arr[] = {3, 5, 2, 4, 6, 8, 7, 1};
    int tam = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < tam; i++) {
        for (int j = i + 1; j < tam; j++) {
            if (arr[i] > arr[j]) {
                int aux = arr[i];
                arr[i] = arr[j];
                arr[j] = aux;
            }
        }
        printf("%d ", arr[i]);
    }
    
    return 0;
}
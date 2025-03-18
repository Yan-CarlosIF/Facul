#include <stdio.h>

int main() {
    int arr[] = {3, 5, 2, 4, 6, 8, 7, 1};
    int tam = sizeof(arr) / sizeof(arr[0]);

    for (int i = 1; i < tam; i++) {
        int aux = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > aux) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = aux;
    }

    for (int i = 0; i < tam; i++) {
        printf("%d ", arr[i]);
    }
    
    return 0;
}
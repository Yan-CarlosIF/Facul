#include <stdio.h>

int main() {
    int arr[] = {4, 1, 5, 2, 3, 6, 8};
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
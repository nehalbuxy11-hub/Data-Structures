#include <stdio.h>

void selectionSort(int arr[], int n) {
    int i, j, temp;

    for(i = 0; i < n - 1; i++) {
        int largest = i;   // assume current is largest

        for(j = i + 1; j < n; j++) {
            if(arr[j] > arr[largest]) {
                largest = j;
            }
        }

        // swap
        temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[100];

    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    selectionSort(arr, n);

    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");
    return 0;
}


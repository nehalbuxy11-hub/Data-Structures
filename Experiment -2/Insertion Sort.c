#include <stdio.h>

void insertionSort(int arr[], int n) {
    int i, key, j;

    for(i = 1; i < n; i++) {
        key = arr[i];   // element to insert
        j = i - 1;

        while(j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];  // shift right
            j--;
        }

        arr[j + 1] = key;   // place element
    }
}

int main() {
    int n;

    scanf("%d", &n);

    int arr[100];

    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    insertionSort(arr, n);

    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");

    return 0;
}

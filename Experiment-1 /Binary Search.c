#include <stdio.h>

int main() {
    int n, i, key, mid, start, end;

    scanf("%d", &n);

    int arr[100];

    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    scanf("%d", &key);

    start = 0;
    end = n - 1;

    while(start <= end) {
        mid = start + (end - start) / 2;

        if(key == arr[mid]) {
            printf("Element found at index %d\n", mid);
            return 0;
        }

        if(key > arr[mid]) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    printf("Element not found\n");

    return 0;
}

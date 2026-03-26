#include <stdio.h>

int main() {
    int n, key, i = 0;

    scanf("%d", &n);

    int arr[100];

    while(i < n) {
        scanf("%d", &arr[i]);
        i++;
    }

    scanf("%d", &key);

    i = 0;
    while(i < n) {
        if(arr[i] == key) {
            printf("found at position %d\n", i);
            return 0;
        }
        i++;
    }

    printf("%d not found\n", key);

    return 0;
}


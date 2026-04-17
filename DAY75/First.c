#include <stdio.h>
#include <stdlib.h>

int maxLen(int arr[], int n) {
    int sum = 0, maxlen = 0;

    int map[100000];
    for (int i = 0; i < 100000; i++) map[i] = -2;

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        if (sum == 0)
            maxlen = i + 1;

        int index = sum + 50000;

        if (map[index] == -2)
            map[index] = i;
        else {
            int len = i - map[index];
            if (len > maxlen)
                maxlen = len;
        }
    }

    return maxlen;
}

int main() {
    int n;
    scanf("%d", &n);

    int *arr = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("%d", maxLen(arr, n));

    free(arr);
    return 0;
}
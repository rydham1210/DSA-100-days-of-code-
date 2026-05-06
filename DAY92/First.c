#include <stdio.h>

int lomuto_partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            int tmp = arr[i]; arr[i] = arr[j]; arr[j] = tmp;
        }
    }
    int tmp = arr[i+1]; arr[i+1] = arr[high]; arr[high] = tmp;
    return i + 1;
}

void quick_sort_lomuto(int arr[], int low, int high) {
    if (low < high) {
        int pi = lomuto_partition(arr, low, high);
        quick_sort_lomuto(arr, low, pi - 1);
        quick_sort_lomuto(arr, pi + 1, high);
    }
}

void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original: "); print_array(arr, n);
    quick_sort_lomuto(arr, 0, n - 1);
    printf("Sorted:   "); print_array(arr, n);

    return 0;
}
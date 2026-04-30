#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int can_place(int *stalls, int n, int k, int min_dist) {
    int count = 1;
    int last_pos = stalls[0];

    for (int i = 1; i < n; i++) {
        if (stalls[i] - last_pos >= min_dist) {
            count++;
            last_pos = stalls[i];
            if (count == k) return 1;
        }
    }
    return count >= k;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int stalls[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &stalls[i]);

    qsort(stalls, n, sizeof(int), compare);

    int lo = 1, hi = stalls[n-1] - stalls[0];
    int answer = 0;

    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (can_place(stalls, n, k, mid)) {
            answer = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    printf("%d\n", answer);
    return 0;
}
#include <stdio.h>

int can_finish(int *boards, int n, int k, long long max_time) {
    int painters = 1;
    long long current = 0;
    for (int i = 0; i < n; i++) {
        if (boards[i] > max_time) return 0;
        if (current + boards[i] > max_time) {
            painters++;
            current = boards[i];
        } else {
            current += boards[i];
        }
    }
    return painters <= k;
}

long long min_time(int *boards, int n, int k) {
    long long lo = 0, hi = 0;
    for (int i = 0; i < n; i++) {
        if (boards[i] > lo) lo = boards[i];
        hi += boards[i];
    }
    while (lo < hi) {
        long long mid = (lo + hi) / 2;
        if (can_finish(boards, n, k, mid)) hi = mid;
        else lo = mid + 1;
    }
    return lo;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int boards[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &boards[i]);
    printf("%lld\n", min_time(boards, n, k));
    return 0;
}
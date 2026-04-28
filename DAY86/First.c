#include <stdio.h>

int intSqrt(int n) {
    if (n == 0) return 0;

    long long left = 1, right = n, ans = 1;

    while (left <= right) {
        long long mid = left + (right - left) / 2;

        if (mid * mid == n)
            return mid;
        else if (mid * mid < n) {
            ans = mid;        // store best answer so far
            left = mid + 1;   // try bigger
        } else {
            right = mid - 1;  // try smaller
        }
    }

    return ans;
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%d\n", intSqrt(n));
    return 0;
}
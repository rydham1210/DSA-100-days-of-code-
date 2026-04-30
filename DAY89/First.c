#include <stdio.h>
#include <stdlib.h>

// Check if we can allocate books to 'm' students with max 'limit' pages each
int can_allocate(int *pages, int n, int m, int limit) {
    int students = 1;   // start with 1 student
    int current = 0;    // pages assigned to current student

    for (int i = 0; i < n; i++) {
        if (pages[i] > limit)
            return 0;   // single book exceeds limit, impossible

        if (current + pages[i] > limit) {
            students++;         // give this book to next student
            current = pages[i];
            if (students > m)
                return 0;       // need more students than available
        } else {
            current += pages[i];
        }
    }
    return 1;
}

int allocateBooks(int *pages, int n, int m) {
    int lo = 0, hi = 0, answer = -1;

    for (int i = 0; i < n; i++) {
        if (pages[i] > lo) lo = pages[i];  // lo = max single book
        hi += pages[i];                     // hi = sum of all books
    }

    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (can_allocate(pages, n, m, mid)) {
            answer = mid;   // mid works, try smaller
            hi = mid - 1;
        } else {
            lo = mid + 1;   // mid too small, try larger
        }
    }
    return answer;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int pages[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("%d\n", allocateBooks(pages, n, m));
    return 0;
}
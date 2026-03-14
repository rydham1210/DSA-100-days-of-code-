#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int x) {
    stack[++top] = x;
}

int pop() {
    return stack[top--];
}

int main() {
    int n;
    int queue[MAX];

    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%d", &queue[i]);
    }

    for(int i = 0; i < n; i++) {
        push(queue[i]);
    }

    for(int i = 0; i < n; i++) {
        queue[i] = pop();
    }

    for(int i = 0; i < n; i++) {
        printf("%d ", queue[i]);
    }

    return 0;
}
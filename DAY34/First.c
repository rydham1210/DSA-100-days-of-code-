#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

void push(int x) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = top;
    top = newNode;
}

int pop() {
    if (top == NULL)
        return -1;
    struct Node* temp = top;
    int val = temp->data;
    top = top->next;
    free(temp);
    return val;
}

int evaluate(char *exp) {
    int i = 0;

    while (exp[i] != '\0') {

        if (exp[i] == ' ') {
            i++;
            continue;
        }

        if (isdigit(exp[i])) {
            int num = 0;
            while (isdigit(exp[i])) {
                num = num * 10 + (exp[i] - '0');
                i++;
            }
            push(num);
        }
        else {
            int val2 = pop();
            int val1 = pop();

            switch (exp[i]) {
                case '+': push(val1 + val2); break;
                case '-': push(val1 - val2); break;
                case '*': push(val1 * val2); break;
                case '/': push(val1 / val2); break;
            }
            i++;
        }
    }
    return pop();
}

int main() {
    char exp[100];

    fgets(exp, sizeof(exp), stdin);

    int result = evaluate(exp);
    printf("%d", result);

    return 0;
}
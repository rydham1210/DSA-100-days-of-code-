#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void createCircularList(struct Node** head, int n) {
    int value;
    struct Node *temp, *last = NULL;

    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        struct Node* newNode = createNode(value);

        if (*head == NULL) {
            *head = newNode;
            last = newNode;
        } else {
            last->next = newNode;
            last = newNode;
        }
    }

    if (last != NULL)
        last->next = *head;
}

void traverseCircularList(struct Node* head) {
    if (head == NULL)
        return;

    struct Node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
}

int main() {
    int n;
    struct Node* head = NULL;

    scanf("%d", &n);
    createCircularList(&head, n);
    traverseCircularList(head);

    return 0;
}
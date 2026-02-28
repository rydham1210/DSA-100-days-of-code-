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

void append(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

struct Node* findIntersection(struct Node* head1, struct Node* head2) {
    while (head1 != NULL) {
        struct Node* temp = head2;
        while (temp != NULL) {
            if (head1->data == temp->data)
                return head1;
            temp = temp->next;
        }
        head1 = head1->next;
    }
    return NULL;
}

int main() {
    int n, m, value;
    struct Node *head1 = NULL, *head2 = NULL;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        append(&head1, value);
    }

    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &value);
        append(&head2, value);
    }

    struct Node* intersection = findIntersection(head1, head2);

    if (intersection != NULL)
        printf("%d\n", intersection->data);
    else
        printf("No Intersection\n");

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

#define SIZE 100003

typedef struct Node {
    long long key;
    long long count;
    struct Node* next;
} Node;

Node* hashTable[SIZE];

int hash(long long key) {
    return (key % SIZE + SIZE) % SIZE;
}

long long get(long long key) {
    int idx = hash(key);
    Node* temp = hashTable[idx];
    while (temp) {
        if (temp->key == key)
            return temp->count;
        temp = temp->next;
    }
    return 0;
}

void insert(long long key) {
    int idx = hash(key);
    Node* temp = hashTable[idx];

    while (temp) {
        if (temp->key == key) {
            temp->count++;
            return;
        }
        temp = temp->next;
    }

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->count = 1;
    newNode->next = hashTable[idx];
    hashTable[idx] = newNode;
}

int main() {
    int n;
    scanf("%d", &n);

    long long prefix_sum = 0;
    long long count = 0;

    insert(0);

    for (int i = 0; i < n; i++) {
        long long num;
        scanf("%lld", &num);

        prefix_sum += num;
        count += get(prefix_sum);
        insert(prefix_sum);
    }

    printf("%lld\n", count);
    return 0;
}
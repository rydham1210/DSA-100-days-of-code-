#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* createNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

struct TreeNode* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct TreeNode** queue = (struct TreeNode**)malloc(n * sizeof(struct TreeNode*));
    int front = 0, rear = 0;

    struct TreeNode* root = createNode(arr[0]);
    queue[rear++] = root;

    int i = 1;
    while (i < n) {
        struct TreeNode* curr = queue[front++];

        if (arr[i] != -1) {
            curr->left = createNode(arr[i]);
            queue[rear++] = curr->left;
        }
        i++;

        if (i < n && arr[i] != -1) {
            curr->right = createNode(arr[i]);
            queue[rear++] = curr->right;
        }
        i++;
    }

    return root;
}

void zigzagTraversal(struct TreeNode* root) {
    if (!root) return;

    struct TreeNode** queue = (struct TreeNode**)malloc(1000 * sizeof(struct TreeNode*));
    int front = 0, rear = 0;

    queue[rear++] = root;
    int leftToRight = 1;

    while (front < rear) {
        int size = rear - front;
        int* level = (int*)malloc(size * sizeof(int));

        for (int i = 0; i < size; i++) {
            struct TreeNode* curr = queue[front++];

            int index = leftToRight ? i : (size - 1 - i);
            level[index] = curr->val;

            if (curr->left) queue[rear++] = curr->left;
            if (curr->right) queue[rear++] = curr->right;
        }

        for (int i = 0; i < size; i++) {
            printf("%d ", level[i]);
        }

        leftToRight = !leftToRight;
        free(level);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct TreeNode* root = buildTree(arr, n);
    zigzagTraversal(root);

    return 0;
}
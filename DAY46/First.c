#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* createNode(int val) {
    if (val == -1) return NULL;
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct TreeNode* buildTree() {
    int val;
    scanf("%d", &val);

    if (val == -1) return NULL;

    struct TreeNode* root = createNode(val);

    root->left = buildTree();
    root->right = buildTree();

    return root;
}

void levelOrder(struct TreeNode* root) {
    if (!root) return;

    struct TreeNode* queue[1000];
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear) {
        int size = rear - front;

        for (int i = 0; i < size; i++) {
            struct TreeNode* temp = queue[front++];
            printf("%d ", temp->val);

            if (temp->left)
                queue[rear++] = temp->left;

            if (temp->right)
                queue[rear++] = temp->right;
        }
        printf("\n");
    }
}

int main() {
    struct TreeNode* root = buildTree();
    levelOrder(root);
    return 0;
}
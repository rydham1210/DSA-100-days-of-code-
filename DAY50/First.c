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

struct TreeNode* insert(struct TreeNode* root, int val) {
    if (root == NULL)
        return createNode(val);

    if (val < root->val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

struct TreeNode* searchBST(struct TreeNode* root, int key) {
    if (root == NULL || root->val == key)
        return root;

    if (key < root->val)
        return searchBST(root->left, key);
    else
        return searchBST(root->right, key);
}

int main() {
    int n, x, key;
    struct TreeNode* root = NULL;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        root = insert(root, x);
    }

    scanf("%d", &key);

    struct TreeNode* res = searchBST(root, key);

    if (res != NULL)
        printf("Found\n");
    else
        printf("Not Found\n");

    return 0;
}
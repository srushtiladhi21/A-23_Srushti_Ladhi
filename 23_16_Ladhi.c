#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int data) {
    struct Node* node = malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

struct Node* insert(struct Node* root, int data) {
    if (!root) return newNode(data);
    if (data < root->data) root->left = insert(root->left, data);
    else if (data > root->data) root->right = insert(root->right, data);
    return root;
}

int findMin(struct Node* root) {
    while (root && root->left) root = root->left;
    return root->data;
}
int findMax(struct Node* root) {
    while (root && root->right) root = root->right;
    return root->data;
}

int main() {
    struct Node* root = NULL;
    root = insert(root, 50);
    insert(root, 30); insert(root, 70);
    insert(root, 20); insert(root, 40);
    insert(root, 60); insert(root, 80);

    printf("Minimum: %d\n", findMin(root));
    printf("Maximum: %d\n", findMax(root));
    return 0;
}

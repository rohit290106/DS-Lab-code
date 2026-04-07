#include <stdio.h>
#include <stdlib.h>

/* Definition of BST Node */
struct node {
    int data;
    struct node *left;
    struct node *right;
};

/* Create a new node */
struct node* createNode(int value) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

/* Insert a node in BST */
struct node* insert(struct node* root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

/* Search an element in BST */
struct node* search(struct node* root, int key) {
    if (root == NULL || root->data == key)
        return root;

    if (key < root->data)
        return search(root->left, key);

    return search(root->right, key);
}

/* Inorder Traversal */
void inorder(struct node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

/* Preorder Traversal */
void preorder(struct node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

/* Postorder Traversal */
void postorder(struct node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

/* Main Function */
int main() {
    struct node* root = NULL;
    int key;

    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    printf("Inorder Traversal: ");
    inorder(root);

    printf("\nPreorder Traversal: ");
    preorder(root);

    printf("\nPostorder Traversal: ");
    postorder(root);

    printf("\n\nEnter element to search: ");
    scanf("%d", &key);

    if (search(root, key) != NULL)
        printf("Element found in BST");
    else
        printf("Element not found in BST");

    return 0;
}

// Inorder Traversal: 20 30 40 50 60 70 80
// Preorder Traversal: 50 30 20 40 70 60 80
// Postorder Traversal: 20 40 30 60 80 70 50

// Enter element to search: 60
// Element found in BST

// Enter element to search: 25
// Element not found in BST

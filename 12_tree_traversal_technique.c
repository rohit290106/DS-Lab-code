#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

// Create Node
struct node* newNode(int data) {
    struct node* n = (struct node*)malloc(sizeof(struct node));
    n->data = data;
    n->left = n->right = NULL;
    return n;
}

// Inorder (Iterative)
void inorder(struct node* root) {
    struct node* stack[50];
    int top = -1;
    struct node* cur = root;

    while (cur || top != -1) {
        while (cur) {
            stack[++top] = cur;
            cur = cur->left;
        }
        cur = stack[top--];
        printf("%d ", cur->data);
        cur = cur->right;
    }
}

// Preorder (Iterative)
void preorder(struct node* root) {
    if (!root) return;

    struct node* stack[50];
    int top = -1;
    stack[++top] = root;

    while (top != -1) {
        struct node* cur = stack[top--];
        printf("%d ", cur->data);

        if (cur->right) stack[++top] = cur->right;
        if (cur->left)  stack[++top] = cur->left;
    }
}

// Postorder (Iterative)
void postorder(struct node* root) {
    if (!root) return;

    struct node* s1[50], *s2[50];
    int t1 = -1, t2 = -1;

    s1[++t1] = root;

    while (t1 != -1) {
        struct node* cur = s1[t1--];
        s2[++t2] = cur;

        if (cur->left)  s1[++t1] = cur->left;
        if (cur->right) s1[++t1] = cur->right;
    }

    while (t2 != -1)
        printf("%d ", s2[t2--]->data);
}

int main() {
    // Sample Tree
    struct node* root = newNode(10);
    root->left = newNode(20);
    root->right = newNode(30);
    root->left->left = newNode(40);
    root->left->right = newNode(50);

    printf("Inorder: ");
    inorder(root);

    printf("\nPreorder: ");
    preorder(root);

    printf("\nPostorder: ");
    postorder(root);

    return 0;
}

// Inorder: 40 20 50 10 30
// Preorder: 10 20 40 50 30
// Postorder: 40 50 20 30 10

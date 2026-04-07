#include <stdio.h>
#include <stdlib.h>

#define MAX 5

/* -------- ARRAY QUEUE -------- */
int aqueue[MAX], frontA = -1, rearA = -1;

void enqueueA(int x) {
    if (rearA == MAX - 1) {
        printf("Array Queue Overflow\n");
        return;
    }
    if (frontA == -1) frontA = 0;
    aqueue[++rearA] = x;
}

void dequeueA() {
    if (frontA == -1 || frontA > rearA) {
        printf("Array Queue Underflow\n");
        return;
    }
    printf("Deleted (Array): %d\n", aqueue[frontA++]);
}

void displayA() {
    for (int i = frontA; i <= rearA; i++)
        printf("%d ", aqueue[i]);
    printf("\n");
}

/* -------- LINKED LIST QUEUE -------- */
struct node {
    int data;
    struct node *next;
};

struct node *frontL = NULL, *rearL = NULL;

void enqueueL(int x) {
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = NULL;

    if (rearL == NULL)
        frontL = rearL = temp;
    else {
        rearL->next = temp;
        rearL = temp;
    }
}

void dequeueL() {
    if (frontL == NULL) {
        printf("Linked Queue Underflow\n");
        return;
    }
    struct node *temp = frontL;
    printf("Deleted (Linked): %d\n", temp->data);
    frontL = frontL->next;
    free(temp);
}

void displayL() {
    struct node *temp = frontL;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

/* -------- MAIN -------- */
int main() {
    /* Array Queue */
    enqueueA(10);
    enqueueA(20);
    enqueueA(30);
    printf("Array Queue: ");
    displayA();
    dequeueA();
    displayA();

    /* Linked List Queue */
    enqueueL(10);
    enqueueL(20);
    enqueueL(30);
    printf("Linked Queue: ");
    displayL();
    dequeueL();
    displayL();

    return 0;
}

// Array Queue: 10 20 30
// Deleted (Array): 10
// 20 30

// Linked Queue: 10 20 30
// Deleted (Linked): 10
// 20 30

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *prev;
    struct node *next;
}node;

node *head = NULL;

/* Insert at beginning */
void insert_begin() {
    node *newnode;
    int value;

    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter value: ");
    scanf("%d", &value);

    newnode->data = value;
    newnode->prev = NULL;
    newnode->next = head;

    if (head != NULL)
        head->prev = newnode;

    head = newnode;
}

/* Insert at end */
void insert_end() {
    node *newnode, *temp;
    int value;

    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter value: ");
    scanf("%d", &value);

    newnode->data = value;
    newnode->next = NULL;

    if (head == NULL) {
        newnode->prev = NULL;
        head = newnode;
    } else {
        temp = head;
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newnode;
        newnode->prev = temp;
    }
}

/* Delete from beginning */
void delete_begin() {
    node *temp;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    temp = head;
    head = head->next;

    if (head != NULL)
        head->prev = NULL;

    free(temp);
    printf("Node deleted from beginning\n");
}

/* Delete from end */
void delete_end() {
    node *temp;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    if (temp->prev != NULL)
        temp->prev->next = NULL;
    else
        head = NULL;

    free(temp);
    printf("Node deleted from end\n");
}

/* Display list */
void display() {
     node *temp;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    temp = head;
    printf("Doubly Linked List: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

/* Main function */
int main() {
    int choice;

    while (1) {
        printf("\n--- Doubly Linked List Operations ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Delete from Beginning\n");
        printf("4. Delete from End\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            insert_begin();
            break;
        case 2:
            insert_end();
            break;
        case 3:
            delete_begin();
            break;
        case 4:
            delete_end();
            break;
        case 5:
            display();
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}

// --- Doubly Linked List Operations ---

// 1. Insert at Beginning
// 2. Insert at End
// 3. Delete from Beginning
// 4. Delete from End
// 5. Display
// 6. Exit
//    Enter your choice: 1
//    Enter value: 10

// Enter your choice: 1
// Enter value: 5

// Enter your choice: 2
// Enter value: 20

// Enter your choice: 2
// Enter value: 30

// Enter your choice: 5
// Doubly Linked List: 5 <-> 10 <-> 20 <-> 30 <-> NULL

// Enter your choice: 3
// Node deleted from beginning

// Enter your choice: 5
// Doubly Linked List: 10 <-> 20 <-> 30 <-> NULL

// Enter your choice: 4
// Node deleted from end

// Enter your choice: 5
// Doubly Linked List: 10 <-> 20 <-> NULL

// Enter your choice: 3
// Node deleted from beginning

// Enter your choice: 3
// Node deleted from beginning

// Enter your choice: 5
// Doubly Linked List: 20 <-> NULL

// Enter your choice: 4
// Node deleted from end

// Enter your choice: 5
// List is empty

// Enter your choice: 3
// List is empty

// Enter your choice: 4
// List is empty

// Enter your choice: 6

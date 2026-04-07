#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
}node;

 node *start = NULL;

/* Insert at beginning */
void insert_begin(int value) {
     node *newnode = ( node *)malloc(sizeof( node));
    newnode->data = value;

    if (start == NULL) {
        newnode->next = newnode;
        start = newnode;
    } else {
        newnode->next = start->next;
        start->next = newnode;
    }
}

/* Insert at end */
void insert_end(int value) {
     node *newnode = ( node *)malloc(sizeof( node));
    newnode->data = value;

    if (start == NULL) {
        newnode->next = newnode;
        start = newnode;
    } else {
        newnode->next = start->next;
        start->next = newnode;
        start = newnode;
    }
}

/* Delete from beginning */
void delete_begin() {
    if (start == NULL) {
        printf("List is empty\n");
        return;
    }

     node *temp = start->next;

    if (start->next == start) {
        start = NULL;
    } else {
        start->next = temp->next;
    }
    free(temp);
}

/* Delete from end */
void delete_end() {
    if (start == NULL) {
        printf("List is empty\n");
        return;
    }

     node *temp = start->next;

    if (start->next == start) {
        free(start);
        start = NULL;
        return;
    }

    while (temp->next != start) {
        temp = temp->next;
    }
    temp->next = start->next;
    free(start);
    start = temp;
}

/* Display list */
void display() {
    if (start == NULL) {
        printf("List is empty\n");
        return;
    }

     node *temp = start->next;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != start->next);
    printf("(Back to Head)\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\n--- Circular Linked List Menu ---\n");
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
            insert_begin(5);
            break;
        case 2:
            insert_end(5);
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

// --- Circular Linked List Menu ---

// 1. Insert at Beginning
// 2. Insert at End
// 3. Delete from Beginning
// 4. Delete from End
// 5. Display
// 6. Exit
//    Enter your choice: 1

// Enter your choice: 1

// Enter your choice: 2

// Enter your choice: 2

// Enter your choice: 5
// 5 -> 5 -> 5 -> 5 -> (Back to Head)

// Enter your choice: 3

// Enter your choice: 5
// 5 -> 5 -> 5 -> (Back to Head)

// Enter your choice: 4

// Enter your choice: 5
// 5 -> 5 -> (Back to Head)

// Enter your choice: 3

// Enter your choice: 3

// Enter your choice: 5
// 5 -> (Back to Head)

// Enter your choice: 4

// Enter your choice: 5
// List is empty

// Enter your choice: 3
// List is empty

// Enter your choice: 4
// List is empty

// Enter your choice: 6

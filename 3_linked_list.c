#include <stdio.h>
#include <stdlib.h>

typedef struct linked_list {
    int data;
    struct linked_list *next;
} node;

node *start = NULL;

node *getnode() {
    node *ptr = (node *)malloc(sizeof(node));
    if (ptr == NULL) {
        printf("Memory error\n");
        return NULL;
    }
    printf("Enter data: ");
    scanf("%d", &ptr->data);
    ptr->next = NULL;
    return ptr;
}

void traversal() {
    if (start == NULL) {
        printf("List is EMPTY\n");
        return;
    }
    node *ptr = start;
    printf("List: ");
    while (ptr != NULL) {
        printf("%d", ptr->data);
        ptr = ptr->next;
    }
}

void creation() {
    node *n = getnode();
    if (start == NULL) {
        start = n;
        return;
    }
    node *ptr = start;
    while (ptr->next != NULL)
        ptr = ptr->next;
    ptr->next = n;
    traversal();
}

void insertBegin() {
    node *n = getnode();
    n->next = start;
    start = n;
    printf("Inserted %d at begin\n", n->data);
}

void insertEnd() {
    node *n = getnode();
    if (start == NULL) {
        start = n;
        return;
    }
    node *ptr = start;
    while (ptr->next != NULL)
        ptr = ptr->next;
    ptr->next = n;
    printf("Inserted %d at end\n", n->data);
}

void insertPos() {
    int pos;
    printf("Enter position: ");
    scanf("%d", &pos);
    if (pos == 1) {
        insertBegin();
        return;
    }
    node *n = getnode();
    node *ptr = start;
    for (int i = 1; i < pos - 1 && ptr != NULL; i++)
        ptr = ptr->next;
    if (ptr == NULL) {
        printf("Invalid position!\n");
        return;
    }
    n->next = ptr->next;
    ptr->next = n;
    printf("Inserted %d at pos %d\n", n->data, pos);
}

void deleteBegin() {
    if (start == NULL) {
        printf("List is EMPTY\n");
        return;
    }
    node *ptr = start;
    start = start->next;
    printf("Deleted %d\n", ptr->data);
    free(ptr);
}

void deleteEnd() {
    if (start == NULL) {
        printf("List is EMPTY\n");
        return;
    }
    if (start->next == NULL) {
        printf("Deleted %d\n", start->data);
        free(start);
        start = NULL;
        return;
    }
    node *front = start->next;
    node *back = start;
    while (front->next != NULL) {
        front = front->next;
        back = back->next;
    }
    printf("Deleted %d\n", front->data);
    back->next = NULL;
    free(front);
}

void deletePos() {
    if (start == NULL) {
        printf("List is EMPTY\n");
        return;
    }
    int pos;
    printf("Enter position: ");
    scanf("%d", &pos);
    if (pos == 1) {
        deleteBegin();
        return;
    }
    node *front = start->next;
    node *back = start;
    for (int i = 1; i < pos - 1 && front != NULL; i++) {
        front = front->next;
        back = back->next;
    }
    if (front == NULL) {
        printf("Invalid position!\n");
        return;
    }
    back->next = front->next;
    printf("Deleted %d\n", front->data);
    free(front);
}

int main() {
    int ch, ch2;
    do {
        printf("\n1.Creation 2.Insertion 3.Deletion 4.Traversal 5.Exit\n");
        printf("Choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                creation();
                break;
            case 2:
                printf("1.Begin 2.Position 3.End\nChoice: ");
                scanf("%d", &ch2);
                if (ch2 == 1) insertBegin();
                else if (ch2 == 2) insertPos();
                else if (ch2 == 3) insertEnd();
                traversal();
                break;
            case 3:
                printf("1.Begin 2.Position 3.End\nChoice: ");
                scanf("%d", &ch2);
                if (ch2 == 1) deleteBegin();
                else if (ch2 == 2) deletePos();
                else if (ch2 == 3) deleteEnd();
                traversal();
                break;
            case 4:
                traversal();
                break;
            case 5:
                return 0;
            default:
                printf("Wrong choice!\n");
                break;
        }
    } while (1);
    return 0;
}


// 1.Creation 2.Insertion 3.Deletion 4.Traversal 5.Exit
// Choice: 1
// Enter data: 10
// List: 10

// Choice: 1
// Enter data: 20
// List: 1020

// Choice: 1
// Enter data: 30
// List: 102030

// Choice: 4
// List: 102030

// Choice: 2
// 1.Begin 2.Position 3.End
// Choice: 1
// Enter data: 5
// Inserted 5 at begin
// List: 5102030

// Choice: 2
// 1.Begin 2.Position 3.End
// Choice: 2
// Enter position: 3
// Enter data: 15
// Inserted 15 at pos 3
// List: 510152030

// Choice: 2
// 1.Begin 2.Position 3.End
// Choice: 3
// Enter data: 40
// Inserted 40 at end
// List: 51015203040

// Choice: 3
// 1.Begin 2.Position 3.End
// Choice: 1
// Deleted 5
// List: 1015203040

// Choice: 3
// 1.Begin 2.Position 3.End
// Choice: 2
// Enter position: 3
// Deleted 20
// List: 10153040

// Choice: 3
// 1.Begin 2.Position 3.End
// Choice: 3
// Deleted 40
// List: 101530

// Choice: 2
// 1.Begin 2.Position 3.End
// Choice: 2
// Enter position: 10
// Enter data: 50
// Invalid position!

// Choice: 3
// 1.Begin 2.Position 3.End
// Choice: 1
// Deleted 10
// List: 1530

// Choice: 3
// 1.Begin 2.Position 3.End
// Choice: 1
// Deleted 15
// List: 30

// Choice: 3
// 1.Begin 2.Position 3.End
// Choice: 1
// Deleted 30
// List:

// Choice: 3
// 1.Begin 2.Position 3.End
// Choice: 1
// List is EMPTY

// Choice: 5

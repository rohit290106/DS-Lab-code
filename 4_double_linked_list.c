#include <stdio.h>
#include <stdlib.h>

typedef struct doubly_linked_list
{
    struct doubly_linked_list *prev;
    int data;
    struct doubly_linked_list *next;
} node;

node *start = NULL;
node *last = NULL;

node *getnode()
{
    node *ptr = (node *)malloc(sizeof(node));

    if (ptr == NULL)
    {
        printf("Memory is full ,new node can't be generated.");
        return 0;
    }

    int data;
    printf("Enter the data: \n");
    scanf("%d", &data);

    ptr->prev = NULL;
    ptr->data = data;
    ptr->next = NULL;

    return ptr;
}

void creation()
{
    node *newnode = getnode();
    node *ptr = start;

    if (start == NULL)
    {
        start = last = newnode;
        return;
    }

    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }

    ptr->next = newnode;
    newnode->prev = ptr;
    last = newnode;
}

void forward_traverse()
{
    node *ptr = start;
    int i = 1;

    if (start == NULL)
    {
        printf("List is empty,there is no data present.");
        return;
    }

    while (ptr->next != NULL)
    {
        printf("Element %d:%d \n", i, ptr->data);
        ptr = ptr->next;
        i++;
    }
}

void reverse_traverse()
{
    node *ptr = last;
    int i = 0;

    if (start == NULL)
    {
        printf("List is empty,there is no data present.");
        return;
    }

    while (ptr->prev != NULL)
    {
        printf("Element %d:%d \n", i, ptr->data);
        ptr = ptr->prev;
        i++;
    }
}

int main_menu()
{
    int choose;
    printf("Choose the operation that you want to perform:\n");
    printf("Press 1 for creation.\n");
    printf("Press 2 for insertion.\n");
    printf("Press 3 for deletion.\n");
    printf("Press 4 for forward_traversal.\n");
    printf("Press 5 for reverse_traversal.\n");
    printf("Press 6 for Exit.\n");
    scanf("%d", &choose);
    return choose;
}

int main()
{
    int main_choice;

    do
    {
        main_choice = main_menu();
        switch (main_choice)
        {
        case 1:
            creation();
            printf("\n");
            break;

        case 2:
            forward_traverse();
            printf("\n");
            break;

        case 3:
            reverse_traverse();
            printf("\n");
            break;

        case 4:
            return 0;

        default:
            printf("You press the wrong button!try again. \n");
        }
    } while (1);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

typedef struct linked_list
{
    int data;
    struct linked_list *next;
} node;

node *start = NULL;

node *getnode()
{
    node *ptr;
    ptr = (node *)malloc(sizeof(node));

    if (ptr == NULL)
        return 0;

    int data;
    printf("Enter the value of data:\n");
    scanf("%d", &data);

    ptr->data = data;
    ptr->next = NULL;

    return ptr;
}

void creation()
{
    node *newnode = getnode();

    if (start == NULL)
    {
        start = newnode;
        return;
    }

    node *ptr = start;
    while (ptr->next != NULL)
        ptr = ptr->next;
    ptr->next = newnode;
}

void insertion_at_beginning()
{
    node *newnode = getnode();

    if (start == NULL)
    {
        start = newnode;
        return;
    }

    newnode->next = start;
    start = newnode;

    printf("The inserted element is %d\n", newnode->data);
}

void insertion_at_specific_position()
{
    node *newnode = getnode();
    node *ptr = start;
    int i = 1;

    int position;
    printf("Enter the position where you want to enter the data: \n");
    scanf("%d", &position);

    if (position == 1)
    {
        insertion_at_beginning();
        return;
    }

    while (i != position - 1 && ptr != NULL)
    {
        ptr = ptr->next;
        i++;
    }

    if (ptr == NULL)
    {
        printf("This position is invalid!\n");
        return;
    }

    newnode->next = ptr->next;
    ptr->next = newnode;

    printf("The inserted element is %d\n", newnode->data);
}

void insertion_at_end()
{
    node *newnode = getnode();

    if (start == NULL)
    {
        start = newnode;
        return;
    }

    node *ptr = start;

    while (ptr->next != NULL)
        ptr = ptr->next;

    ptr->next = newnode;

    printf("The inserted element is %d\n", newnode->data);
}

void deletion_at_beginning()
{
    if (start == NULL)
    {
        printf("Linked list is empty deletion operation can't be performed.\n");
        return;
    }

    node *ptr = start;

    start = start->next;

    printf("The deleted element is %d\n", ptr->data);
    free(ptr);
}

void deletion_at_specific_position()
{
    node *ptr_front = start->next;
    node *ptr_back = start;
    int i = 1;

    int position;
    printf("Enter the position you want to delete:\n");
    scanf("%d", &position);

    if (start == NULL&&position==0)
    {
        printf("Linked list is empty deletion operation can't be performed.\n");
        return;
    }
    else if (start->next == NULL&&position==1)
    {
        deletion_at_beginning();
        return;
    }

    while (i != position - 1)
    {
        ptr_front = ptr_front->next;
        ptr_back = ptr_back->next;
        i++;
    }

    ptr_back->next = ptr_front->next;
    printf("The deleted data is %d.\n", ptr_front->data);
    free(ptr_front);
}

void deletion_at_end()
{
    if (start == NULL)
        printf("Linked list is empty deletion operation can't be performed.\n");
    else if (start->next == NULL)
    {
        printf("The deleted data is %d.\n", start->data);
        free(start);
        start = NULL;
    }
    else
    {
        node *ptr_front = start->next;
        node *ptr_back = start;

        while (ptr_front->next != NULL)
        {
            ptr_front = ptr_front->next;
            ptr_back = ptr_back->next;
        }

        printf("The deleted data is %d.\n", ptr_front->data);
        ptr_back->next = NULL;

        free(ptr_front);
    }
}

void traversal()
{
    if (start == NULL)
        printf("No data in a list.\n");
    else
    {
        node *ptr = start;
        int i = 1;

        printf("Data of a linked list: \n");

        while (ptr != NULL)
        {
            printf("Element %d : %d\n", i, ptr->data);
            i++;
            ptr = ptr->next;
        }
    }
}

int main_menu()
{
    int choose;
    printf("Choose the operation that you want to perform:\n");
    printf("Press 1 for creation.\n");
    printf("Press 2 for insertion.\n");
    printf("Press 3 for deletion.\n");
    printf("Press 4 for traversal.\n");
    printf("Press 5 for Exit.\n");
    scanf("%d", &choose);
    return choose;
}

int insertion_menu()
{
    int choose;
    printf("Choose the operation that you want to perform:\n");
    printf("Press 1 for insertion at beginning.\n");
    printf("Press 2 for insertion at specify position.\n");
    printf("Press 3 for insertion at end.\n");
    scanf("%d", &choose);
    return choose;
}

int deletion_menu()
{
    int choose;
    printf("Choose the operation that you want to perform:\n");
    printf("Press 1 for deletion at beginning.\n");
    printf("Press 2 for deletion at specify position.\n");
    printf("Press 3 for deletion at end.\n");
    scanf("%d", &choose);
    return choose;
}

int main()
{
    int main_choice;
    int insertion_choice;
    int deletion_choice;

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
            insertion_choice = insertion_menu();
            switch (insertion_choice)
            {
            case 1:
                insertion_at_beginning();
                printf("After Insertion!\n");
                traversal();
                printf("\n");
                break;

            case 2:
                insertion_at_specific_position();
                printf("After Insertion!\n");
                traversal();
                printf("\n");
                break;

            case 3:
                insertion_at_end();
                printf("After Insertion!\n");
                traversal();
                printf("\n");
                break;

            default:
                printf("You press the wrong button!\n");
                printf("\n");
                break;
            }

            break;

        case 3:
            deletion_choice = deletion_menu();
            switch (deletion_choice)
            {
            case 1:
                deletion_at_beginning();
                printf("After deletion!\n");
                traversal();
                printf("\n");
                break;

            case 2:
                deletion_at_specific_position();
                printf("After deletion!\n");
                traversal();
                printf("\n");
                break;

            case 3:
                deletion_at_end();
                printf("After deletion!\n");
                traversal();
                printf("\n");

                break;

            default:
                printf("You press the wrong button!\n");
                printf("\n");
                break;
            }

            break;

        case 4:
            traversal();
            printf("\n");
            break;

        case 5:
            return 0;

        default:
            printf("You Press the wrong button!\n");
            printf("\n");
        }
    } while (1);

    return 0;
}
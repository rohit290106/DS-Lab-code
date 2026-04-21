#include <stdio.h>
#include <stdlib.h>

int count();
typedef struct circular_linked_list
{
    int data;
    struct circular_linked_list *next;
} node;

node *start = NULL;

node *getnode()
{
    node *ptr = (node *)malloc(sizeof(node));
    if (ptr == NULL)
    {
        printf("Memory is full!, node can't be created");
        return 0;
    }

    int value;
    printf("Enter the value:");
    scanf("%d", &value);

    ptr->data = value;
    ptr->next = NULL;

    return ptr;
}

void create_node()
{
    node *newnode, *last = NULL;

    int count;
    printf("Enter number of nodes: ");
    scanf("%d", &count);

    for (int i = 0; i < count; i++)
    {
        newnode = getnode();

        if (start == NULL)
        {
            start = newnode;
            last = newnode;
            newnode->next = start;
        }
        else
        {
            last->next = newnode;
            newnode->next = start;
            last = newnode;
        }
    }
}

int count()
{
    if (start == NULL)
        return 0;

    node *temp = start;
    int i = 0;

    do
    {
        temp = temp->next;
        i++;
    } while (temp != start);

    printf("The no. of nodes in a list is %d.\n", i);

    return i;
}
void insert_at_beginning()
{
    node *newnode = getnode();
    node *temp = start;

    if (start == NULL)
    {
        start = newnode;
        start->next = start;
        return;
    }

    while (temp->next != start)
        temp = temp->next;

    newnode->next = start;
    temp->next = newnode;
    start = newnode;
}

void insert_at_position()
{
    node *newnode = getnode();
    node *temp = start;
    int position;
    int i = 1;

    if (start == NULL)
    {
        start = newnode;
        start->next = start;
        return;
    }

    printf("Enter the position of insertion from 1 to %d:\n", count());
    scanf("%d", &position);

    if (position < 1)
    {
        printf("Position is invalid!\n");
        return;
    }
    else if (position == 1)
    {
        insert_at_beginning();
    }
    else
    {
        while (temp->next != start && i < position - 1)
        {
            temp = temp->next;
            i++;
        }

        if (temp->next == start)
        {
            printf("Position is invalid!\n");
            return;
        }

        newnode->next = temp->next;
        temp->next = newnode;
    }
}

void insert_at_end()
{
    node *newnode = getnode();
    node *temp = start;

    if (start == NULL)
    {
        start = newnode;
        start->next = start;
        return;
    }

    while (temp->next != start)
        temp = temp->next;

    temp->next = newnode;
    newnode->next = start;
}

void delete_at_beginning()
{
    node *temp = start;
    node *hold = start;

    if (start == NULL)
    {
        printf("List is Empty!");
        return;
    }

    if (start->next == start)
    {
        printf("The deleted data is %d.\n", start->data);
        free(start);
        start = NULL;
        return;
    }

    while (temp->next != start)
        temp = temp->next;

    start = start->next;
    temp->next = start;
    printf("The deleted data is %d.\n", hold->data);
    free(hold);
}

void delete_at_position()
{
    node *temp_front = start->next;
    node *temp_back = start;
    int position;
    int i = 1;

    if (start == NULL)
    {
        printf("List is Empty!\n");
        return;
    }

    printf("Enter the position of deletion from 1 to %d:\n", count());
    scanf("%d", &position);

    if (position < 1)
    {
        printf("Position is invalid!\n");
        return;
    }
    else if (position == 1)
    {
        delete_at_beginning();
    }
    else
    {
        while (temp_front->next != start && i < position - 1)
        {
            temp_back = temp_front;
            temp_front = temp_front->next;
            i++;
        }

        if (temp_front->next == start)
        {
            printf("Position is invalid!\n");
            return;
        }

        temp_back->next = temp_front->next;
        printf("The deleted data is %d.\n", temp_front->data);
        free(temp_front);
    }
}

void delete_at_end()
{
    node *temp_front = start->next;
    node *temp_back = start;

    if (start == NULL)
    {
        printf("List is Empty!");
        return;
    }

    if (start->next == start)
    {
        printf("The deleted data is %d.\n", start->data);
        free(start);
        start = NULL;
        return;
    }

    while (temp_front->next != start)
    {
        temp_back = temp_front;
        temp_front = temp_front->next;
    }

    temp_back->next = start;
    printf("The deleted data is %d.\n", temp_front->data);
    free(temp_front);
}

void traverse()
{
    node *temp = start;
    int i = 1;

    if (start == NULL)
    {
        printf("List is Empty!");
        return;
    }

    do
    {
        printf("Element %d:%d\n", i++, temp->data);
        temp = temp->next;
    } while (temp != start);
}

int menu()
{
    int choice;
    printf("Press 1 for creation.\n");
    printf("Press 2 for count.\n");
    printf("Press 3 for insertion.\n");
    printf("Press 4 for delete.\n");
    printf("Press 5 for display.\n");
    printf("Press 6 for exit.\n");
    scanf("%d", &choice);
    return choice;
}

int insertion_menu()
{
    int insert_choice;
    printf("Press 1 for insertion at beginning.\n");
    printf("Press 2 for insertion at position.\n");
    printf("Press 3 for insertion at end.\n");
    scanf("%d", &insert_choice);
    return insert_choice;
}

int deletion_menu()
{
    int delete_choice;
    printf("Press 1 for deletion at beginning.\n");
    printf("Press 2 for deletion at position.\n");
    printf("Press 3 for deletion at end.\n");
    scanf("%d", &delete_choice);
    return delete_choice;
}

int main()
{
    int choice;
    int insert_choice;
    int delete_choice;

    do
    {
        choice = menu();

        switch (choice)
        {
        case 1:
            create_node();
            break;

        case 2:
            count();
            break;

        case 3:
            insert_choice = insertion_menu();
            switch (insert_choice)
            {
            case 1:
                insert_at_beginning();
                break;
            case 2:
                insert_at_position();
                break;
            case 3:
                insert_at_end();
                break;
            default:
                printf("You press wrong button!");
            }
            break;

        case 4:
            delete_choice = deletion_menu();
            switch (delete_choice)
            {
            case 1:
                delete_at_beginning();
                break;
            case 2:
                delete_at_position();
                break;
            case 3:
                delete_at_end();
                break;
            default:
                printf("You press wrong button!");
            }
            break;

        case 5:
            traverse();
            break;

        case 6:
            printf("Exiting program ... \n");
            return 0;

        default:
            printf("You press wrong button!\n");
            break;
        }

        if (choice != 6 && choice != 1 && choice != 2)
        {
            printf("\nCurrent List:\n");
            traverse();
        }

        printf("\n");
    } while (choice != 5);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *front = NULL, *rear = NULL;

void enqueue(int x)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = x;

    if (front == NULL)
    {
        front = rear = newnode;
        newnode->next = front;
    }
    else
    {
        rear->next = newnode;
        rear = newnode;
        rear->next = front;
    }
    printf("%d inserted\n", x);
}

void dequeue()
{
    if (front == NULL)
        printf("Circular Queue is Empty\n");
    else
    {
        struct node *temp;
        temp = front;
        printf("%d deleted\n", temp->data);

        if (front == rear)
        {
            front = rear = NULL;
        }
        else
        {
            front = front->next;
            rear->next = front;
        }
        free(temp);
    }
}

void display()
{
    struct node *temp;
    if (front == NULL)
        printf("Queue is Empty\n");
    else
    {
        temp = front;
        printf("Queue elements: ");
        do
        {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != front);
        printf("\n");
    }
}

int main()
{
    enqueue(5);
    enqueue(15);
    enqueue(25);
    display();
    dequeue();
    display();
    return 0;
}

// 5 inserted
// 15 inserted
// 25 inserted

// Queue elements: 5 15 25

// 5 deleted

// Queue elements: 15 25

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int size;
    int front;
    int rear;
    int *array;
} queue;

int isFull(queue *q)
{
    return (q->rear == q->size - 1);
}

int isEmpty(queue *q)
{
    return (q->front == q->rear);
}

void enqueue(queue *q)
{
    if (isFull(q))
    {
        printf("Queue is overflow enqueue operation can't be performed.\n");
    }

    int value;
    printf("Enter the value you want to push in queue:\n");
    scanf("%d", &value);

    q->rear++;
    q->array[q->rear] = value;
    printf("The push value in a queue is %d\n\n", q->array[q->rear]);
}

void dequeue(queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is underflow dequeue operation can't be performed.\n\n");
        return;
    }

    q->front++;
    int value = q->array[q->front];
    printf("The pop value in a queue is %d\n\n", value);

    if (q->front == q->rear)
        q->front = q->rear = -1;
}

void display(queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is underflow display operation can't be performed.\n\n");
    }
    printf("The element in a queue!\n");

    for (int i = q->front + 1; i <= q->rear; i++)
    {
        printf("Element:%d\n", q->array[i]);
    }

    printf("\n");
}

int menu()
{
    int choice;
    printf("Enter the operation you want to perform in a queue.\n");
    printf("press 1 for enqueue.\n");
    printf("press 2 for dequeue.\n");
    printf("press 3 for display.\n");
    printf("press 4 for exit.\n");
    printf("Enter your choice:\n");
    scanf("%d", &choice);
    return choice;
}

int main()
{
    queue *q = (queue *)malloc(sizeof(queue));
    q->size = 10;
    q->front = q->rear = -1;
    q->array = (int *)malloc(q->size * sizeof(int));

    while (1)
    {
        switch (menu())
        {
        case 1:
            enqueue(q);
            break;
        case 2:
            dequeue(q);
            break;
        case 3:
            display(q);
            break;
        case 4:
            free(q->array);
            free(q);
            return 0;
        default:
            printf("You press wrong button!try again.\n\n");
        }
    }

    return 0;
}
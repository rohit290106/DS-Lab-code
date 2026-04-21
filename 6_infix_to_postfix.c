#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    int size;
    int top;
    char *array;
} stack;

int full(stack *sp)
{
    return sp->top == sp->size - 1;
}

int empty(stack *sp)
{
    return sp->top == -1;
}

char top(stack *sp)
{
    return sp->array[sp->top];
}

int operator(char a)
{
    if (a == '+' || a == '-' || a == '*' || a == '/' || a == '^')
        return 1;
    return 0;
}

int precedence(char a)
{
    if (a == '^')
        return 3;
    else if (a == '*' || a == '/')
        return 2;
    else if (a == '+' || a == '-')
        return 1;
    else
        return 0;
}

void push(stack *sp, char value)
{
    if (full(sp))
    {
        printf("Stack is overfow.\n");
        return;
    }
    sp->array[++(sp->top)] = value;
}

char pop(stack *sp)
{
    if (empty(sp))
    {
        printf("Stack is underflow.\n");
        return '\0';
    }
    return sp->array[(sp->top)--];
}

char *infix_to_postfix(char *infix)
{
    stack *sp = (stack *)malloc(sizeof(stack));
    sp->size = strlen(infix);
    sp->top = -1;
    sp->array = (char *)malloc(sp->size * sizeof(char));
    char *postfix = (char *)malloc(sp->size + 1 * sizeof(char));
    int i = 0;
    int j = 0;

    while (infix[i] != '\0')
    {
        if (!operator(infix[i]))
        {
            postfix[j] = infix[i];
            i++;
            j++;
        }
        else
        {
            if (precedence(infix[i]) > precedence(top(sp)))
            {
                push(sp, infix[i]);
                i++;
            }
            else
            {
                postfix[j] = pop(sp);
                j++;
            }
        }
    }
    while (!empty(sp))
    {
        postfix[j] = pop(sp);
        j++;
    }
    postfix[j] = '\0';

    return postfix;
}

int main()
{
    char infix[100];
    int choice;
    do
    {
        printf("Press 1 for conversion from infix to potfix.\n");
        printf("Press 2 for Exit.\n");
        scanf("%d", &choice);

        if (choice == 1)
        {
            printf("Write the expression in infix:\n");
            scanf("%s", infix);

            printf("The Expression in postfix is %s\n\n", infix_to_postfix(infix));
        }
        else if (choice == 2)
        {
            printf("Exiting from the program.\n\n");
        }
        else
        {
            printf("Wrong button press!try again.\n\n");
        }
    } while (choice != 2);

    return 0;
}
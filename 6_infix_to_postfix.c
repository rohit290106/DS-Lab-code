#include <stdio.h>
#include <ctype.h>

char stack[50];
int top = -1;

/* Push operation */
void push(char x) {
    stack[++top] = x;
}

/* Pop operation */
char pop() {
    if (top == -1)
        return -1;
    else
        return stack[top--];
}

/* Function to check operator precedence */
int priority(char x) {
    if (x == '(')
        return 0;
    if (x == '+' || x == '-')
        return 1;
    if (x == '*' || x == '/')
        return 2;
    return 0;
}

int main() {
    char exp[50];
    char *e, x;

    printf("Enter the infix expression: ");
    scanf("%s", exp);

    e = exp;

    printf("Postfix expression: ");

    while (*e != '\0') {
        /* If operand, print it */
        if (isalnum(*e)) {
            printf("%c", *e);
        }
        /* If '(', push to stack */
        else if (*e == '(') {
            push(*e);
        }
        /* If ')', pop until '(' */
        else if (*e == ')') {
            while ((x = pop()) != '(') {
                printf("%c", x);
            }
        }
        /* If operator */
        else {
            while (priority(stack[top]) >= priority(*e)) {
                printf("%c", pop());
            }
            push(*e);
        }
        e++;
    }

    /* Pop remaining operators */
    while (top != -1) {
        printf("%c", pop());
    }

    return 0;
}


// Enter the infix expression: ((A+B)*C-(D-E))*(F+G)
// Postfix expression: AB+C*DE--FG+*

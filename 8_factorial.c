#include <stdio.h>
#define MAX 50

int stack[MAX];
int top = -1;

/* Push operation */
void push(int value) {
    stack[++top] = value;
}

/* Pop operation */
int pop() {
    return stack[top--];
}

int main() {
    int n, i;
    long int fact = 1;

    printf("Enter a number: ");
    scanf("%d", &n);

    /* Push numbers into stack */
    for (i = n; i >= 1; i--) {
        push(i);
    }

    /* Pop and multiply */
    while (top != -1) {
        fact = fact * pop();
    }

    printf("Factorial of %d is %ld", n, fact);

    return 0;
}

// Enter a number: 5
// Factorial of 5 is 120



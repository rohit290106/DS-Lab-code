// 2.2 Program to Insert an Element at the Beginning

#include <stdio.h>

void transverse(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d \n", a[i]);
    }
}

void insertion_start(int a[], int e, int n, int c)
{
    if (n >= c)
    {
        printf("The insertion is failed because overflow of memory. \n");
    }
    else
    {
        for (int i = n - 1; i >= 0; i--)
        {
            a[i + 1] = a[i];
        }
        a[0] = e;
        n++;
    }
    transverse(a, n);
}

int main()
{
    int array[20] = {2, 4, 6, 8, 0, 9, 7, 5, 3, 1};
    int capacity = sizeof(array) / sizeof(int);
    int size = 10;
    int element;

    transverse(array, size);

    printf("The element you want to put in beginning: \n");
    scanf("%d", &element);

    printf("After Insertion \n");

    insertion_start(array, element, size, capacity);

    return 0;
}
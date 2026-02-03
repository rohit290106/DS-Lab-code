// 2.2 Program to Insert an Element at the Beginning

#include <stdio.h>

void transverse(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d \n", a[i]);
    }
}

void deletion_start(int a[], int n)
{
    if (n == -1)
    {
        printf("The insertion is failed because underflow of memory. \n");
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            a[i] = a[i + 1];
        }
        n--;
    }
    transverse(a, n);
}

int main()
{
    int array[20] = {2, 4, 6, 8, 0, 9, 7, 5, 3, 1};
    int size = 10;

    transverse(array, size);

    printf("After deletion. \n");

    deletion_start(array,size);

    return 0;
}
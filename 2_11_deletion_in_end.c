#include <stdio.h>

void transverse(int array[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d \n", array[i]);
    }
}

void deletion_end(int a[], int n)
{
    if (n == 0)
    {
        printf("The insertion is failed because overflow of memory. \n");
    }

    printf("After deletion \n");

    n--;

    transverse(a, n);
}

int main()
{
    int array[20] = {2, 4, 6, 8, 0, 9, 7, 5, 3, 1};
    int size = 10;
    int element;

    transverse(array, size);

    deletion_end(array, size);

    return 0;
}

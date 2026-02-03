#include <stdio.h>

void transverse(int array[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d \n", array[i]);
    }
}

void insertion_mid(int array[], int e, int n, int c,int x)
{
    if (n >= c)
    {
        printf("The insertion is failed because overflow of memory. \n");
    }
    else
    {
        for (int i = n - 1; i >= x; i--)
        {
            array[i + 1] = array[i];
        }
        array[x] = e;
        n++;
    }
    transverse(array, n);
}

int main()
{
    int array[20] = {2, 4, 6, 8, 0, 9, 7, 5, 3, 1};
    int capacity = sizeof(array) / sizeof(int);
    int size = 10;
    int element;
    int index;

    transverse(array, size);

    printf("The element you want to put in middle: \n");
    scanf("%d", &element);

    printf("The index where you want to put element: \n");
    scanf("%d", &index);

    printf("After Insertion \n");

    insertion_mid(array, element, size, capacity,index);

    return 0;
}
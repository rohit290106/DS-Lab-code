#include <stdio.h>

void transverse(int array[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d \n", array[i]);
    }
}

int main()
{
    int array[20] = {2, 4, 6, 8, 0, 9, 7, 5, 3, 1};
    int capacity = sizeof(array) / sizeof(int);
    int size = 10;
    int element;

    transverse(array, size);

    printf("The element you want to insert: \n");
    scanf("%d", &element);

    if (size >= capacity)
    {
        printf("The insertion is failed because overflow of memory. \n");
    }
    else
    {
        array[size++] = element;
    }

    printf("After Insertion \n");

    transverse(array, size);

    return 0;
}
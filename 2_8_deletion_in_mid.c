#include <stdio.h>

void transverse(int array[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d \n", array[i]);
    }
}

void deletion_mid(int array[],int n, int c,int x)
{
    if (n==-1)
    {
        printf("The insertion is failed because overflow of memory. \n");
    }
    else{
        for (int i = x; i<n; i++)
        {
            array[i] = array[i+1];
        }
        n--;
    }
    transverse(array, n);
}

int main()
{
    int array[20] = {2, 4, 6, 8, 0, 9, 7, 5, 3, 1};
    int capacity = sizeof(array) / sizeof(int);
    int size = 10;
    int index;

    transverse(array, size);


    printf("The index where you want to delete the element: \n");
    scanf("%d", &index);

    printf("After deletion. \n");

    deletion_mid(array, size, capacity,index);

    return 0;
}
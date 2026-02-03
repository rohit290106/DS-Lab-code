#include <stdio.h>

void transverse(int array[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d \n", array[i]);
    }
}

void deletion_before(int a[], int k, int n)
{
    if (n == -1)
    {
        printf("The insertion is failed because underflow of memory. \n");
    }
    else
    {
        for (int i = 0; i < n - 1; i++)
        {
            if (a[i] == k)
            {
                for (int j = i - 1; j < n - 1; j++)
                {
                    a[j] = a[j + 1];
                }
                n--;
                transverse(a, n);
            }
        }
    }
}

int main()
{
    int array[20] = {1, 5, 9, 2, 3, 4, 0, 6, 3, 7, 8};
    int size = 10;
    int key;

    transverse(array, size);

    printf("Enter the element before you want to delete: \n");
    scanf("%d", &key);

    printf("After deletion \n");

    deletion_before(array, key, size);

    return 0;
}
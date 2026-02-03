#include <stdio.h>

void transverse(int array[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d \n", array[i]);
    }
}

int error(int a[], int n, int k)
{
    int e = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] != k)
        {
            e++;
        }
    }
    if (e == n)
    {
        return 0;
    }
}

void insertion_after(int a[], int e, int n, int c, int k)
{
    if (n >= c)
    {
        printf("The insertion is failed because overflow of memory. \n");
    }
    else
    {
        for (int i = n - 1; i > 0; i--)
        {
            if (a[i] == k)
            {
                a[i + 1] = e;
                break;
                n++;
            }
            else
            {
                a[i + 1] = a[i];
            }
        }

        // int i = n - 1;

        // while (a[i] != k)
        // {
        //     a[i + 1] = a[i];
        //     i--;
        // }
        // a[i + 1] = e;
        // n++;
    }
    transverse(a, n);
}

int main()
{
    int array[20] = {2, 4, 6, 8, 0, 9, 7, 5, 3, 1};
    int capacity = sizeof(array) / sizeof(int);
    int size = 10;
    int put;
    int element;

    transverse(array, size);

    do
    {
        printf("The element after you want to insert: \n");
        scanf("%d", &put);

        int e = error(array, size, put);

        if (e == 0)
        {
            printf("This element is not present in a array.\n\n");
        }
        else
        {
            break;
        }
    } while (1);

    printf("Enter the element you want to insert after %d: \n", put);
    scanf("%d", &element);

    printf("After Insertion \n");

    insertion_after(array, element, size, capacity, put);

    return 0;
}
#include <stdio.h>

void transverse(int array[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d \n", array[i]);
    }
}

int error(int a[], int n, int d)
{
    int e = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] != d)
        {
            e++;
        }
    }
    if (e == n)
    {
        return 0;
    }
}

int deletion_after(int a[], int n,int k)
{
    if (n == -1)
    {
        printf("The insertion is failed because overflow of memory. \n");
    }
    else
    {
        for (int i = 0; i < n - 1; i++)
        {
            if (a[i] == k)
            {
                for (int j = i + 1; j < n - 1; j++)
                {
                    a[j] = a[j + 1];
                }
                n--;
                printf("\nAfter deletion. \n");
                transverse(a, n);
                return 0;
            }
        }
        // int i = 0;
        // while (i != n - 1)
        // {
        //     if (a[i] == k)
        //     {
        //         i = i + 1;
        //         while (i < n - 1)
        //         {
        //             a[i] = a[i + 1];
        //             i++;
        //         }
        //         n--;
        //         printf("After deletion.\n");
        //         tranverse(a, n);
        //         return 0;
        //     }
        //     i++;
        // }
    }
}

int main()
{
    int array[20] = {2, 4, 6, 8, 0, 9, 7, 5, 3, 1};
    int size = 10;
    int delete;

    transverse(array, size);

       do
    {
        printf("Enter the element after you want to delete: \n");
        scanf("%d", &delete);

        int e = error(array, size, delete);

        if (e == 0)
        {
            printf("This element is not present in an array.\n\nEnter Again!\n\n");
        }
        else{
            break;
        }
    } while (1);

    deletion_after(array, size,delete);

    return 0;
}
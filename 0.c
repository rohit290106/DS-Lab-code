#include <stdio.h>

void tranverse(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", a[i]);
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

int deletion_after_number(int a[], int n, int c, int e)
{
    if (c == 0)
    {
        printf("The array is empty.\n");
    }
    else
    {
        int i = 0;
        while (i != n - 1)
        {
            if (a[i] == e)
            {
                i = i + 1;
                while (i < n - 1)
                {
                    a[i] = a[i + 1];
                    i++;
                }
                n--;
                printf("After deletion.\n");
                tranverse(a, n);
                return 0;
            }
            i++;
        }
    }
}

int main()
{
    int array[20] = {1, 3, 2, 5, 4, 7, 6, 9, 8, 0};
    int capacity = (sizeof(array)) / sizeof(int);
    int size = 10;
    int delete;

    tranverse(array, size);

    do
    {
        printf("Enter the element after you want to delete: \n");
        scanf("%d", &delete);

        int e = error(array, size, delete);

        if (e == 0)
        {
            printf("This element is not present in an array.\n");
        }
        else
        {
            break;
        }
    } while (1);

    // printf("Enter the index that you want to delete: \n");
    // scanf("%d",&index);

    deletion_after_number(array, size, capacity, delete);

    return 0;
}
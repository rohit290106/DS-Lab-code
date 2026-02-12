// 2.2 Program to Insert an Element at the Beginning

#include <stdio.h>

void transverse(int a[], int n)
{
    printf("The element of the array.\n");

    for (int i = 0; i < n; i++)
    {
        printf("%d \n", a[i]);
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

void linear_search(int array[], int n)
{
    int count = 0;
    int element;
    printf("Enter the element you want to search:\n");
    scanf("%d", &element);

    for (int i = 0; i < n; i++)
    {
        if (array[i] == element)
        {
            printf("The element %d is found at %d index.\n", element, i);
            count = 1;
        }
    }
    if (count != 1)
    {
        printf("The element %d is not found in list.\n", element);
    }
}

void binary_search(int array[], int n)
{
    int count = 0;
    int element;
    printf("Enter the element you want to search:\n");
    scanf("%d", &element);

    int low, high, mid;
    low = 0;
    high = n - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (array[mid] == element)
        {
            printf("The element %d is found at %d index.\n", element, mid);
            count = 1;
            break;
        }
        else if (array[mid] < element)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    if (count != 1)
    {
        printf("The element %d is not found in list.\n", element);
    }
}

void insertion_beginning(int a[], int n, int c)
{
    int element;
    printf("Enter the value you want to insert:\n");
    scanf("%d", &element);

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
        a[0] = element;
        n++;
        printf("After Insertion!\n");
        transverse(a, n);
    }
}

void insertion_index(int array[], int n, int c)
{
    int index;
    printf("Enter the index where you want to insert. \n");
    scanf("%d", &index);

    int element;
    printf("Enter the value you want to insert:\n");
    scanf("%d", &element);

    if (n >= c)
    {
        printf("The insertion is failed because overflow of memory. \n");
    }
    else
    {
        for (int i = n - 1; i >= index; i--)
        {
            array[i + 1] = array[i];
        }
        array[index] = element;
        n++;

        printf("After Insertion!\n");
        transverse(array, n);
    }
}

void insertion_after_number(int a[], int n, int c)
{
    int number;
    int count = 0;

    do
    {
        printf("The element after you want to insert: \n");
        scanf("%d", &number);

        int e = error(a, n, number);

        if (e == 0)
        {
            printf("This element is not present in a array.\n\n");
        }
        else
        {
            count = 1;
        }
    } while (count != 1);

    int element;
    printf("Enter the element you want to insert after %d: \n", number);
    scanf("%d", &element);

    if (n >= c)
    {
        printf("The insertion is failed because overflow of memory. \n");
    }
    else
    {
        for (int i = n - 1; i > 0; i--)
        {
            if (a[i] == number)
            {
                a[i + 1] = element;
                n++;
                break;
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

        printf("After Insertion!\n");

        transverse(a, n);
    }
}

void insertion_before_number(int a[], int n, int c)
{
    int number;
    int count = 0;

    do
    {
        printf("The element before you want to insert: \n");
        scanf("%d", &number);

        int e = error(a, n, number);

        if (e == 0)
        {
            printf("This element is not present in a array.\n\n");
        }
        else
        {
            count = 1;
        }
    } while (count != 1);

    int element;
    printf("Enter the element you want to insert before %d: \n", number);
    scanf("%d", &element);

    if (n >= c)
    {
        printf("The insertion is failed because overflow of memory. \n");
    }
    else
    {
        for (int i = n - 1; i > 0; i--)
        {
            if (a[i] == number)
            {
                a[i + 1] = a[i];
                a[i] = element;
                break;
                n++;
            }
            else
            {
                a[i + 1] = a[i];
            }
        }

        // int i = n - 1;

        // while (a[i] != d)
        // {
        //     a[i + 1] = a[i];
        //     i--;
        // }
        // a[i + 1] = a[i];
        // a[i] = e;
        // n++;

        printf("After Insertion.\n");
        transverse(a, n);
    }
}

void insertion_end(int a[], int n, int c)
{
    int element;
    printf("The element you want to insert: \n");
    scanf("%d", &element);

    if (n >= c)
    {
        printf("The insertion is failed because overflow of memory. \n");
    }
    else
    {
        a[n++] = element;
        printf("After Insertion \n");
        transverse(a, n);
    }
}

void deletion_beginning(int a[], int n)
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
        printf("After Deletion!\n");
        transverse(a, n);
    }
}

void deletion_index(int array[], int n)
{
    int index;
    printf("Enter the index which value you want to delete:\n");
    scanf("%d", &index);

    if (n == -1)
    {
        printf("The insertion is failed because overflow of memory. \n");
    }
    else
    {
        for (int i = index; i < n; i++)
        {
            array[i] = array[i + 1];
        }
        n--;
        printf("After Deletion!\n");
        transverse(array, n);
    }
}

int deletion_after_number(int a[], int n)
{
    int number;
    int count = 0;

    do
    {
        printf("The element after you want to delete: \n");
        scanf("%d", &number);

        int e = error(a, n, number);

        if (e == 0)
        {
            printf("This element is not present in a array.\n\n");
        }
        else
        {
            count = 1;
        }
    } while (count != 1);

    if (n == -1)
    {
        printf("The insertion is failed because overflow of memory. \n");
    }
    else
    {
        for (int i = 0; i < n - 1; i++)
        {
            if (a[i] == number)
            {
                for (int j = i + 1; j < n - 1; j++)
                {
                    a[j] = a[j + 1];
                }
                n--;
                printf("After deletion. \n");
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

void deletion_before_number(int a[], int n)
{
    int number;
    int count = 0;

    do
    {
        printf("The element before you want to delete: \n");
        scanf("%d", &number);

        int e = error(a, n, number);

        if (e == 0)
        {
            printf("This element is not present in a array.\n\n");
        }
        else
        {
            count = 1;
        }
    } while (count != 1);

    if (n == -1)
    {
        printf("The deletion is failed because underflow of memory. \n");
    }
    else
    {
        for (int i = 0; i < n - 1; i++)
        {
            if (a[i] == number)
            {
                for (int j = i - 1; j < n - 1; j++)
                {
                    a[j] = a[j + 1];
                }
                n--;
                printf("After Deletion. \n");
                transverse(a, n);
            }
        }
    }
}

void deletion_end(int a[], int n)
{
    if (n == 0)
    {
        printf("The insertion is failed because overflow of memory. \n");
    }
    else
    {
        n--;
        printf("After deletion \n");
        transverse(a, n);
    }
}

int main()
{
    int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int capacity = sizeof(array) / sizeof(int);
    int size =-1;
    int element;
    int choice;
    int choice_search;

    do
    {
        printf("Enter the mode of operation that you want to perform on Array.\n");
        printf("Press 1 for searching the element.\n");
        printf("Press 2 for showing the element.\n");
        printf("Press 3 for insertion the element at the beginning.\n");
        printf("Press 4 for insertion the element at the particular index .\n");
        printf("Press 5 for insertion the element after the number.\n");
        printf("Press 6 for insertion the element before the number.\n");
        printf("Press 7 for insertion the element at the end.\n");
        printf("Press 8 for deletion the element at the beginning.\n");
        printf("Press 9 for deletion the element at the particular index.\n");
        printf("Press 10 for deletion the element after the number.\n");
        printf("Press 11 for deletion the element before the number.\n");
        printf("Press 12 for deletion the element at the end.\n");
        printf("Press 13 for Exit.\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the mode of searching.\n");
            printf("Press 1 for linear search.\n");
            printf("Press 2 for binary search.(Condition:Data has to be arrange in order.)\n");
            scanf("%d", &choice_search);
            if (choice_search == 1)
            {
                linear_search(array, size);
            }
            else if (choice_search == 2)
            {
                binary_search(array, size);
            }
            else
            {
                printf("You press wrong button.");
            }
            printf("\n");
            break;
        case 2:
            transverse(array, size);
            printf("\n");
            break;
        case 3:
            transverse(array, size);
            insertion_beginning(array, size, capacity);
            printf("\n");
            size++;
            break;
        case 4:
            transverse(array, size);
            insertion_index(array, size, capacity);
            printf("\n");
            size++;
            break;
        case 5:
            transverse(array, size);
            insertion_after_number(array, size, capacity);
            printf("\n");
            size++;
            break;
        case 6:
            transverse(array, size);
            insertion_before_number(array, size, capacity);
            printf("\n");
            size++;
            break;
        case 7:
            transverse(array, size);
            insertion_end(array, size, capacity);
            printf("\n");
            size++;
            break;
        case 8:
            transverse(array, size);
            deletion_beginning(array, size);
            printf("\n");
            size--;
            break;
        case 9:
            transverse(array, size);
            deletion_index(array, size);
            printf("\n");
            size--;
            break;
        case 10:
            transverse(array, size);
            deletion_after_number(array, size);
            printf("\n");
            size--;
            break;
        case 11:
            transverse(array, size);
            deletion_before_number(array, size);
            printf("\n");
            size--;
            break;
        case 12:
            transverse(array, size);
            deletion_end(array, size);
            printf("\n");
            size--;
            break;
        case 13:
            return 0;
            printf("\n");
        default:
            printf("You press wrong button.\n");
            printf("\n");
        }
    } while (choice != 13);
    return 0;
}
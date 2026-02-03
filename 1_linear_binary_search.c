#include <stdio.h>

int linear_search(int array[], int element, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (array[i] == element)
        {
            return i + 1;
        }
    }
    return 0;
}

int binary_search(int array[], int element, int n)
{
    int low, high, mid;
    low = 0;
    high = n - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (array[mid] == element)
        {
            return mid + 1;
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
    return 0;
}

int main()
{
    int array[20] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int size = sizeof(array) / sizeof(int);
    int element;

    printf("Enter the element you want to search: \n");
    scanf("%d", &element);

    // for linear search
    int x = linear_search(array, element, size);
    if (x)
    {
        printf("The element %d is found at %d index.\n", element, x - 1);
    }
    else
    {
        printf("The element %d is not found in list.\n", element);
    }

    // for binary search
    int y = binary_search(array, element, size);
    if (y)
    {
        printf("The element %d is found at %d index.\n", element, y - 1);
    }
    else
    {
        printf("The element %d is not found in list.\n", element);
    }
    return 0;
}
#include <stdio.h>
#define MAX 10

int arr[MAX], n;

void display() {
    printf("Array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int isFull() {
    if (n == MAX) {
        printf("Array is FULL!\n");
        return 1;
    }
    return 0;
}

int isEmpty() {
    if (n == 0) {
        printf("Array is EMPTY!\n");
        return 1;
    }
    return 0;
}

void search() {
    if (isEmpty())
        return;
    int x;
    printf("Enter number to search: ");
    scanf("%d", &x);
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            printf("Found at index %d\n", i);
            return;
        }
    }
    printf("Not found\n");
}

void insertAt(int pos) {
    if (isFull())
        return;
    for (int i = n; i > pos; i--)
        arr[i] = arr[i - 1];
    printf("Enter number: ");
    scanf("%d", &arr[pos]);
    n++;
}

void deleteAt(int pos) {
    if (isEmpty())
        return;
    printf("Deleted: %d\n", arr[pos]);
    for (int i = pos; i < n - 1; i++)
        arr[i] = arr[i + 1];
    n--;
}

int findIndex(int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x)
            return i;
    }
    printf("Number not found\n");
    return -1;
}

int main() {
    int choice, x, idx;

    printf("Enter size (max %d): ", MAX);
    scanf("%d", &n);
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    while (1) {
        printf("\n1.Search  2.Insert Begin  3.Insert End\n");
        printf("4.Insert After  5.Insert Before\n");
        printf("6.Delete Begin  7.Delete End\n");
        printf("8.Delete After  9.Delete Before  0.Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                search();
                break;

            case 2:
                insertAt(0);
                break;

            case 3:
                insertAt(n);
                break;

            case 4:
                if (isFull())
                    break;
                printf("Insert after which number? ");
                scanf("%d", &x);
                idx = findIndex(x);
                if (idx != -1)
                    insertAt(idx + 1);
                break;

            case 5:
                if (isFull())
                    break;
                printf("Insert before which number? ");
                scanf("%d", &x);
                idx = findIndex(x);
                if (idx != -1)
                    insertAt(idx);
                break;

            case 6:
                if (!isEmpty())
                    deleteAt(0);
                break;

            case 7:
                if (!isEmpty())
                    deleteAt(n - 1);
                break;

            case 8:
                if (isEmpty())
                    break;
                printf("Delete after which number? ");
                scanf("%d", &x);
                idx = findIndex(x);
                if (idx != -1 && idx + 1 < n)
                    deleteAt(idx + 1);
                else if (idx != -1)
                    printf("No element after it\n");
                break;

            case 9:
                if (isEmpty())
                    break;
                printf("Delete before which number? ");
                scanf("%d", &x);
                idx = findIndex(x);
                if (idx != -1 && idx - 1 >= 0)
                    deleteAt(idx - 1);
                else if (idx != -1)
                    printf("No element before it\n");
                break;

            case 0:
                return 0;
        }
        if (n > 0)
            display();
    }
}

/*Enter size (max 10): 5
Enter 5 elements: 10 20 30 40 50
Array: 10 20 30 40 50

1.Search  2.Insert Begin  3.Insert End
4.Insert After  5.Insert Before
6.Delete Begin  7.Delete End
8.Delete After  9.Delete Before  0.Exit
Choice: 1
Enter number to search: 30
Found at index 2
Array: 10 20 30 40 50

Choice: 2
Enter number: 5
Array: 5 10 20 30 40 50

Choice: 3
Enter number: 60
Array: 5 10 20 30 40 50 60

Choice: 4
Insert after which number? 20
Enter number: 25
Array: 5 10 20 25 30 40 50 60

Choice: 5
Insert before which number? 10
Enter number: 7
Array: 5 7 10 20 25 30 40 50 60

Choice: 6
Deleted: 5
Array: 7 10 20 25 30 40 50 60

Choice: 7
Deleted: 60
Array: 7 10 20 25 30 40 50

Choice: 8
Delete after which number? 25
Deleted: 30
Array: 7 10 20 25 40 50

Choice: 9
Delete before which number? 25
Deleted: 20
Array: 7 10 25 40 50

Choice: 0*/
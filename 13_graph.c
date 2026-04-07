#include <stdio.h>

int a[10][10], v[10], q[10], n, f = -1, r = -1;

void dfs(int x)
{
    int i;
    printf("%d ", x);
    v[x] = 1;
    for (i = 1; i <= n; i++)
        if (a[x][i] && !v[i])
            dfs(i);
}

void bfs(int x)
{
    int i;
    q[++r] = x;
    v[x] = 1;

    while (f != r)
    {
        x = q[++f];
        printf("%d ", x);
        for (i = 1; i <= n; i++)
            if (a[x][i] && !v[i])
            {
                q[++r] = i;
                v[i] = 1;
            }
    }
}

int main()
{
    int i, j, s;

    printf("Enter vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);

    printf("Enter start vertex: ");
    scanf("%d", &s);

    for (i = 1; i <= n; i++) v[i] = 0;
    printf("DFS: ");
    dfs(s);

    for (i = 1; i <= n; i++) v[i] = 0;
    f = r = -1;
    printf("\nBFS: ");
    bfs(s);

    return 0;
}

// Enter vertices: 5
// Enter adjacency matrix:
// 0 1 1 0 0
// 1 0 0 1 1
// 1 0 0 0 0
// 0 1 0 0 0
// 0 1 0 0 0

// Enter start vertex: 1

// DFS: 1 2 4 5 3
// BFS: 1 2 3 4 5

#include <stdio.h>

#define MAX 10

/* BFS traversal */
void bfsTraverse(int adj[MAX][MAX], int n, int start)
{
    int visited[MAX] = {0};
    int q[MAX];
    int f = 0, r = 0;

    visited[start] = 1;
    q[r++] = start;

    printf("BFS Traversal: ");

    while (f < r)
    {
        int curr = q[f++];
        printf("%d ", curr);

        for (int i = 0; i < n; i++)
        {
            if (adj[curr][i] == 1 && !visited[i])
            {
                visited[i] = 1;
                q[r++] = i;
            }
        }
    }
    printf("\n");
}

/* DFS recursion use garera */
void dfsTraverse(int adj[MAX][MAX], int n, int node, int visited[])
{
    visited[node] = 1;
    printf("%d ", node);

    for (int i = 0; i < n; i++)
    {
        if (adj[node][i] == 1 && !visited[i])
        {
            dfsTraverse(adj, n, i, visited);
        }
    }
}

int main()
{
    int n = 5;

    int adjMatrix[MAX][MAX] =
    {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 1, 0},
        {1, 1, 0, 0, 1},
        {0, 1, 0, 0, 1},
        {0, 0, 1, 1, 0}
    };

    int visited[MAX] = {0};

    printf("Adjacency Matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }

    printf("\nVertex 0 bata traversal\n");
    bfsTraverse(adjMatrix, n, 0);

    printf("DFS Traversal: ");
    dfsTraverse(adjMatrix, n, 0, visited);
    printf("\n");

    return 0;
}
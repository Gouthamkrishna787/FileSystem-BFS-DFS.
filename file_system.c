
#include <stdio.h>

#define MAX 20

int graph[MAX][MAX];
int visited[MAX];
int n;

// BFS Algorithm
void BFS(int start, int target)
{
    int queue[MAX], front = 0, rear = 0;
    int found = 0;

    for(int i = 0; i < n; i++)
        visited[i] = 0;

    queue[rear++] = start;
    visited[start] = 1;

    printf("\nBFS Traversal: ");

    while(front < rear)
    {
        int v = queue[front++];
        printf("%d ", v);

        if(v == target)
            found = 1;

        for(int i = 0; i < n; i++)
        {
            if(graph[v][i] == 1 && !visited[i])
            {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }

    if(found)
        printf("\nFile found using BFS.");
    else
        printf("\nFile not found using BFS.");
}

// DFS Algorithm
void DFS(int v, int target, int *found)
{
    visited[v] = 1;

    printf("%d ", v);

    if(v == target)
        *found = 1;

    for(int i = 0; i < n; i++)
    {
        if(graph[v][i] == 1 && !visited[i])
            DFS(i, target, found);
    }
}

int main()
{
    int start, target;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);
    }

    printf("Enter starting node: ");
    scanf("%d", &start);

    printf("Enter file node to search: ");
    scanf("%d", &target);

    if(start < 0 || start >= n ||
       target < 0 || target >= n)
    {
        printf("Invalid node number.\n");
        return 0;
    }

    BFS(start, target);

    for(int i = 0; i < n; i++)
        visited[i] = 0;

    int found = 0;

    printf("\n\nDFS Traversal: ");
    DFS(start, target, &found);

    if(found)
        printf("\nFile found using DFS.");
    else
        printf("\nFile not found using DFS.");

    return 0;
}

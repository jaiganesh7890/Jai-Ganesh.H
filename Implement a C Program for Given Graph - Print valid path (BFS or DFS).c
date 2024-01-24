//Implement a C Program for Given Graph - Print valid path (BFS or DFS)

#include <stdio.h>
#include <stdbool.h>
#define MAX_VERTICES 100

void DFS(int graph[MAX_VERTICES][MAX_VERTICES], int vertex, bool visited[MAX_VERTICES], int destination) {
    visited[vertex] = true;
    printf("%d ", vertex);
    if (vertex == destination)
    {
        printf("\nValid path found!\n");
        return;
    }
    for (int i = 0; i < MAX_VERTICES; i++)
    {
        if (graph[vertex][i] == 1 && !visited[i])
        {
            DFS(graph, i, visited, destination);
        }
    }
}
void BFS(int graph[MAX_VERTICES][MAX_VERTICES], int start, int destination)
{
    bool visited[MAX_VERTICES] = {false};
    int queue[MAX_VERTICES];
    int front = -1, rear = -1;
    visited[start] = true;
    queue[++rear] = start;
    while (front != rear)
    {
        int vertex = queue[++front];
        printf("%d ", vertex);
        if (vertex == destination)
        {
            printf("\nValid path found!\n");
            return;
        }
        for (int i = 0; i < MAX_VERTICES; i++)
        {
            if (graph[vertex][i] == 1 && !visited[i])
            {
                visited[i] = true;
                queue[++rear] = i;
            }
        }
    }
}
int main()
{
    int graph[MAX_VERTICES][MAX_VERTICES] =
    {
        {0, 1, 1, 0, 0},
        {1, 0, 0, 1, 0},
        {1, 0, 0, 1, 1},
        {0, 1, 1, 0, 1},
        {0, 0, 1, 1, 0}
    };
    int start = 0; // Starting vertex
    int destination = 4; // Destination vertex
    printf("DFS traversal: ");
    bool visited[MAX_VERTICES] = {false};
    DFS(graph, start, visited, destination);
    printf("\nBFS traversal: ");
    BFS(graph, start, destination);
    return 0;
}

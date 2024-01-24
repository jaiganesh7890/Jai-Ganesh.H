//Implement a C Program Traveling Salesman Problem to Identify shortest path
Given a set of cities and distances between every pair of cities, the problem is to find the shortest possible route that visits every city exactly once and returns to the starting point.

#include <stdio.h>
#include <limits.h>
#define V 4
int min(int a, int b)
{
    return (a < b) ? a : b;
}
int tsp(int graph[][V], int mask, int pos, int n)
{
    if (mask == (1 << n) - 1)
    {
        return graph[pos][0];
    }
    int ans = INT_MAX;
    for (int city = 0; city < n; city++)
    {
        if ((mask & (1 << city)) == 0 && graph[pos][city] != 0)
        {
            int newAns = graph[pos][city] + tsp(graph, mask | (1 << city), city, n);
            ans = min(ans, newAns);
        }
    }
    return ans;
}
int main()
{
    int graph[V][V] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };
    int shortestPath = tsp(graph, 1, 0, V);
    printf("Shortest Path: %d\n", shortestPath);
    return 0;
}

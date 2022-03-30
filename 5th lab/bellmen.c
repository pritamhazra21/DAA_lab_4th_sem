#include <stdio.h>
#include <limits.h>
void BellmanFord(int graph[][3], int Vert, int Edge)
{
    int dist[Vert];
    dist[0] = 0;
    for (int i = 1; i < Vert; i++)
        dist[i] = INT_MAX;
    for (int i = 0; i < Vert - 1; i++)
    {
        for (int j = 0; j < Edge; j++)
            if (dist[graph[j][0]] + graph[j][2] < dist[graph[j][1]])
                dist[graph[j][1]] = dist[graph[j][0]] + graph[j][2];
    }
    for (int i = 0; i < Vert; i++)
        printf("distance of vertice %d from vertice 0 is = %d\n", i, dist[i]);
}
int main()
{
    int V = 7;
    int E = 10;
    int graph[][3] = {{0, 1, 6},
                      {0, 2, 5},
                      {0, 3, 5},
                      {1, 4, -1},
                      {2, 1, -2},
                      {2, 4, 1},
                      {3, 2, -2},
                      {3, 5, -1},
                      {4, 6, 3},
                      {5, 6, 3}};
    BellmanFord(graph, V, E);
    return 0;
}










// c(1,2)= 6
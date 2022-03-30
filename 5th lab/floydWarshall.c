#include <stdio.h>

#define n 4
#define Inf 9999

void floydWarshall(int graph[][n])
{
    int i, j, k;
    for (k = 0; k < n; k++)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (graph[i][k] + graph[k][j] < graph[i][j])
                    graph[i][j] = graph[i][k] + graph[k][j];
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (graph[i][j] == Inf)
                printf("∞\t");
            else
                printf("%d\t", graph[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    int graph[][n] = {{0, 5, Inf, 10},
                      {Inf, 0, 3, Inf},
                      {Inf, Inf, 0, 1},
                      {Inf, Inf, Inf, 0}};

    floydWarshall(graph);
    return 0;
}
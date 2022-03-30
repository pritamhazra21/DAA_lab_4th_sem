#include <stdio.h>
#include <limits.h>

int ary[10][10];
int completed[10];
int n, cost = 0, start = 0;

int find_next_city(int node)
{
    int i, min_index = INT_MAX, min = INT_MAX, min_cost_path;
    for (i = 0; i < n; i++)
    {
        if ((ary[node][i] != 0) && (completed[i] == 0))
            if (ary[node][i] + ary[i][node] < min)
            {
                min = ary[node][i];
                min_cost_path = ary[node][i];
                min_index = i;
            }
    }

    if (min != INT_MAX)
        cost += min_cost_path;

    return min_index;
}

void TSP(int city)
{
    completed[city] = 1;
    printf("%d --> ", city);
    int next_city = find_next_city(city);
    if (next_city == INT_MAX)
    {
        next_city = 0;
        printf("%d", start);
        cost += ary[city][next_city];

        return;
    }
    TSP(next_city);
}
int main()
{
    printf("Enter the number of cities : ");
    scanf("%d", &n);
    printf("Enter the Cost Matrix\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            scanf("%d", &ary[i][j]);

        completed[i] = 0;
    }
    printf("The Path is:\t");
    TSP(start);
    printf("\nMinimum cost is\t%d\n", cost);
    return 0;
}

// {{0, 4, 1, 3},
//  {4, 0, 2, 1},
//  {1, 2, 0, 5},
//  {3, 1, 5, 0}};
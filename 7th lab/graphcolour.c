/*
Algorithm
isSafe(graph, colour)
{
    for i = 0 -> n-1
        for j = i+1 -> n-1
            if(graph[i,j]  and  colour[j] == colour[i]) return false
    return true
}

graphcolouring(graph, i, m, colour)
{
    if(i = n)  
        if(isSafe(graph, colour)) return true;
        return false
    for i = 1 -> m-1
        colour[i] = j
        if (graphcolouring(graph, i+1, m, colour)) return true;
        colour[i] = 0
    return false
}


*/

#include <stdio.h> //completed
int n;

int isSafe(int graph[n][n], int colour[])
{
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (graph[i][j] && colour[j] == colour[i])
                return 0;
    return 1;
}

int graphcolouring(int graph[][n], int i, int m, int colour[n])
{
    if (i == n)
    {
        if (isSafe(graph, colour))
            return 1;
        return 0;
    }
    for (int j = 1; j <= m; j++)
    {
        colour[i] = j;
        if (graphcolouring(graph, i + 1, m, colour))
            return 1;
        colour[i] = 0;
    }
    return 0;
}

int main()
{
    printf("Enter the number of vertices : ");
    scanf("%d", &n);
    int graph[n][n];
    printf("enter the corosponding matrix :\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);
    int m;
    printf("enter the number of colour :");
    scanf("%d", &m);
    int colour[n];
    for (int i = 0; i < n; i++)
        colour[i] = 0;
    if (graphcolouring(graph, 0, m, colour))
    {
        printf("Colour of the vertices is : ");
        for (int i = 0; i < n; i++)
            printf("%d ", colour[i]);
        printf("\n");
    }
    else
        printf("Solution does not exist");

    return 0;
}

// { 0, 1, 1, 1 },
// { 1, 0, 1, 0 },
// { 1, 1, 0, 1 },
// { 1, 0, 1, 0 },

// Enter the number of vertices : 4
// enter the corosponding matrix :
// 0 1 1 1
// 1 0 1 0
// 1 1 0 1
// 1 0 1 0
// enter the number of colour :3
// Colour of the vertices is : 1 2 3 2

// I have found somewhere it is O(n*m^n) where n=no vertex and m= number of color.
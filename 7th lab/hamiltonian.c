/*

Algorithm Hamiltonian(k)
{
    do
    {
        NextVertex(k);
        if (x[k] == 0)
            return;
        if (k == n)
            print(x [1:n]);
        if (k != n)
            Hamiltonian(k + 1);
    } while (true);
}

Algorithm NextVertex(k)
(
    do
    {
        x[k] = (x[k]+1)mod(n+1);
        if(x[k]==0) return;
        if(G[x[k-1], x[k]] != 0)
            for j = 0 -> k-1 do if (x[j] == x[k]) break;
            if(j==k)
                if(k<n or (k==n and G[x[n], x[1]] != 0)) return;
    } while (true);
    
)

*/




#include <stdio.h>
int n;
int nextVertex(int graph[][n], int x[n], int k)
{
    do
    {
        x[k] = (x[k] + 1) % (n);
        if (x[k] == 0)
            return 1;
        if (graph[x[k - 1]][x[k]])
        {
            int j = 0;
            for (j = 0; j < k; j++)
            {
                if (x[j] == x[k])
                {
                    break;
                }
            }
            if (j == k)
            {
                if ((k < n - 1) || ((k == n - 1) && (graph[x[n - 1]][x[0]]) != 0))
                {
                    return 1;
                }
            }
        }
    } while (1);
}

int hamiltonian(int graph[][n], int x[n], int k)
{
    do
    {
        nextVertex(graph, x, k);
        if (x[k] == 0)
        {
            return 1;
        }
        if (k == n - 1)
        {
            for (int i = 0; i < n; i++)
                printf("%d -- > ", x[i]);
            printf("0\n");
        }
        if (k != n - 1)
        {
            hamiltonian(graph, x, k + 1);
        }
    } while (1);
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

    int x[n];
    for (int i = 0; i < n; i++)
        x[i] = 0;

    hamiltonian(graph, x, 1);
    return 0;
}

//    0 ----- 1
//    | \     |
//    |   \   |
//    |     \ |
//    2 ----- 3

// Enter the number of vertices : 4
// enter the corosponding matrix :
0 1 1 1
1 0 0 1
1 0 0 1
1 1 1 0
// 0 -- > 1 -- > 3 -- > 2 -- > 0
// 0 -- > 2 -- > 3 -- > 1 -- > 0


// time complexity of the problem is O(n^n)
#include <stdio.h>
#include <limits.h>

int mcm(int p[], int n)
{
    int m[n][n], s[n][n];
    int i, j, k, l, q;
    for (i = 0; i < n; i++)
        m[i][i] = 0;
    for (l = 2; l < n; l++)
    {
        for (i = 1; i < (n - l + 1); i++)
        {
            j = i + l - 1;
            m[i][j] = INT_MAX;
            for (k = i; k < j; k++)
            {
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j])
                {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
   printf("\n\n\n\n");
    for (i = 1; i < n; i++)

    {
        for (j = 1; j < n; j++)

        {
            if (i > j)
            {
                printf("\t");
            }
            else
                printf("%d\t", m[i][j]);
        }

        printf("\n");
    }
    printf("\n\n\n\n");
    for (i = 1; i < n; i++)

    {
        for (j = 1; j < n; j++)

        {
            if (i >= j)
            {
                printf("\t");
            }
            else
                printf("%d\t", s[i][j]);
        }

        printf("\n");
    }

    return m[1][n - 1];
}

int main()
{
    int arr[] = {1,2,3,4};
    int n = 4;

    printf("Dimention of the matrises are ::\n");
    for (int i = 0; i < n - 1; i++)
    {
        printf("%d x %d    ", arr[i], arr[i + 1]);
    }
    printf("\nOptimal cost of the problem = %d\n", mcm(arr, n));
    return 0;
}

// Time Complexity: O(n3 )
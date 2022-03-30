#include <stdio.h>
int n;

int isSafe(int arr[][n], int x, int y)
{
    for (int row = 0; row < x; row++)
    {
        if (arr[row][y] == 1)
        {
            return 0;
        }
    }

    int row = x;
    int col = y;
    while (row >= 0 && col >= 0)
    {
        if (arr[row][col] == 1)
        {
            return 0;
        }
        row--;
        col--;
    }

    row = x;
    col = y;
    while (row >= 0 && col < n)
    {
        if (arr[row][col] == 1)
        {
            return 0;
        }
        row--;
        col++;
    }

    return 1;
}

int nQueen(int arr[][n], int x)
{
    if (x >= n)
    {
        return 1;
    }

    for (int col = 0; col < n; col++)
    {
        if (isSafe(arr, x, col))
        {
            arr[x][col] = 1;
            if (nQueen(arr, x + 1))
            {
                return 1;
            }

            arr[x][col] = 0;  
        }
    }

    return 0;
}

int main()
{
    printf("Enter the value of n : ");
    scanf("%d", &n);
    int board[n][n];
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            board[row][col] = 0;
        }
    }

    if (nQueen(board, 0))
    {
        printf("Positions of %d queen in %d x %d board :\n", n,n,n);
        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < n; col++)
            {
                printf("%d ", board[row][col]);
            }
            printf("\n");
        }
    }
    else
    {
        printf("It is not possible to put %d queen in %d x %d board\n", n, n, n);
    }

    return 0;
}
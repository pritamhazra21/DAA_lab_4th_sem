// The 15 Puzzle consists of 15 squares numbered from 1 to 15 that are placed in a 4 by 4 box with one empty position. The objective of the puzzle is to reposition the squares by sliding them one at a time into a configuration with the numbers in order.


#include <stdio.h>
#define n 4

void swp(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void copyMatrix(int x[n][n], int y[n][n])
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            y[i][j] = x[i][j];
}

int isSolved(int x[n][n], int target[n][n])
{
    int flag = 1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (x[i][j] != target[i][j])
                flag = 0;
    return flag;
}

int notMatched(int x[n][n], int target[n][n])
{
    int count = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (x[i][j] != target[i][j] && x[i][j] != 0)
                count++;
    return count;
}

void fifteenPuzzle(int matrix[n][n])
{
    int fc = 0, cc, cc_min = 0, x, y, gc, tc = 0;
    int temp[n][n], e[n][n];
    int target[n][n] = {{1, 2, 3, 4},
                        {5, 6, 7, 8},
                        {9, 10, 11, 12},
                        {13, 14, 15, 0}};

    printf("\nInitial arrangment\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            (matrix[i][j] == 0) ? (printf("[ ]\t")) : (printf("%d\t", matrix[i][j]));
        }
        printf("\n");
    }

    while (!(isSolved(matrix, target)))
    {
        fc++;
        cc = 9999;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (matrix[i][j] == 0)
                    x = i, y = j;

        // up
        copyMatrix(matrix, temp);
        if (x != 0)
        {
            swp(&temp[x][y], &temp[x - 1][y]);
        }
        gc = notMatched(temp, target);
        cc_min = fc + gc;
        if (cc_min < cc)
        {
            cc = cc_min;
            copyMatrix(temp, e);
        }

        //down
        copyMatrix(matrix, temp);

        if (x != n - 1)
        {
            swp(&temp[x][y], &temp[x + 1][y]);
        }
        gc = notMatched(temp, target);
        cc_min = fc + gc;
        if (cc_min < cc)
        {
            cc = cc_min;
            copyMatrix(temp, e);
        }

        //right
        copyMatrix(matrix, temp);
        if (y != n - 1)
        {
            swp(&temp[x][y], &temp[x][y + 1]);
        }
        gc = notMatched(temp, target);
        cc_min = fc + gc;
        if (cc_min < cc)
        {
            cc = cc_min;
            copyMatrix(temp, e);
        }

        //left
        copyMatrix(matrix, temp);
        if (y != 0)
        {
            swp(&temp[x][y], &temp[x][y - 1]);
        }
        gc = notMatched(temp, target);
        cc_min = fc + gc;
        if (cc_min < cc)
        {
            cc = cc_min;
            copyMatrix(temp, e);
        }

        printf("\nAfter step %d\n", fc);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                (e[i][j] == 0) ? (printf("[ ]\t")) : (printf("%d\t", e[i][j]));
                matrix[i][j] = e[i][j];
            }
            printf("\n");
        }

        printf("Minimum cost for this step = %d\n", cc);
        tc = tc + cc;
    }
    printf("\nThis is the final arrangment.\nTotal cost = %d\n", tc);
}

int main()
{
    int x[n][n];
    printf("Enter the initial value of the tiles : \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &x[i][j]);
        }
    }

    fifteenPuzzle(x);

    return 0;
}

// Enter the initial value of the tiles :
// 1 2 3 4
// 5 6 0 8
// 9 10 7 11
// 13 14 15 12

// After step 1
// 1       2       3       4
// 5       6       7       8
// 9       10      [ ]     11
// 13      14      15      12
// Minimum cost for this step = 3

// After step 2
// 1       2       3       4
// 5       6       7       8
// 9       10      11      [ ]
// 13      14      15      12
// Minimum cost for this step = 3

// After step 3
// 1       2       3       4
// 5       6       7       8
// 9       10      11      12
// 13      14      15      [ ]
// Minimum cost for this step = 3

// This is the final arrangment.
// Total cost = 9
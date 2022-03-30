    printf("\n\n\t\tM values ::::::\n\n");
    for (i = 1; i < n; i++)
    {
        for (j = 1; j < n; j++)
        {
            if (j < i)
            {
                printf("\t");
            }
            else
            {
                printf("%d\t", m[i][j]);
            }
        }
        printf("\n");
    }
    printf("\n\n\t\tS values ::::::\n\n");
    for (i = 1; i < n; i++)
    {
        for (j = 1; j < n; j++)
        {
            if (j <= i)
            {
                printf(" \t");
            }
            else
            {
                printf("%d\t", s[i][j]);
            }
        }
        printf("\n");
    }
//Objective  == traverse the array recursively and by comparing each eliment we can find the maximum as well as minimum value from the array.

#include <stdio.h>
int min(int a, int b) { return (a < b) ? a : b; }
int max(int a, int b) { return (a > b) ? a : b; }
int getMax(int a[], int n)
{
    return (n == 1) ? a[0] : max(a[n - 1], getMax(a, n - 1));
}

int getMin(int a[], int n)
{
    return (n == 1) ? a[0] : min(a[n - 1], getMin(a, n - 1));
}

int main()
{
    int a[50], n, i;
    printf("Number of elements : ");
    scanf("%d", &n);
    printf("Enter array elements:");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("Largest element of the array is %d\n", getMax(a, n));
    printf("Smallest element of the array is %d\n", getMin(a, n));
    return 0;
}

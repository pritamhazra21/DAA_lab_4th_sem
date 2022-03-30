//Objective :- 

//QuickSort is a Divide and Conquer algorithm. It picks an element as pivot and partitions the given array around the picked pivot. This function takes the first element as pivot, places the pivot element at its correct position in sorted array, and places all smaller (smaller than pivot) to left of pivot and all greater elements to right of pivot

//Algorithm:=

/*
partition(a[], l, u)
step 1 = declear the variables v, i, j, temp
spet 2 = set v = a[l]
step 3 = set i = l
step 4 = set j = u+1
step 5 = follow step 6 to step 11 while i < j
step 6 = set i = i+1 while a[i] < v and i <= u
step 7 = set j = j-1 while v < a[j]
step 8 = if i < j follow step 9 to step 11
step 9 = set temp = a[i];
step 10 = set a[i] = a[j];
step 11 = a[j] = temp
step 12 = a[l] = a[j]
step 13 = a[j] = v
step 14 = return j and exit
*/

/*
quick_sort(a[], l, u)
step 1 = declare a variable j
step 2 = if l<u then follow step 3 to step 5
step 3 = i = partition(a,l,u)
step 4 = quick_sort(a, l, j-1)
step 5 = quick_soer(a, j+1, u)
*/


#include <stdio.h>

int partition(int a[], int l, int u)
{
    int v, i, j, temp;
    v = a[l];
    i = l;
    j = u + 1;
    do
    {
        do
            i++;
        while (a[i] < v && i <= u);
        do
            j--;
        while (v < a[j]);
        if (i < j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    } while (i < j);
    a[l] = a[j];
    a[j] = v;
    return (j);
}

void quick_sort(int a[], int l, int u)
{
    int j;
    if (l < u)
    {
        j = partition(a, l, u);
        quick_sort(a, l, j - 1);
        quick_sort(a, j + 1, u);
    }
}

int main()
{
    int a[50], n, i;
    printf("Number of elements : ");
    scanf("%d", &n);
    printf("Enter array elements:");

    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    quick_sort(a, 0, n - 1);
    printf("Array after sorting: ");

    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}

// Output
// Number of elements : 6
// Enter array elements:89 41 2 56 45 12

// time complexity of this program is O(nlogn)

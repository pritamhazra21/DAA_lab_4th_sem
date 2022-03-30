// logic
//     Binary search is an efficient algorithm for finding an item from a sorted list of items. It works by repeatedly dividing in half the portion of the list that could contain the item, until you've narrowed down the possible locations to just one.

//algorithm binarySearch(arr[], l, u, value)
//step 1: if u > = l then follow step 2 to step 5
//step 2: declare a variable mid and set it to (l + (u - l) / 2) 
//step 3: if arr[mid] == value then return mid
//step 4: if arr[mid] > value then return binarySearch(arr, l, mid - 1, value)
//step 5; return binarySearch(arr, mid + 1, u, value)
//step 6: return -1


#include <stdio.h>
int binarySearch(int arr[], int l, int u, int value)
{
    if (u >= l)
    {
        int mid = l + (u - l) / 2;
        if (arr[mid] == value)
            return mid;
        if (arr[mid] > value)
            return binarySearch(arr, l, mid - 1, value);
        return binarySearch(arr, mid + 1, u, value);
    }
    return -1;
}
int main()
{
    int n, value, index;
    printf("Enter the length of the array : ");
    scanf("%d", &n);
    int arr[n];
    printf("Input of array must be sorted\nEnter the value : ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter the value you want to find : ");
    scanf("%d", &value);
    index = binarySearch(arr, 0, n - 1, value);
    (index == -1) ? printf("Element is not present in array")
                  : printf("Element is present at index %d\n", index);
    return 0;
}


// The time complexity of the binary search algorithm is O(log n). The best-case time complexity would be O(1)

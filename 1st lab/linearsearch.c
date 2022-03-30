// logic
//     a linear search or sequential search is a method for finding an element within a list. It sequentially checks each element of the list until a match is found or the whole list has been searched.
//     hare we take two point 1st element and last element ar traverse from both side until two point crossed each other

// linearSearch(int arr[], int value, int l, int u)
// step 1 : if l > u then return -1
// step 2 : if value == arr[l] then return l
// step 3 : if value == arr[u] then return u
// step 4 : return linearSearch(arr, value, l + 1, u - 1)

#include <stdio.h>
int linearSearch(int arr[], int value, int l, int u)
{
    if (l > u)
        return -1;
    if (value == arr[l])
        return l;
    if (value == arr[u])
        return u;
    return linearSearch(arr, value, l + 1, u - 1);
}
int main()
{
    int n, value, index;
    printf("Enter the length of the array : ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the value : ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter the value you want to find : ");
    scanf("%d", &value);
    index = linearSearch(arr, value, 0, n - 1);
    (index == -1) ? printf("Element is not present in array")
                  : printf("Element is present at index %d\n", index);
    return 0;
}


// Linear search has a time complexity of O(n)
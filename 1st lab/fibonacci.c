// logic
//     In case of fibonacci series, next number is the sum of previous two numbers for example 0, 1, 1, 2, 3, 5, 8, 13, 21 etc. The first two numbers of fibonacci series are 0 and 1.

//Fibonacci(int n)
// step 1 : if n == 0 then return 0
// step 2 : if n == 1 then return 1
// step 3 : return Fibonacci(n - 1) + Fibonacci(n - 2))


#include <stdio.h>
int Fibonacci(int n)
{
    return (n == 0) ? 0 
                    : ((n == 1) ? 1 
                                : Fibonacci(n - 1) + Fibonacci(n - 2));
}
int main()
{
    int n;
    printf("Enter the value for term number : ");
    scanf("%d", &n);
    printf("Fibonacci Series is : ");
    for (int i = 1; i <= n; i++)
        printf("%d ", Fibonacci(i));
    return 0;
}


// the time taken by recursive Fibonacci is O(2^n) or exponential.
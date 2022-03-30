// logic
//     factorial means the product of an integer and all the integers below it
//     so in this funtion called itself with the parameter with decrementimg 1 and multiply this with the parameter
//     and in the base case the value of parameter will be 1
//     by doing this the funtion called itself in recurcive manner till the decrementing value reach 1 


// algorithm of factorial( a)
// step 1: if a == 0 or a == 1 then return 1
// step 2: return a * factorial(a - 1)


#include <stdio.h>
int factorial(int a)
{
    return (a == 0 || a == 1) ? 1 : a * factorial(a - 1);
}
int main()
{
    int n;
    printf("Enter the value : ");
    scanf("%d", &n);
    printf("Factorial = %d\n", factorial(n));
    return 0;
}

// The time complexity of recursive factorial is O(n).
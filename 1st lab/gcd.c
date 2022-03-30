// logic
//     the common logic to find gcd is we first divide the greater number by the smaller number. The remainder becomes the new divisor and the previous divisor as the new dividend. We continue the process until we get 0 remainder.


// algorithm of gcd(int x, int y)
// step 1 : if x == 0 then return y
// step 2 : if x < y then return gcd(y, x)
// step 3 : return gcd( x%y, y)


#include <stdio.h>
int gcd(int x, int y)
{
    return (x == 0) ? y
                    : ((x < y) ? gcd(y, x)
                               : gcd(x % y, y));
}
int main()
{
    int a, b;
    printf("Enter the value for a and b : ");
    scanf("%d%d", &a, &b);
    printf("GCD of two numbers is : %d\n", gcd(a, b));
    return 0;
}

// time complexity is O(log n)
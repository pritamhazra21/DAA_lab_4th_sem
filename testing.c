#include <stdio.h>

// int setbit(int a)
// {
//     unsigned int count = 0;
//     while (a)
//     {
//         count += a & 1;
//         a >>= 1;
//     }
//     return count;
// }

int main()
{
    int a = 3;
    if(a&1)
    {
        printf("Done\n");
    }
    return 0;
}
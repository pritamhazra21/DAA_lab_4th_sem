// Name - Pritam Hazra
// Roll - CSE/19/009

#include <stdio.h>

void hanoi(int disk, char source, char dest, char aux)
{
    if (disk == 1)
    {
        printf("move disk %d, %c to %c\n", disk, source, dest);
        return;
    }
    hanoi(disk - 1, source, aux, dest);
    printf("move disk %d, %c to %c\n", disk, source, dest);
    hanoi(disk - 1, aux, dest, source);
}

int main()
{
    printf("\n\tPritam Hazra\n\tCSE/19/009\n\n");
    int n = 3; 
    hanoi(n, 'A', 'C', 'B'); 
    return 0;
}


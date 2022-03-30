//objective :-

//  tower of hanoi is a mathematical puzzle which consists of three towers (pegs) and more than one rings is as depicted. These rings are of different sizes and stacked upon in an ascending order, i.e. the smaller one sits over the larger one. The task is to move all the disks to some another tower without violating the sequence of arrangement.

//Algorithm
/*

hanoi(disk, source, dest, aux)

step 1 = if disk = 1 then print "source" to "dest" and return
step 2 = hanoi(disk - 1, source, aux, dest)
step 3 = print "source" to "dest"
step 4 = hanoi(disk - 1, aux, dest, source);

*/

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
    int n = 3; 
    hanoi(n, 'A', 'C', 'B'); 
    return 0;
}


/*
Output

move disk 1, A to C
move disk 2, A to B
move disk 1, C to B
move disk 3, A to C
move disk 1, B to A
move disk 2, B to C
move disk 1, A to C
*/

// time complexity of this program is O(2^n)
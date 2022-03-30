// The sequencing of jobs on a single processor with deadline constraints is called as Job Sequencing with Deadlines. You are given a set of jobs. Each job has a defined deadline and some profit associated with it. The profit of a job is given only when that job is completed within its deadline.



// for i = 1 to n do
//   Set k = min(dmax, DEADLINE(i))  //where DEADLINE(i) denotes deadline of ith job

//   while k >= 1 do
//     if timeslot[k] is EMPTY then
//       timeslot[k] = job(i)
//       break
//     endif

//     Set k = k - 1

//   endwhile

// endfor


#include <stdio.h>
typedef struct Job
{
    char id[5];
    int deadline;
    int profit;
} Job;

int minValue(int x, int y)
{
    return (x < y) ? x : y;
}

void jobSequencingWithDeadline(Job jobs[], int n)
{
    int i, j, k, maxprofit;
    int timeslot[100];
    int filledTimeSlot = 0;

    int dmax = 0;
    for (i = 0; i < n; i++)
    {
        if (jobs[i].deadline > dmax)
            dmax = jobs[i].deadline;
    }

    for (i = 1; i <= dmax; i++)
        timeslot[i] = -1;
    
    printf("\ndmax: %d\n", dmax);

    for (i = 1; i <= n; i++)
    {
        k = minValue(dmax, jobs[i - 1].deadline);
        while (k >= 1)
        {
            if (timeslot[k] == -1)
            {
                timeslot[k] = i - 1;
                filledTimeSlot++;
                break;
            }
            k--;
        }

        if (filledTimeSlot == dmax)
            break;    
    }

    printf("\nRequired Jobs: ");
    for (i = 1; i <= dmax; i++)
    {
        printf("%s", jobs[timeslot[i]].id);
        if (i < dmax)
            printf(" --> ");
    }

    maxprofit = 0;
    for (i = 1; i <= dmax; i++)
        maxprofit += jobs[timeslot[i]].profit;
    printf("\nMax Profit: %d\n", maxprofit);
}

int main(void)
{
    Job jobs[5] = {
        {"j1", 2, 60},
        {"j2", 1, 100},
        {"j3", 3, 20},
        {"j4", 2, 40},
        {"j5", 1, 20},
    };
    Job temp;
    int n = 5;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            if (jobs[j + 1].profit > jobs[j].profit)
            {
                temp = jobs[j + 1];
                jobs[j + 1] = jobs[j];
                jobs[j] = temp;
            }
        }
    }

    printf("%10s %10s %10s\n", "Job", "Deadline", "Profit");
    for (int i = 0; i < n; i++)
        printf("%10s %10d %10d\n", jobs[i].id, jobs[i].deadline, jobs[i].profit);
    
    jobSequencingWithDeadline(jobs, n);
    return 0;
}


// 1. sort job according to decresing order of deadline =  O(nlogn)

// 2. for each job find slot in array of size n = O(n^2)

// total time  = O(nlogn) + O(n^2) =O(n^2)
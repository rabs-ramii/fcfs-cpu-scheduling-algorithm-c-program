// c-program for fcfs cpu scheduling algorithm
#include <stdio.h>
void main()
{
    int i, n, j = 1, min, temp;
    float avgtat = 0, avgwt = 0;
    printf("enter total numbers of processes: "); // taking total processes from user
    scanf("%d", &n);
    int p[n], at[n], bt[n], ct[n], tat[n], wt[n];
    printf("\nEnter  process,it's arrival time and it's burst time:\n");
    for (i = 0; i < n; i++)
    {

        scanf("%d%d%d", &p[i], &at[i], &bt[i]);
    }
    // sorting the process burst time on the basis of arrival time
    for (i = 0; i < n; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            if (at[j] < at[min])
            {
                min = j;
            }
            if (at[min] == at[j]) // arranging process and burst time of two processes which have same arrival time on the basis of process id
            {
                if (p[min] > p[j]) // checking which process comes first and put it on first
                {
                    temp = p[j];
                    p[j] = p[min];
                    p[min] = temp;

                    temp = bt[j]; // aranging burst time according to process
                    bt[j] = bt[min];
                    bt[min] = temp;
                    goto loop;
                }
            }
        }

        if (min != i)
        {
            temp = at[min];
            at[min] = at[i];
            at[i] = temp;

            temp = p[min];
            p[min] = p[i];
            p[i] = temp;

            temp = bt[min];
            bt[min] = bt[i];
            bt[i] = temp;
        }
    loop:
        continue;
    } // sorting of process and burst time ends here
    // calculation of CT TAT WT avgtat and avgwt starts here
    ct[-1] = 0;
    for (i = 0; i < n; i++)
    {
        ct[i] = ct[i - 1] + bt[i];
        if (ct[i - 1] < at[i])
        {
            temp = at[i] - ct[i - 1];
            ct[i] = ct[i] + temp;
        }
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        avgtat = avgtat + tat[i];
        avgwt = avgwt + wt[i];
    } // calculation of CT TAT WT and avgtat and avgwt ends here
    // Arranging arrival time burst time CT TAT WT on the basis of process id
    for (i = 0; i < n; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            if (p[j] <= p[min])
            {
                min = j;
            }
        }

        if (min != i)
        {
            temp = p[min]; // arranging process id
            p[min] = p[i];
            p[i] = temp;

            temp = at[min]; // arranging arrival time
            at[min] = at[i];
            at[i] = temp;

            temp = bt[min]; // arrnaging burst time
            bt[min] = bt[i];
            bt[i] = temp;

            temp = ct[min]; // arranging completion time
            ct[min] = ct[i];
            ct[i] = temp;

            temp = tat[min]; // arranging turnaround time
            tat[min] = tat[i];
            tat[i] = temp;

            temp = wt[min]; // arranging waiting time
            wt[min] = wt[i];
            wt[i] = temp;
        }
    } // Arranging arrival time burst time CT TAT WT on the basis of process id ends here
    // displaying results starts here
    printf("===============================================\n");
    printf("Process id\t|\tAT\t|\tBT\t|\tCT\t|\tTAT\t|\tWAT\t|\n");
    for (i = 0; i < n; i++)
    {
        printf("\t%d\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t|", p[i], at[i], bt[i], ct[i], tat[i], wt[i]);
        printf("\n");
    }
    printf("\nAverage Turn Around Time = %.2f", avgtat / n);
    printf("\nAverage Waiting Time = %.2f", avgwt / n);
    // displaying results ends here
}
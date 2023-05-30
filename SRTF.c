#include <stdio.h>

int main()
{
    int n;
    printf("\ Enter the number of P: ");
    scanf("%d", &n);
    int proc[n + 1][4];

    for (int i = 1; i <= n; i++)
    {
        printf(" Enter the Arrival P%d: ", i);
        scanf("%d", &proc[i][0]);
        printf(" Enter the Burst Time P%d: ", i);
        scanf("%d", &proc[i][1]);
    }

    printf("\n");

    int total_time = 0;
    for (int i = 1; i <= n; i++)
    {
        total_time += proc[i][1];
    }

    int time_chart[total_time];
    char process_chart[total_time][5];

    for (int i = 0; i < total_time; i++)
    {
        int sel_proc = 0;
        int min = 99999;

        for (int j = 1; j <= n; j++)
        {
            if (proc[j][0] <= i)
            {
                if (proc[j][1] < min && proc[j][1] != 0)
                {
                    min = proc[j][1];
                    sel_proc = j;
                }
            }
        }

        time_chart[i] = sel_proc;
        proc[sel_proc][1]--;
        process_chart[i][0] = 'P';
        process_chart[i][1] = sel_proc + '0';
        process_chart[i][2] = ' ';
        process_chart[i][3] = ' ';
        process_chart[i][4] = '\0';

        for (int j = 1; j <= n; j++)
        {
            if (proc[j][0] <= i)
            {
                if (proc[j][1] != 0)
                {
                    proc[j][3]++;
                    if (j != sel_proc)
                    {
                        proc[j][2]++;
                    }
                }
                else if (j == sel_proc)
                {
                    proc[j][3]++;
                }
            }
        }
    }

    printf("\nGantt Chart:\n");
    printf("---------------------------------------------------\n");
    printf("|");
    for (int i = 0; i < total_time; i++)
    {
        printf("%s|", process_chart[i]);
    }

    printf("\n");

    // Printing the average WT & TT
    float WT = 0, TT = 0;
    for (int i = 1; i <= n; i++)
    {
        WT += proc[i][2];
        TT += proc[i][3];
    }
    WT /= n;
    TT /= n;
    printf("The Average WT is: %.2f\n", WT);
    printf("The Average TT is: %.2f\n", TT);
}

#include <stdio.h>
#include <stdlib.h>
#define MAX(a,b) ((a) > (b) ? (a) : (b))

struct Process {
    int pid;
    int arrival;
    int burst;
};

int compare(const void *arg1, const void *arg2) {
    Process *p1 = (Process *)arg1;
    Process *p2 = (Process *)arg2;

    if (p1->arrival > p2->arrival) return 1;
    if (p1->arrival < p2->arrival) return -1;
    return 0;
}

int main() {
    Process p[10];
    int star[10], finish[10], tat[10], wt[10], i, n;
    float totwt = 0, tottat = 0;
    printf("Enter the number of process:");
    scanf_s("%d", &n);

    for (i = 0; i<n; i++) {
        printf("Enter the Process Name, Arrival Time & Burst Time:");
        scanf_s("%d%d%d", &p[i].pid, &p[i].arrival, &p[i].burst);
    }

    qsort(p, n, sizeof(Process), compare);
    for (i = 0; i<n; i++) {
        if (i == 0) {
            star[i] = p[i].arrival;
        }
        else {
            star[i] = MAX(finish[i-1], p[i].arrival);
        }
        wt[i] = star[i] - p[i].arrival;
        finish[i] = star[i] + p[i].burst;
        tat[i] = finish[i] - p[i].arrival;
    }

    printf("\n%-6s%-8s%-8s%-6s%-6s%-6s\n", "PName", "Arrtime", "Burtime", "Start", "TAT", "Finish");
    for (i = 0; i<n; i++) {
        printf("%-6d%-8d%-8d%-6d%-6d%-6d\n", p[i].pid, p[i].arrival, p[i].burst, star[i], tat[i], finish[i]);
        totwt += wt[i];
        tottat += tat[i];
    }
    printf("Avg waiting: %.2f\nAvg turnaround: %.2f", totwt/n, tottat/n);

    return 0;
}
#include <stdio.h>

struct Process {
    int id;
    int at;        // Arrival Time
    int bt;        // Burst Time
    int pr;        // Priority (lower = higher priority)
    int remaining; // Remaining Burst Time
    int wt;        // Waiting Time
    int tt;        // Turnaround Time
    int completed;
    int ct;        // Completion Time
};

int main() {
    struct Process p[10];
    int n, completed = 0, currentTime = 0;
    float totalWT = 0, totalTT = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter Arrival Time, Burst Time and Priority for each process:\n");
    for (int i = 0; i < n; i++) {
        p[i].id = i + 1;
        p[i].completed = 0;
        printf("Process P%d (AT BT Priority): ", i + 1);
        scanf("%d %d %d", &p[i].at, &p[i].bt, &p[i].pr);
        p[i].remaining = p[i].bt;
    }

    while (completed < n) {
        int idx = -1;
        int highestPriority = 9999;

        // Pick the arrived, incomplete process with highest priority (lowest pr value)
        for (int i = 0; i < n; i++) {
            if (p[i].at <= currentTime && !p[i].completed) {
                if (p[i].pr < highestPriority ||
                   (p[i].pr == highestPriority && idx != -1 && p[i].at < p[idx].at)) {
                    highestPriority = p[i].pr;
                    idx = i;
                }
            }
        }

        if (idx != -1) {
            // Run the selected process for 1 unit (preemptive)
            p[idx].remaining--;
            currentTime++;

            if (p[idx].remaining == 0) {
                p[idx].ct = currentTime;
                p[idx].tt = p[idx].ct - p[idx].at;
                p[idx].wt = p[idx].tt - p[idx].bt;
                p[idx].completed = 1;
                totalWT += p[idx].wt;
                totalTT += p[idx].tt;
                completed++;
            }
        } else {
            // CPU idle — jump to the next process arrival
            int nextAT = 99999;
            for (int i = 0; i < n; i++) {
                if (!p[i].completed && p[i].at > currentTime && p[i].at < nextAT)
                    nextAT = p[i].at;
            }
            currentTime = nextAT;
        }
    }

    printf("\nProcess\tAT\tBT\tPriority\tFT\tTT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t\t%d\t%d\t%d\n",
               p[i].id, p[i].at, p[i].bt, p[i].pr,
               p[i].ct, p[i].tt, p[i].wt);
    }

    printf("\nAverage Waiting Time    : %.2f\n", totalWT / n);
    printf("Average Turnaround Time : %.2f\n", totalTT / n);

    return 0;
}
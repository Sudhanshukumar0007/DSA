#include <stdio.h>

struct Process {
    int id;     // Process ID
    int at;     // Arrival Time
    int bt;     // Burst Time
    int pr;     // Priority (lower value = higher priority)
    int wt;     // Waiting Time
    int tt;     // Turnaround Time
    int completed; // Flag to indicate if process is completed
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
    }

    while (completed < n) {
        int idx = -1;
        int highestPriority = 9999;

        for (int i = 0; i < n; i++) {
            if (p[i].at <= currentTime && !p[i].completed) {
                if (p[i].pr < highestPriority || (p[i].pr == highestPriority && p[i].at < p[idx].at)) {
                    highestPriority = p[i].pr;
                    idx = i;
                }
            }
        }

        if (idx != -1) {
            // Process selected
            currentTime = currentTime < p[idx].at ? p[idx].at : currentTime;
            currentTime += p[idx].bt;
            p[idx].tt = currentTime - p[idx].at;
            p[idx].wt = p[idx].tt - p[idx].bt;
            p[idx].completed = 1;
            totalWT += p[idx].wt;
            totalTT += p[idx].tt;
            completed++;
        } else {
            // No process is ready to execute
            currentTime++;
        }
    }

    // Output
    printf("\nProcess\tAT\tBT\tPriority\tTT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t\t%d\t%d\n", p[i].id, p[i].at, p[i].bt, p[i].pr, p[i].tt, p[i].wt);
    }

    printf("\nAverage Waiting Time: %.2f\n", totalWT / n);
    printf("Average Turnaround Time: %.2f\n", totalTT / n);

    return 0;
}
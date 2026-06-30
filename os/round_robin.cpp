#include <stdio.h>

struct Process {
    int id;
    int at;        // Arrival Time
    int bt;        // Burst Time
    int remaining; // Remaining Burst Time
    int wt;        // Waiting Time
    int tt;        // Turnaround Time
    int ft;        // Finish Time
    int inQueue;   // Whether added to ready queue
};

int main() {
    struct Process p[10];
    int n, completed = 0, currentTime = 0, quantum;
    float totalWT = 0, totalTT = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter time quantum: ");
    scanf("%d", &quantum);

    printf("Enter Arrival Time and Burst Time for each process:\n");
    for (int i = 0; i < n; i++) {
        p[i].id = i + 1;
        p[i].inQueue = 0;
        printf("Process P%d (AT BT): ", i + 1);
        scanf("%d %d", &p[i].at, &p[i].bt);
        p[i].remaining = p[i].bt;
    }

    // Simple circular queue using an array
    int queue[100], front = 0, rear = 0;

    // Enqueue processes that arrive at time 0
    for (int i = 0; i < n; i++) {
        if (p[i].at == 0) {
            queue[rear++] = i;
            p[i].inQueue = 1;
        }
    }

    while (completed < n) {
        if (front == rear) {
            // Queue empty — advance time to next arrival
            int nextAT = 99999;
            for (int i = 0; i < n; i++) {
                if (!p[i].inQueue && p[i].remaining > 0 && p[i].at < nextAT)
                    nextAT = p[i].at;
            }
            currentTime = nextAT;

            // Enqueue newly arrived processes
            for (int i = 0; i < n; i++) {
                if (!p[i].inQueue && p[i].at <= currentTime && p[i].remaining > 0) {
                    queue[rear++] = i;
                    p[i].inQueue = 1;
                }
            }
            continue;
        }

        int idx = queue[front++]; // Dequeue

        // CPU may be idle before this process starts
        if (currentTime < p[idx].at)
            currentTime = p[idx].at;

        // Run for min(quantum, remaining)
        int runTime = (p[idx].remaining < quantum) ? p[idx].remaining : quantum;
        p[idx].remaining -= runTime;
        currentTime += runTime;

        // Enqueue processes that arrived during this slice (excluding current)
        for (int i = 0; i < n; i++) {
            if (!p[i].inQueue && p[i].at <= currentTime && p[i].remaining > 0) {
                queue[rear++] = i;
                p[i].inQueue = 1;
            }
        }

        if (p[idx].remaining == 0) {
            // Process finished
            p[idx].ft = currentTime;
            p[idx].tt = p[idx].ft - p[idx].at;
            p[idx].wt = p[idx].tt - p[idx].bt;
            totalWT += p[idx].wt;
            totalTT += p[idx].tt;
            completed++;
        } else {
            // Re-enqueue unfinished process
            queue[rear++] = idx;
        }
    }

    printf("\nProcess\tAT\tBT\tFT\tTT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i].id, p[i].at, p[i].bt,
               p[i].ft, p[i].tt, p[i].wt);
    }

    printf("\nAverage Waiting Time    : %.2f\n", totalWT / n);
    printf("Average Turnaround Time : %.2f\n", totalTT / n);

    return 0;
}
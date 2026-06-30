#include <iostream>
#include <vector>
using namespace std;

struct Process {
    int pid;
    int arrival;
    int burst;
    int remaining;
    int completion;
    int waiting;
    int turnaround;
};

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    vector<Process> p(n);

    for(int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        cout << "Enter Arrival Time for P" << i+1 << ": ";
        cin >> p[i].arrival;
        cout << "Enter Burst Time for P" << i+1 << ": ";
        cin >> p[i].burst;
        p[i].remaining = p[i].burst;
    }

    int completed = 0, currentTime = 0;

    while(completed < n) {
        int idx = -1;
        int minRemaining = 1e9;

        for(int i = 0; i < n; i++) {
            if(p[i].arrival <= currentTime && p[i].remaining > 0) {
                if(p[i].remaining < minRemaining) {
                    minRemaining = p[i].remaining;
                    idx = i;
                }
            }
        }

        if(idx != -1) {
            p[idx].remaining--;
            currentTime++;

            if(p[idx].remaining == 0) {
                completed++;
                p[idx].completion = currentTime;
                p[idx].turnaround = p[idx].completion - p[idx].arrival;
                p[idx].waiting = p[idx].turnaround - p[idx].burst;
            }
        } else {
            currentTime++; // CPU Idle
        }
    }

    float totalWT = 0, totalTAT = 0;

    cout << "\nPID\tAT\tBT\tCT\tWT\tTAT\n";
    for(auto proc : p) {
        totalWT += proc.waiting;
        totalTAT += proc.turnaround;

        cout << "P" << proc.pid << "\t"
             << proc.arrival << "\t"
             << proc.burst << "\t"
             << proc.completion << "\t"
             << proc.waiting << "\t"
             << proc.turnaround << endl;
    }

    cout << "\nAverage Waiting Time: " << totalWT/n;
    cout << "\nAverage Turnaround Time: " << totalTAT/n;

    return 0;
}
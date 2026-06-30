#include <iostream>
#include <vector>
using namespace std;

struct Process {
    int pid;
    int arrival;
    int burst;
    int completion;
    int waiting;
    int turnaround;
    bool completed = false;
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
    }

    int completed = 0, currentTime = 0;

    while(completed < n) {
        int idx = -1;
        int minBurst = 1e9;

        for(int i = 0; i < n; i++) {
            if(p[i].arrival <= currentTime && !p[i].completed) {
                if(p[i].burst < minBurst) {
                    minBurst = p[i].burst;
                    idx = i;
                }
            }
        }

        if(idx != -1) {
            currentTime += p[idx].burst;
            p[idx].completion = currentTime;
            p[idx].turnaround = p[idx].completion - p[idx].arrival;
            p[idx].waiting = p[idx].turnaround - p[idx].burst;
            p[idx].completed = true;
            completed++;
        } else {
            currentTime++; 
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
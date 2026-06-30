#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Process {
    int pid;
    int arrival;
    int burst;
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
    }

    // Sort processes by arrival time
    sort(p.begin(), p.end(), [](Process a, Process b) {
        return a.arrival < b.arrival;
    });

    int currentTime = 0;

    for(int i = 0; i < n; i++) {

        // If CPU is idle
        if(currentTime < p[i].arrival) {
            currentTime = p[i].arrival;
        }

        p[i].completion = currentTime + p[i].burst;
        p[i].turnaround = p[i].completion - p[i].arrival;
        p[i].waiting = p[i].turnaround - p[i].burst;

        currentTime = p[i].completion;
    }

    float totalWT = 0, totalTAT = 0;

    cout << "\nPID\tAT\tBT\tCT\tWT\tTAT\n";

    for(int i = 0; i < n; i++) {
        totalWT += p[i].waiting;
        totalTAT += p[i].turnaround;

        cout << "P" << p[i].pid << "\t"
             << p[i].arrival << "\t"
             << p[i].burst << "\t"
             << p[i].completion << "\t"
             << p[i].waiting << "\t"
             << p[i].turnaround << endl;
    }

    cout << "\nAverage Waiting Time: " << totalWT/n;
    cout << "\nAverage Turnaround Time: " << totalTAT/n;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define MAX 30

int main() {
    int n, i, qt, sq = 0, temp, count = 0;
    cout << "Enter number of processes: ";
    if (!(cin >> n)) return 0;

    int bt[MAX], wt[MAX], tat[MAX], rem_bt[MAX];
    float awt = 0, atat = 0;

    cout << "Enter burst times: ";
    for (i = 0; i < n; i++) {
        cin >> bt[i];
        rem_bt[i] = bt[i]; // Fixed scoping here
    }

    cout << "Enter quantum time: ";
    cin >> qt;

    while (true) {
        bool done = true; // Use a flag to track if all processes are finished
        for (i = 0; i < n; i++) {
            if (rem_bt[i] > 0) {
                done = false; // There is still a pending process
                if (rem_bt[i] > qt) {
                    sq += qt;
                    rem_bt[i] -= qt;
                } else { // rem_bt[i] >= 0
                    sq += rem_bt[i];
                    tat[i] = sq; // TAT is recorded only when process finishes
                    rem_bt[i] = 0;
                }
            }
        }
        if (done) break;
    }

    cout << "\nProcess\t Burst Time\t Waiting Time\t Turn Around Time\n";
    for (i = 0; i < n; i++) {
        wt[i] = tat[i] - bt[i];
        awt += wt[i];
        atat += tat[i];
        cout << i + 1 << "\t\t" << bt[i] << "\t\t" << wt[i] << "\t\t" << tat[i] << endl;
    }

    cout << fixed << setprecision(2); // For cleaner output
    cout << "\nAverage waiting time: " << awt / n << endl;
    cout << "Average turn around time: " << atat / n << endl;

    return 0;
}
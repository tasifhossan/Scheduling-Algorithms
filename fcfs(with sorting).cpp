#include <iostream>

using namespace std;

#define MAX 30

int main() {
    int pid[MAX], bt[MAX], at[MAX], wt[MAX], tat[MAX], ct[MAX];
    int n;
    float awt = 0, atat = 0;

    cout << "Enter the number of processes: ";
    cin >> n;

    // Reading inputs and initializing Process IDs
    for(int i = 0; i < n; i++) {
        pid[i] = i + 1; // Assign Process ID: 1, 2, 3...
        cout << "Process " << pid[i] << " Arrival Time: ";
        cin >> at[i];
        cout << "Process " << pid[i] << " Burst Time: ";
        cin >> bt[i];
    }

    // --- SORTING PROCESSES BY ARRIVAL TIME (Bubble Sort) ---
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(at[j] > at[j+1]) {
                // Swap Arrival Time
                int temp = at[j];
                at[j] = at[j+1];
                at[j+1] = temp;

                // Swap Burst Time
                temp = bt[j];
                bt[j] = bt[j+1];
                bt[j+1] = temp;

                // Swap Process ID (so we remember who is who)
                temp = pid[j];
                pid[j] = pid[j+1];
                pid[j+1] = temp;
            }
        }
    }

    // --- CALCULATING TIMES ---
    int currentTime = 0; // Tracks the current time on the CPU clock

    for(int i = 0; i < n; i++) {
        // IDLE TIME CHECK: If the CPU is idle before this process arrives
        if (currentTime < at[i]) {
            currentTime = at[i]; 
        }

        // Completion Time = Current Time + Burst Time
        ct[i] = currentTime + bt[i];
        
        // Update Current Time for the next process
        currentTime = ct[i];

        // Turnaround Time = Completion Time - Arrival Time
        tat[i] = ct[i] - at[i];
        
        // Waiting Time = Turnaround Time - Burst Time
        wt[i] = tat[i] - bt[i];
        
        awt += wt[i];
        atat += tat[i];
    }

    // --- PRINTING RESULTS ---
    cout << "\nPID\t Arrival\t Burst\t\t Completion\t Waiting\t Turnaround\n";
    for(int i = 0; i < n; i++) {
        cout << pid[i] << "\t " << at[i] << "\t\t " << bt[i] << "\t\t " 
             << ct[i] << "\t\t " << wt[i] << "\t\t " << tat[i] << "\n";
    }

    awt = awt / n;
    atat = atat / n;

    cout << "\nAverage waiting time: " << awt << "\n";
    cout << "Average turn around time: " << atat << "\n";

    return 0;
}
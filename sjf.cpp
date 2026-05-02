/* sjf scheduling without arrival time
n:  number of processes.
t: A temporary variable for swap.
SJF algorithm work:
shob process k ascending burst times e sort korbo
Schedule the process with the shortest burst time next.
Repeat steps 1 and 2 until all the processes have been scheduled
 */
#include <iostream>

using namespace std;

#define MAX 30

int main() {
    int i, j, n, t;
    // Arrays initialized to 0 for safety
    int p[MAX] = {0}, bt[MAX] = {0}, wt[MAX] = {0}, tat[MAX] = {0}; 
    float awt = 0, atat = 0;

    cout << "Enter the number of processes: ";
    cin >> n;

    cout << "Enter the process numbers:\n";
    for(i = 0; i < n; i++) {
        cin >> p[i];
    }

    cout << "Enter the burst time of the processes:\n";
    for(i = 0; i < n; i++) {
        cin >> bt[i];
    }

    /*
     bubble sort algorithm use korbo shortest burst time er shb process gula 
     sort hbe first scheduled hoye
     */
    for(i = 0; i < n; i++) {
        for(j = 0; j < n - i - 1; j++) {
            if(bt[j] > bt[j+1]) {
                // Swap burst time
                t = bt[j];
                bt[j] = bt[j+1];
                bt[j+1] = t;
                
                // Swap process ID to keep them aligned
                t = p[j];
                p[j] = p[j+1];
                p[j+1] = t;
            }
        }
    }

    // calculation hobe
    cout << "\nProcess\t Burst Time\t Waiting Time\t Turn Around Time\n";
    for(i = 0; i < n; i++) {
        wt[i] = 0;
        tat[i] = 0;
        
        // Calculate waiting time
        for(j = 0; j < i; j++) {
            wt[i] = wt[i] + bt[j];
        }
        
        // Calculate turnaround time
        tat[i] = wt[i] + bt[i];
        
        awt = awt + wt[i];
        atat = atat + tat[i];
        
        cout << p[i] << "\t\t " << bt[i] << "\t\t " << wt[i] << "\t\t " << tat[i] << endl;
    }
    
    awt = awt / n;
    atat = atat / n;
    
    cout << "\nAverage waiting time: " << awt << endl;
    cout << "Average turn around time: " << atat << endl;

    return 0;
}
#include <iostream>

using namespace std;

int main() {
    // Initialized arrays to 0 for safety
    int p[20] = {0}, bt[20] = {0}, pr[20] = {0}, wt[20] = {0}, tat[20] = {0};
    int i, j, n, pos, temp;
    
    // Changed to float to prevent integer division when calculating averages
    float total = 0, avg_wt, avg_tat; 

    cout << "Enter Total Number of Process: ";
    cin >> n;

    cout << "\nEnter Burst Time and Priority\n";
    for(i = 0; i < n; i++) {
        cout << "\nP[" << i + 1 << "]\n";
        cout << "Burst Time: ";
        cin >> bt[i];
        cout << "Priority: ";
        cin >> pr[i];
        p[i] = i + 1;  // contains process number
    }

    // ascending order e sort korbo burst time, priority and process number
    // (Using Selection Sort)
    for(i = 0; i < n; i++) {
        pos = i;
        for(j = i + 1; j < n; j++) {
            if(pr[j] < pr[pos]) { // current priority j jodi i theke choto hoi
                pos = j;
            }
        }
        
        // jodi priority position change true hoi swap korbo
        temp = pr[i];
        pr[i] = pr[pos];
        pr[pos] = temp; 
        
        // samevabe brust time swap
        temp = bt[i];
        bt[i] = bt[pos];
        bt[pos] = temp; 
        
        // process position swap korbo
        temp = p[i];
        p[i] = p[pos];
        p[pos] = temp; 
    }

    wt[0] = 0; // first process er waiting time zero
    
    // waiting time calculation
    for(i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1]; // Optimized waiting time calculation
        total += wt[i];
    }
    
    avg_wt = total / n;
    total = 0; // Reset total to use for turnaround time
    
    cout << "\nProcess\t Burst Time\t Priority\t Waiting Time\t Turnaround Time\n";
    
    for(i = 0; i < n; i++) { // calculate turnaround time
        tat[i] = bt[i] + wt[i];
        total += tat[i];
        
        cout << "P[" << p[i] << "]\t\t " << bt[i] << "\t\t " << pr[i] 
             << "\t\t " << wt[i] << "\t\t " << tat[i] << "\n";
    }
    
    avg_tat = total / n;
    
    cout << "\nAverage Waiting Time = " << avg_wt << "\n";
    cout << "Average Turnaround Time = " << avg_tat << "\n";

    return 0;
}
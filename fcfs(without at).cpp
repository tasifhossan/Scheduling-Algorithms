#include <bits/stdc++.h>
using namespace std;

#define MAX 30


int main(){
    
    int n;
    cin>>n;
    
    int bt[n], wt[n], tat[n];
    
    float awt = 0, atat = 0;
    
    for(int i = 0; i<n; i++) cin>>bt[i];
    
    cout<< "Process\t Burst Time\t Waiting Time\t Turn Around Time\n";
    
    for(int i = 0; i<n; i++){
        if(i > 0) wt[i] = wt[i-1] + bt[i-1];
        else wt[i] = 0;
        
        tat[i] = wt[i] + bt[i];
        
        cout<< i + 1<< "\t\t" << bt[i] << "\t\t" << wt[i] <<  "\t\t" << tat[i]<<endl;
        
        awt += wt[i];
        atat += tat[i];
        
    }
    
    awt = awt / n;
    atat = atat / n;
    cout << "\nAverage waiting time: " << awt << endl;
    cout << "Average turn around time: " << atat << endl;
    
    return 0;
}

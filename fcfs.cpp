#include <bits/stdc++.h>
using namespace std;

#define MAX 30


int main(){
    
    int n;
    cin>>n;
    
    int at[MAX], bt[MAX], wt[MAX], tat[MAX], temp[MAX];
    
    float awt = 0, atat = 0;
    
    for(int i = 0; i<n; i++) cin>>bt[i];
    for(int i = 0; i<n; i++) cin>>at[i];
    
    cout<< "Process\t Burst Time\t Waiting Time\t Turn Around Time\n";
    // 1st starting time = 0  temp->starting time
    temp[0]= 0;
    for(int i = 0; i<n; i++){
        if(at[i] > temp[i]) temp[i] = at[i];
        temp[i+1] = temp[i] + bt[i];
        
        wt[i] = temp[i] - at[i];
        
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
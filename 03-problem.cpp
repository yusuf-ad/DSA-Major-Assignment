#include<bits/stdc++.h>
using namespace std;

struct Job {
    int id;
    int deadline;
    int profit;
};

bool comparison(Job a, Job b) {
    return (a.profit > b.profit);
}

vector<int> JobScheduling(int n, Job arr[]) {
    sort(arr, arr+n, comparison);
    
    int maxDeadline = 0;
    for(int i=0; i<n; i++) {
        maxDeadline = max(maxDeadline, arr[i].deadline);
    }
    
    int dp[maxDeadline+1];
    for(int i=0; i<=maxDeadline; i++) {
        dp[i] = -1;
    }
    
    int countJobs = 0, jobProfit = 0;
    for(int i=0; i<n; i++) {
        for(int j=arr[i].deadline; j>0; j--) {
            if(dp[j] == -1) {
                dp[j] = i;
                countJobs++;
                jobProfit += arr[i].profit;
                break;
            }
        }
    }
    
    return {countJobs, jobProfit};
}

int main() {
    Job arr[] = {{1,4,20}, {2,1,10}, {3,1,40}, {4,1,30}};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> result = JobScheduling(n, arr);
    cout << "Example 1 output: " << result[0] << " " << result[1] << endl;  
    
    cout << endl;
    
    Job arr2[] = {{1,2,100}, {2,1,19}, {3,2,27}, {4,1,25}, {5,1,15}};
    int m = sizeof(arr2)/sizeof(arr2[0]);
    vector<int> result2 = JobScheduling(m, arr2);
    cout << "Example 2 output: " << result2[0] << " " << result2[1] << endl;  
    return 0;
}

#include<bits/stdc++.h>
using namespace std;

bool comparison(const tuple<int, int, int>& a, const tuple<int, int, int>& b) {
    return (get<2>(a) > get<2>(b));
}

vector<int> JobScheduling(int n, vector<tuple<int, int, int>>& jobs) {
    sort(jobs.begin(), jobs.end(), comparison);
    
    vector<int> slot(n, false);
    int count = 0;
    int profit = 0;
    
    for(auto job : jobs) {
        for(int j = min(n, get<1>(job)) - 1; j >= 0; j--) {
            if(slot[j] == false) {
                slot[j] = true;
                count++;
                profit += get<2>(job);
                break;
            }
        }
    }
    return {count, profit};
}

int main() {
    vector<tuple<int, int, int>> jobs = {make_tuple(1,4,20), make_tuple(2,1,10), make_tuple(3,1,40), make_tuple(4,1,30)};
    int n = jobs.size();
    vector<int> result = JobScheduling(n, jobs);
    cout << "Example 1 output: " << result[0] << " " << result[1] << endl;  
    
    cout << endl;
    
    vector<tuple<int, int, int>> jobs2 = {make_tuple(1,2,100), make_tuple(2,1,19), make_tuple(3,2,27), make_tuple(4,1,25), make_tuple(5,1,15)};
    int m = jobs2.size();
    vector<int> result2 = JobScheduling(m, jobs2);
    cout << "Example 2 output: " << result2[0] << " " << result2[1] << endl;  
    return 0;
}

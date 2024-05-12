#include<bits/stdc++.h>
using namespace std;

struct Pair {
    int a;
    int b;
};

bool comparison(Pair p1, Pair p2) {
    return p1.b < p2.b;
}

int maxChainLen(Pair arr[], int n) {
    sort(arr, arr+n, comparison);
    
    int count = 1;
    int last = arr[0].b;
    
    for(int i=1; i<n; i++) {
        if(arr[i].a > last) {
            last = arr[i].b;
            count++;
        }
    }
    
    return count;
}

int main() {
    Pair arr[] = {{5,24}, {39,60}, {15,28}, {27,40}, {50,90}};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Example 1 output: " << maxChainLen(arr, n) << endl;  
    
    cout << endl;
    
    Pair arr2[] = {{5,10}, {1,11}};
    int m = sizeof(arr2)/sizeof(arr2[0]);
    cout << "Example 2 output: " << maxChainLen(arr2, m) << endl;  
	
	return 0;
}

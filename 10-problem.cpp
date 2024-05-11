#include<bits/stdc++.h>
using namespace std;

int kthElement(int arr1[], int arr2[], int n, int m, int k) {
    if(n > m) {
        return kthElement(arr2, arr1, m, n, k); 
    }
    
    int low = max(0, k-m), high = min(k, n);
    
    while(low < high) {
        int cut1 = low + (high - low) / 2;
        int cut2 = k - cut1;
        int l1 = cut1 == 0 ? INT_MIN : arr1[cut1 - 1];
        int l2 = cut2 == 0 ? INT_MIN : arr2[cut2 - 1];
        int r1 = cut1 == n ? INT_MAX : arr1[cut1];
        int r2 = cut2 == m ? INT_MAX : arr2[cut2];
        
        if(l1 <= r2 && l2 <= r1) {
            return max(l1, l2);
        } else if (l1 > r2) {
            high = cut1;
        } else {
            low = cut1 + 1;
        }
    }
    return 1;
}

int main() {
    int arr1[] = {2, 3, 6, 7, 9};
    int arr2[] = {1, 4, 8, 10};
    int k = 5;
    int n = sizeof(arr1) / sizeof(arr1[0]);
    int m = sizeof(arr2) / sizeof(arr2[0]);
    cout << "Example 1 output: " << kthElement(arr1, arr2, n, m, k) << endl;

	cout << endl;

    int arr3[] = {100, 112, 256, 349, 770};
    int arr4[] = {72, 86, 113, 119, 265, 445, 892};
    k = 7;
    n = sizeof(arr3) / sizeof(arr3[0]);
    m = sizeof(arr4) / sizeof(arr4[0]);
    cout << "Example 2 output: " << kthElement(arr3, arr4, n, m, k) << endl;

    return 0;
}

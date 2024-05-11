#include<bits/stdc++.h>
using namespace std;

bool isPossible(int arr[], int n, int m, int curr_min) {
    int studentsRequired = 1;
    int curr_sum = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > curr_min) {
            return false;
        }

        if (curr_sum + arr[i] > curr_min) {
            studentsRequired++;
            curr_sum = arr[i];

            if (studentsRequired > m) {
                return false;
            }
        } else {
            curr_sum += arr[i];
        }
    }
    return true;
}

int findPages(int arr[], int n, int m) {
    long long sum = 0;

    if (n < m) {
        return -1;
    }

    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }

    int start = 0, end = sum;
    int result = INT_MAX;

    while (start <= end) {
        int mid = (start + end) / 2;
        if (isPossible(arr, n, m, mid)) {
            result = mid;
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    return result;
}

int main() {
    int arr1[] = {12, 34, 67, 90};
    int m1 = 2;
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    cout << "Example 1 output: " << findPages(arr1, n1, m1) << endl;

	cout << endl;

    int arr2[] = {15, 17, 20};
    int m2 = 2;
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    cout << "Example 2 output: " << findPages(arr2, n2, m2) << endl;

    return 0;
}

#include<bits/stdc++.h>
using namespace std;

int maxMeetings(int start[], int end[], int n) {
    vector<pair<int, int>> meetings;
    for(int i = 0; i < n; i++) {
        meetings.push_back({end[i], start[i]});
    }
    sort(meetings.begin(), meetings.end());
    
    int last_meeting_end = -1;
    int count = 0;
    for(auto meeting : meetings) {
        if(meeting.second > last_meeting_end) {
            last_meeting_end = meeting.first;
            count++;
        }
    }
    return count;
}

int main() {
//	Example 1
    int start[] = {1, 3, 0, 5, 8, 5};
    int end[] = {2, 4, 6, 7, 9, 9};
    int n = sizeof(start) / sizeof(start[0]);
    cout << "Example 1 output: " << maxMeetings(start, end, n) << endl;
    
    cout << endl;
    
//  Example 2
    int start1[] = {10, 12, 20};
    int end1[] = {20, 25, 30};
    int m = sizeof(start1) / sizeof(start1[0]);
    cout << "Example 2 output: " << maxMeetings(start1, end1, m) << endl;
    
    return 0;
}

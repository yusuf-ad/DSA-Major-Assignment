#include<bits/stdc++.h>
using namespace std;

void findPath(vector<vector<int>>& m, int x, int y, vector<string>& ans, string path, vector<vector<int>>& vis) {
    int n = m.size();
    if(x<0 || y<0 || x>=n || y>=n || vis[x][y] || m[x][y] == 0) {
        return;
    }
    
    if(x == n-1 && y == n-1) {
        ans.push_back(path);
        return;
    }
    
    vis[x][y] = 1;
    
    findPath(m, x-1, y, ans, path+'U', vis);
    findPath(m, x+1, y, ans, path+'D', vis);
    findPath(m, x, y-1, ans, path+'L', vis);
    findPath(m, x, y+1, ans, path+'R', vis);
    
    vis[x][y] = 0;
}

vector<string> printPath(vector<vector<int>>& m, int n) {
    vector<string> ans;
    vector<vector<int>> vis(n, vector<int>(n, 0));
    findPath(m, 0, 0, ans, "", vis);
    sort(ans.begin(), ans.end());
    return ans;
}

int main() {
    vector<vector<int>> m1 = {{1, 0, 0, 0}, {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1}};
    vector<string> ans1 = printPath(m1, 4);
    cout << "Example 1 output: ";
    for(string s : ans1) {
        cout << s << " ";
    }
    cout << endl;
    
    vector<vector<int>> m2 = {{1, 0}, {1, 0}};
    vector<string> ans2 = printPath(m2, 2);
    for(string s : ans2) {
        cout << s << " ";
    }
    
    cout << endl;
    
    vector<vector<int>> m3 = {{1, 0}, {1, 0}};
	vector<string> ans3 = printPath(m3, 2);
	cout << "Example 2 output: ";
    if(ans3.empty()) {
        cout << "-1" << endl;
    } else {
        for(string s : ans3) {
            cout << s << " ";
        }
        cout << endl;
    }
	cout << endl;
    
    return 0;
}

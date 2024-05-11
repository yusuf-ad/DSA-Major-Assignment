#include<bits/stdc++.h>
using namespace std;

bool isValid(string s) {
    if(s.size() > 1 && s[0] == '0')
        return false;
    if(stoi(s) <= 255 && stoi(s) >= 0)
        return true;
    else
        return false;
}

vector<string> genIp(string ip) {
    int l = ip.size();
    string check = ip;
    vector<string> ans;

    if(l < 4 || l > 12)
        return ans;

    for(int i = 1; i < l - 2; i++) {
        for(int j = i + 1; j < l - 1; j++) {
            for(int k = j + 1; k < l; k++) {
                check = check.substr(0, k) + "." + check.substr(k);
                check = check.substr(0, j) + "." + check.substr(j);
                check = check.substr(0, i) + "." + check.substr(i);

                if(isValid(check.substr(0, i)) && isValid(check.substr(i + 1, j - i)) && isValid(check.substr(j + 2, k - j)) && isValid(check.substr(k + 3)))
                    ans.push_back(check);

                check = ip;
            }
        }
    }

    return ans;
}

int main() {
    string ip1 = "1111";
    vector<string> ans1 = genIp(ip1);
    cout << "Example 1 output: ";
    if(ans1.empty()) {
        cout << "-1" << endl;
    } else {
        for(string s : ans1) {
            cout << s << " ";
        }
        cout << endl;
    }
    
    cout << endl;

    string ip2 = "55";
    vector<string> ans2 = genIp(ip2);
    cout << "Example 2 output: ";
    if(ans2.empty()) {
        cout << "-1" << endl;
    } else {
        for(string s : ans2) {
            cout << s << " ";
        }
        cout << endl;
    }

    return 0;
}

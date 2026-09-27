#include <iostream>             //* Longest prefix sum
#include <vector>
#include <string>
using namespace std;
int main() {

    int n;
    cin >> n;
    vector<string> strs;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        strs.push_back(s);
    }

    string ans = "";

    for (int i = 0; i < strs[0].size(); i++) {
        for (int j = 0; j < strs.size(); j++) {
            
            if (i >= strs[j].size() || strs[j][i] != strs[0][i]) {
                cout << ans;
                return 0;
            }

        }
        ans += strs[0][i];
    }

    cout << ans;

}
#include <bits/stdc++.h>
using namespace std;
int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    unordered_map<char, int> count;
    int left = 0;
    int ans = 0;
    int n = s.size();
    
    for (int right = 0; right < n; right++) {
        
        count[s[right]]++;
        while (count[s[right]] > 1) {
            count[s[left]]--;
            left++;
        }

        ans = max(ans, right - left + 1);

    }

    cout << ans;

}
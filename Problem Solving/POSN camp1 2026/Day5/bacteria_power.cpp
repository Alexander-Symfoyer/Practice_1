#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int power = 0;
        vector<int> freq(26, 0);

        for (int i = 0; i < s.size(); i++) {
            if (islower(s[i])) {
                freq[s[i] - 'a']++;
            }
            else {
                freq[s[i] - 'A']++;
            }
        }
        
        sort(freq.begin(), freq.end(), greater<int>());
        for (int i = 0; i < 26; i++) {
            power += freq[i] * (26 - i);
        }
        
        cout << power << '\n';

    }

    

}
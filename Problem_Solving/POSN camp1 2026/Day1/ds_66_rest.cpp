#include <bits/stdc++.h>
using namespace std;
int main() {

    int n,k;
    cin >> n >> k;
    cin.ignore();

    vector<pair<int, string>> soln;

    for (int i = 0; i < n; i++) {
       string line;
       getline(cin, line);
       stringstream ss(line);

        string name;
        ss >> name;
        int x;
        int count = 0;

        while (ss >> x) {
            if (x < k) {
                count++;
            }
            else if (x == k) {
              soln.push_back({count, name});
            }
            else {
                continue;
            }
        }

    }

    sort(soln.begin(), soln.end());

    if (soln.empty()) {
        cout << -1;
        return 0;
    }
    
    for (int i = 0; i < 3; i++) {
        if (i < soln.size()) {
            cout << soln[i].second << " ";
        }
    }   cout << '\n';

}
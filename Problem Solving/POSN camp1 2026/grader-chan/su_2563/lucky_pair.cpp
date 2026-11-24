#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, lucky; 
    cin >> n;

    vector<int> birth(n);
    for (int i = 0; i < n; i++) {
        cin >> birth[i];
    }

    cin >> lucky;
    bool is_empty = true;
    
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (birth[i] + birth[j] == lucky) {
                cout << birth[i] << " " << birth[j] << '\n';
                is_empty = false;
            }
        }
    }

    if (is_empty) {
        cout << "NO";
    }

}
#include <bits/stdc++.h>
using namespace std;
int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> foods(n);
    for (int i = 0; i < n; i++) {
        cin >> foods[i];
    }

    bool found = true;
    vector<int> remain;
    while (found) {
        remain.clear();
        for (int i = 0; i < foods.size() ; ) {
            int j = i;
            while (j < foods.size() && foods[i] == foods[j]) {
                j++;
            }

            if (j - i == 1) {
                remain.push_back(foods[i]);
            }
                
            i = j;
        }
        
        found = false;
        foods = remain;

        for (int i = 0; i < remain.size(); i++) {
            if (i != remain.size() - 1 && remain[i] == remain[i+1]) {
                found = true;
                break;
            }
        }
    }

    if (remain.empty()) {
        cout << "empty";
    }
    else {
        cout << remain.size() << '\n';
        for (const int& i : remain) {
            cout << i << " ";
        }   cout << '\n';
    }

}
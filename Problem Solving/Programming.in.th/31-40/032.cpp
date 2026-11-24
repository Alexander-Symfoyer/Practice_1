#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {

    vector<int> ans;
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        ans.push_back(x);
    }

    sort(ans.begin(), ans.end());

    int min_index = -1;
    for (int i = 0; i < n; i++) {
        if (ans[i] != 0 && 
            (min_index == -1 || ans[i] < ans[min_index])) {
            min_index = i;
        }

    }

    swap(ans[min_index], ans[0]);

    for (int i = 0; i < n; i++) {
        cout << ans[i];
    }   cout << '\n';

}
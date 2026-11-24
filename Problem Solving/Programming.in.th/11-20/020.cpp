#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {

    vector<vector<int>> v1;
    for (int i = 0; i < 5; i++) {
        vector<int> v2;
        for (int j = 0; j < 4; j++) {
            int x;
            cin >> x;
            v2.push_back(x);
        }
        v1.push_back(v2);
    }

    vector<int> v3;
    for (const auto &row : v1) {
        int sum = 0;
        for (const int &x : row) {
            sum += x;
        }
        v3.push_back(sum);
    }

    auto it = max_element(v3.begin(), v3.end());
    int winner = distance(v3.begin(),it);
    cout << winner + 1 << " " << *it;

}
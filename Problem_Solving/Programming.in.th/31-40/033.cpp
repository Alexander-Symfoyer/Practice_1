#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {

    int n; cin >> n;
    vector<int> v;
    vector<int> count(10001,0);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
        count[x]++;
    }

    int max_count = 0;
    for (int i = 1; i <= 10000; i++) {
        max_count = max(max_count, count[i]);
    }

    for (int i = 1; i <= 10000; i++) {
        if (count[i] == max_count) {
            cout << i << " ";
        }   
    }   cout << '\n';

}
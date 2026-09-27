#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {

    int n;
    vector<int> v;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    auto it1 = min_element(v.begin(), v.end());
    auto it2 = max_element(v.begin(), v.end());

    cout << *it1 << '\n';
    cout << *it2 << '\n';

}
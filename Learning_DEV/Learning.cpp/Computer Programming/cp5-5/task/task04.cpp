#include <bits/stdc++.h>
using namespace std;

void rotate(vector<int>& v, int k) {    //* Time O(n) : Space O(1)

    int n = v.size();
    if (n == 0) return;
    k %= n;
    
    reverse(v.begin(), v.end());        //* Reverse all
    reverse(v.begin(), v.begin() + k);  //* Reverse left
    reverse(v.begin() + k, v.end());    //* Reverse right

}

int main() {
    vector<int> v = {1,2,3,4,5,6,7};
    int k = 3;
    rotate(v, k);

    for (const int& i : v) {
        cout << i << " ";
    }   cout << '\n';
}
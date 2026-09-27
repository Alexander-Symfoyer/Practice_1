#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> nums = {2,2,3,1};
    
    long long first = LLONG_MIN;
    long long second = LLONG_MIN;
    long long third = LLONG_MIN;    

    for (int x : nums) {

        if (x == first || x == second || x == third) {
            continue;
        }

        if (x > first) {
            third = second;
            second = first;
            first = x;
        }
        else if (x > second) {
            third = second;
            second = x;
        }
        else if (x > third) {
            third = x;
        }

    }

    if (third == LLONG_MIN) {
        cout << first;
    }
    else {
        cout << third;
    }

}
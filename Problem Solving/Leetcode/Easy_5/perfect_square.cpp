#include <bits/stdc++.h>
using namespace std;
int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int num;
    scanf("%d", &num);

    int left = 0;
    int right = num / 2;
    long long mid;
    
    while (left <= right) {

        mid = left + (right - left) / 2;
        if (mid * mid < num) {
            left = mid + 1;
        }
        else if (mid * mid > num) {
            right = mid - 1;
        }
        else {
            cout << "True";
            return 0;
        }

    }

    cout << "False";

}
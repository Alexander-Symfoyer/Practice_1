#include <bits/stdc++.h>
using namespace std;

int guess(const int& n) {

}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    scanf("%d", &n);

    int mid;
    int left = 1;
    int right = n;
    while (true) {
        mid = left + (right - left) / 2;
        if (guess(mid) == -1) {
            right = mid - 1;
        }
        else if (guess(mid) == 1) {
            left = mid + 1;
        }
        else {
            cout << mid;
            return 0;
        }
    }

}
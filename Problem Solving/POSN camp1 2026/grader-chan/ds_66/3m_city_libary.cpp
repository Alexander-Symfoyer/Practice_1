#include <bits/stdc++.h>
using namespace std;

vector<pair<long long, long long>> libaries;        //* O(n log 20,000,000) and O(n)

long long count_le(long long x) {

    long long count = 0;
    for (auto [X,Y] : libaries) {

        if (x < X) {
            count += 0;
        }
        else if (x < Y) {
            count += x - X + 1;
        }
        else {
            count += Y - X;
        }

    }

    return count;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; 
    cin >> n;

    long long total_books = 0;
    for (int i = 0; i < n; i++) {
        long long X, Y;
        cin >> X >> Y;
        
        libaries.push_back({X,Y});
        total_books += Y - X;
    }

    if (total_books == 1) {
        cout << libaries[0].first << '\n';
        return 0;
    }

    long long target = total_books / 2;

    long long left = 0;
    long long right = 19999999;
    long long soln = -1;

    while (left <= right) {

        long long mid = (left + right) / 2;
        if (count_le(mid) >= target) {
            soln = mid;
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }

    }

    cout << soln;

}
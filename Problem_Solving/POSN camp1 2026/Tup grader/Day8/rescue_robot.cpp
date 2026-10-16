#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n,k,d;
    cin >> n >> k >> d;

    if (n < 1 || n > 1000 || k < 0 || k > n - 1 || d < 0 || d > 10e9) return 0;

    vector<int> people(n);
    int count = 0;
    for (int i = 0; i < n; i++) {
        cin >> people[i];
        if (people[i] <= d) count++;
    }

    for (int i = 0; i < k; i++) {
        int index = i;
        for (int j = i + 1; j < n; j++) {
            if (people[j] < people[index]) {
                index = j;
            }
        }
        swap(people[i], people[index]);
    }

    for (int i : people) {
        cout << i << " ";
    }   cout << '\n';

    cout << count;

    return 0;
}
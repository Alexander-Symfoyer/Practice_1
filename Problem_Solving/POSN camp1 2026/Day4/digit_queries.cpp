#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {

        long long k;
        cin >> k;
        long long digit = 1;
        long long start = 1;
        
        while (true) {

            long long count = 9 * start;
            long long block = count * digit;

            if (k <= block) break;

            k -= block;
            digit++;
            start *= 10;

        }
        long long number = start + (k - 1) / digit;
        long long position = (k - 1) % digit;
        string s = to_string(number);
        cout << s[position] << '\n';

    }

    return 0;
}
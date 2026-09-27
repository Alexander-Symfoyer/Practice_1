#include <bits/stdc++.h>
using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    if (n == 1) return 1;

    string current = "1";

    for (int k = 1; k < n; k++) {

        string temp = "";

        for (int i = 0; i < current.size(); ) {

            int j = i;
            while (j < current.size() && current[i] == current[j]) {
                j++;
            }

            int freq = j - i;
            temp += to_string(freq);
            temp += current[i];

            i = j;

        }

        current = temp;

    }

    cout << current;

}
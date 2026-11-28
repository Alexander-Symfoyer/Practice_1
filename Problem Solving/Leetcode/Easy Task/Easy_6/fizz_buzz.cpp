#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 15;
    vector<string> soln;

    for (int i = 1; i <= n; i++) {

        if (i % 3 == 0 && i % 5 == 0) {
            soln.push_back("FizzBuzz");
        }
        else if (i % 3 == 0) {
            soln.push_back("Fizz");
        }
        else if (i % 5 == 0) {
            soln.push_back("Buzz");
        }
        else {
            soln.push_back(to_string(i));
        }

    }

    for (string s : soln) {
        cout << s << " ";
    }   cout << '\n';

}
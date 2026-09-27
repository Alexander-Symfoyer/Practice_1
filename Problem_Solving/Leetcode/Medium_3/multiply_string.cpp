#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string num1 = "124";
    string num2 = "67";
    string result = "";
    vector<int> soln(num1.size() + num2.size(), 0);

    for (int i = num1.size() - 1; i >= 0; i--) {
        for (int j = num2.size() - 1; j >= 0; j--) {

            int product = (num1[i] - '0') * (num2[j] - '0');
            soln[i + j] += product / 10;
            soln[i + j + 1] += product % 10;

        }
    }

    for (int x = soln.size() - 1; x > 0; x--) {
        if (soln[x] >= 10) {
            soln[x - 1] += soln[x] / 10;
            soln[x] = soln[x] % 10;
        }
    }

    bool found = true;

    for (const int& x : soln) {
        if ((x == 0) && found) {
            continue;
        }
        else {
            found = false;
            result += to_string(x);
        }
    }  
    if (result.empty()) {
        cout << "0";
        return 0;
    }
    cout << result;

}
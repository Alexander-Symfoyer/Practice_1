#include <bits/stdc++.h>
using namespace std;
int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {

        string command;
        cin >> command;

        if (command == "ADD") {
            int x,y;
            cin >> x >> y;
            cout << x + y << '\n';
        }
        else if (command == "SUB") {
            int x,y;
            cin >> x >> y;
            cout << x - y << '\n';
        }
        else if (command == "MUL") {
            long long x,y;
            cin >> x >> y;
            cout << x * y << '\n';
        }
        else if (command == "DIV") {
            double x,y;
            cin >> x >> y;
            cout << fixed << setprecision(2) << x / y << '\n';
        }
        else if (command == "POW") {
            int x,y;
            long long mul = 1;
            cin >> x >> y;
            for (int i = 0; i < y; i++ ) {
                mul *= x;
            }
            cout << mul << '\n';
        }
        else if (command == "MAX") {
            int max_element = INT_MIN;
            int k;
            cin >> k;
            for (int i = 0; i < k; i++) {
                int x;
                cin >> x;
                max_element = max(max_element, x);
            }
            cout << max_element << '\n';
        }
        else if (command == "MIN") {
            int min_element = INT_MAX;
            int k;
            cin >> k;
            for (int i = 0; i < k; i++) {
                int x;
                cin >> x;
                min_element = min(min_element, x);
            }
            cout << min_element << '\n';
        }
        else if (command == "SUM") {
            long long sum = 0;
            int k;
            cin >> k;
            for (int i = 0; i < k; i++) {
                int x;
                cin >> x;
                sum += x;
            }
            cout << sum << '\n';
        }
        else if (command == "SORT") {
            vector<int> nums;
            int k;
            cin >> k;
            for (int i = 0; i < k; i++) {
                int x;
                cin >> x;
                nums.push_back(x);
            }
            sort(nums.begin(), nums.end());
            for (const int& x : nums) {
                cout << x << " ";
            }   cout << '\n';
        }
        else if (command == "UP") {
            string s;
            getline(cin,s);
            if (!s.empty() && s[0] == ' ') {
                s.erase(0,1);
            }
            for (int i = 0; i < s.size(); i++) {
                s[i] = toupper(s[i]);
            }
            cout << s << '\n';
        }
        else if (command == "LEN") {
            string s;
            getline(cin,s);
            if (!s.empty() && s[0] == ' ') {
                s.erase(0,1);
            }
            cout << s.size() << '\n';
        }

    }

}
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main() {

    int columnNumber = 28;
    string ans = "";
    while (columnNumber > 0) {
        columnNumber--;
        int remainder = columnNumber % 26;
        char c = remainder + 'A';
        ans += c;
        columnNumber /= 26;
    }
    reverse(ans.begin(), ans.end());
    cout << ans;

}
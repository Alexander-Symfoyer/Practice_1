#include <bits/stdc++.h>
using namespace std;
int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s = "LEetCode";
    int left = 0;
    int right = s.size() - 1;
    string vowels = "aeiouAEIOU";

    while (left <= right) {
        if (string(vowels).find(s[left]) == string::npos) {
            left++;
            continue;
        }
        if (string(vowels).find(s[right]) == string::npos) {
            right--;
            continue;
        }

        swap(s[left],s[right]);
        left++;
        right--;
        
    }

    cout << s << '\n';

}
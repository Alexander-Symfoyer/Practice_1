#include <bits/stdc++.h>
using namespace std;
int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string hexa;
    cin >> hexa;
    string octal;
    string binary;

    unordered_map<char, int> alpha = {
        {'A', 10}, {'B', 11}, {'C', 12}, {'D', 13},
        {'E', 14}, {'F', 15}
    };

    int temp = 0;
    int j = 0;
    for (int i = hexa.size() - 1; i >= 0; i--) {
        if (isdigit(hexa[i])) {
            temp += pow(16,j++) * (hexa[i] - '0');
        }
        else {
            temp += pow(16,j++) * (alpha[hexa[i]]);
        }
    }

    int tempo = temp;

    while (temp > 0) {
        binary += char('0' + temp % 2);
        temp /= 2;
    }
    reverse(binary.begin(), binary.end());

    while (tempo > 0) {
        octal += char('0' + tempo % 8);
        tempo /= 8;
    }
    reverse(octal.begin(), octal.end());

    cout << binary << '\n';
    cout << octal << '\n';

}
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> value(n);
    for (int i = 0; i < n; i++) {
        cin >> value[i];
    }

    int maxLength = *max_element(value.begin(), value.end());

    // Large canvas for drawing the stalactites
    int height = maxLength + 1;
    int width = 500;

    vector<string> canvas(height, string(width, ' '));

    int row = 0;
    int col = 0;

    for (int length : value) {

        // Draw the left side
        for (int i = 0; i < length; i++) {
            int r = row + i;
            int c = col + i;

            if (r < height && c < width)
                canvas[r][c] = '\\';
        }

        // Draw the right side
        for (int i = 0; i < length; i++) {
            int r = row + i;
            int c = col + (length * 2 - 2) - i;

            if (r < height && c < width)
                canvas[r][c] = '/';
        }

        // Move to the next stalactite
        col += length * 2;
    }

    for (const string& line : canvas) {
        int last = line.find_last_not_of(' ');

        if (last != string::npos) {
            cout << line.substr(0, last + 1) << '\n';
        }
    }
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int area;
    cin >> area;
    int w = sqrt(area);

    while (area % w != 0) {
        w--;
    }
    
    int l = area / w;

    cout << l << " " << w << '\n';

}
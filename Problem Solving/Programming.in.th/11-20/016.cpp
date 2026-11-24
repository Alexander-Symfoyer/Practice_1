#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {

    int n; cin >> n;
    string letter; cin >> letter;
    vector<char> adrian = {'A', 'B', 'C'};
    vector<char> bruno = {'B', 'A', 'B', 'C'};
    vector<char> goran = {'C', 'C', 'A', 'A', 'B', 'B'};
    int ad = 0; int br = 0; int go = 0;

    for (int i = 0; i < n; i++) {
        if (letter[i] == adrian[i % 3]) ad += 1;
        if (letter[i] == bruno[i % 4]) br += 1;
        if (letter[i] == goran[i % 6]) go += 1;
    }

    int mx = max({ad, br, go});
    cout << mx << '\n';
    if (mx == ad) cout << "Adrian" << '\n';
    if (mx == br) cout << "Bruno" << '\n';
    if (mx == go) cout << "Goran" << '\n';

}
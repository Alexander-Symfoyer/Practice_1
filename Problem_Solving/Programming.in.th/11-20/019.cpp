#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;


int n;
vector<int> sour;
vector<int> bitter;


int ans = 1e9;

void solve(                 //! O(2^n) == 2^10 = 1024
    int index,
    int s,
    int b,
    bool used
) {

    if (index == n) {       //* We have checked all ingredient
        if (used) {         //* We must choose at least one ingredient
            ans = min(ans, abs(s- b));
        }
        return;
    }

    solve(index + 1, s * sour[index], b + bitter[index], true);     //* Choose this ingredient
    solve(index + 1, s, b, used);                                   //* Don't choose this ingredient

}


int main() {

    cin >> n;
    sour.resize(n);
    bitter.resize(n);
    
    for (int i = 0; i < n; i++) {
        cin >> sour[i] >> bitter[i];
    }

    solve(0, 1, 0, false);

    cout << ans;
    return 0;

}
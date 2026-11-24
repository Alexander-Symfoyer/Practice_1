#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int main() {
    int a,b,c;
    cin >> a >> b >> c;
    int x = abs(a - b);
    int y = abs(b - c);
    int output = max(x,y);
    cout << output - 1 << '\n';
}
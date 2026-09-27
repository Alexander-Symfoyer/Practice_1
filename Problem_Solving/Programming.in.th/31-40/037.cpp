#include <iostream>
#include <vector>
using namespace std;
int main() {

    int n, m;
    cin >> n >> m;
    int l, k;
    cin >> l >> k;
    int c; 
    cin >> c;

    long long light = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int x;
            cin >> x;
            light += x;
        }
    }

    long long fuel = c * k * l;
    long long cost = light + fuel;

    long long rent = (cost + c - 1) / c;    //! Ceiling division
    cout << rent;

}
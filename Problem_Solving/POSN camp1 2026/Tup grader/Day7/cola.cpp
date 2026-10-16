#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    if (n < 20 || n > 50000) return 0;
    int total = n / 20;
    int caps = total;
    int bottles = total;
    while (bottles >= 2 || caps >= 4) {
        if (bottles >= 2) {
            int new_bottles = bottles / 2;
            bottles -= new_bottles;
            caps += new_bottles;
            total += new_bottles;
        }
        else if (caps >= 4) {
            int new_caps = caps / 4;
            caps -= new_caps * 3;
            bottles += new_caps;
            total += new_caps;
        }
    }
    
    cout << total << '\n';
    
}
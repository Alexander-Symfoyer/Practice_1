#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
int main() {

    vector<int> v;
    for (int i = 0; i < 9; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }

    int sum = accumulate(v.begin(), v.end(), 0);
    int target = sum - 100;
    int a = 0; int b = 0;
    
    for (int i = 0; i < v.size(); i++) {
        for (int j = i + 1; j < v.size(); j++) {
            if (v[i] + v[j] == target) {
                a = i;
                b = j;
            }                
        }
    }

    for (int i = 0; i < 9; i++) {
        if (i != a && i != b) {
            cout << v[i] << '\n';
        }
    }

}
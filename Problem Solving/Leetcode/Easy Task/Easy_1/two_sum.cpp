#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {

    vector<int> v;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x; 
        cin >> x;
        v.push_back(x);
    }
    int target;
    cin >> target;


    for (int i = 0; i < n; i++) {

        int goal = target - v[i];
        auto it = find(v.begin(), v.end(), goal);
        
        if (it != v.end()) {
            int index1 = it - v.begin();
            if (index1 != i) {
                cout << index1 << " " << i;
                return 0;
            }
        }

    }

    return 0;

}
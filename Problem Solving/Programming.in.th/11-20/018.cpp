#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 
int main() {

    int n,k;
    cin >> n >> k;
    vector<int> v;
    for (int i = 2; i <= n; i++) {

        if (find(v.begin(), v.end(), i) != v.end()) {
            continue;
        }

        int x = 1;

        while (i * x <= n) {
            int num = i * x;

            if (find(v.begin(), v.end(), num) == v.end()) {
                v.push_back(num);
                
                if (v.size() == k) {
                    cout << num;
                    return 0;
                }
            }
            x++;
        }
    }


}
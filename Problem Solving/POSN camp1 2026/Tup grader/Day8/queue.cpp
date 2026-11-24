#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;

    vector <int> height;
    for(int i = 0; i < n; i++){
        int input;
        cin >> input;
        height.push_back(input);
    }

    for(int i = 0; i < m; i++){
        int target;
        cin >> target;
        int pre = *max_element(height.begin(), height.begin() + target - 1);

        if(pre < height[target - 1]){ 
            cout << "0\n";
        }
        else if (target == 1) { 
            cout << "0\n"; 
        }
        else{ 
            cout << pre - height[target-1] + 1 << "\n"; 
        }
    }
    return 0;
}
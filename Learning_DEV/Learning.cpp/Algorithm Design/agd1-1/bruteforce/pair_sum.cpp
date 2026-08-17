#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


void input(vector<int> &v) {
    
    int n;
    cout << "Enter size of vector : ";
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        int x;
        cout << "Enter member " << i + 1 << " : ";
        cin >> x;
        v.push_back(x);
    }
    
}


int pair_sum(vector<int> &v, int k) {

    bool found = false;

    for(int i = 0; i < v.size(); i++) {

        int target = k - v[i];
        auto it = find(v.begin() + i + 1, v.end(), target);
        
        if (it != v.end()) {
            cout << v[i] << " + " << target << " = " << k << '\n';
            found = true;
        }

    }
    if (!found) {
        cout << 0 << " " << 0 << '\n';
    }

}


int main() {

    vector<int> v;
    input(v);

    int k;
    cout << "Enter value : ";
    cin >> k;

    pair_sum(v, k);


}
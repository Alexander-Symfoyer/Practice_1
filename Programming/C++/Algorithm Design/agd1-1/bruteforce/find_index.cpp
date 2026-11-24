#include <iostream>
#include <vector>

using namespace std;


int brute_force(vector<int> S, int T) {
    
    for (int i = 0; i < S.size(); i++) {
        if (S[i] == T) {
            return i;
        }
    } 
    return 0;

}



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


int main() {

    vector<int> v;
    input(v);

    cout << "------------------------" << '\n';

    cout << "Enter value : ";
    int x;
    cin >> x;
    cout << "Found value at index : " << brute_force(v, x) << '\n';

}
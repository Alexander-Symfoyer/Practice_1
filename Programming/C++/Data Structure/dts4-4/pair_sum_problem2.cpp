#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {        // set method
    vector<int> arr = {2,5,3,8,10,1};
    int X = 10;
    set<int> s;

    for (int i : arr) {         //* Range based for loop 
        int target = X - i;     //* for (x : y) for all y contain in x
        
        if (s.find(target) != s.end()) {
            cout << "Found pair!" << endl;
            cout << target << " + " << i << " = " << X << endl;

            return 0;
        }
        s.insert(i);
    }
    cout << "NO pair found" << endl;

    return 0;
}
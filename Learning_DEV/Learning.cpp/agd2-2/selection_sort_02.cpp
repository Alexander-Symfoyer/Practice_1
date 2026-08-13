#include <iostream>
#include <vector> 
#include <algorithm>


using namespace std;


template<typename T>
vector<T> selection_sort(vector<T> &a) {

    vector<T> b;
    while(a.size() > 0) {

        auto it = max_element(a.begin(), a.end());          //* O(n)
        b.insert(b.begin(), *it);                           //* O(n) elements in b must be shifted right
        a.erase(it);                                        //* O(n) elements after it must be shifed left

    }
    return b;

}


void print(const vector<int> &b) {

    cout << "{";

    for (int i = 0; i < b.size(); i++) {

        cout << b[i];
        if (i != b.size() - 1) {
            cout << ",";
        }

    }

    cout << "}" << '\n';

}


int main() {

    vector<int> a = {3,21,54,6,3,88,73,82,1,0,312,348};
    print(selection_sort(a));

}
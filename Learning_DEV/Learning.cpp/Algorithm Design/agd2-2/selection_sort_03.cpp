#include <iostream>
#include <vector> 
#include <algorithm>


using namespace std;


template<typename T>
vector<T> selection_sort(vector<T> &a) {

    vector<T> b(a.size());
    while(a.size() > 0) {

        auto it = max_element(a.begin(), a.end());              //* O(n) for each iteration
        b[a.size() - 1] = *it;                                  //* fill from right to left
        swap(*it, a[a.size() - 1]);                             //* O(1) move the maximum to the last position
                                                                //* Remove it without shifting other elements
        a.pop_back();                                           //* O(1) only remover the last element

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

    vector<int> a = {7,23,532,773,900,318,1,783,89,1,849,12,3};
    print(selection_sort(a));

}
#include <iostream>
#include <vector>


using namespace std;

vector<int> selection_sort(vector<int> &a, vector<int> &b) {            //* Time complexity = O(n^2)

    while(!a.empty()) {                             //* Keep sorting until all elements are moved to b

        int max_index = 0;                          
        for (int i = 0; i < a.size(); i++) {        //* Search for larger element

            if (a[i]  > a[max_index]) {             //* Update

                max_index = i;

            }
        }

        b.insert(b.end(), a[max_index]);            //* Move to b
        a.erase(a.begin() + max_index);             //* Remove from a
                                                    //? So it will not be selected again
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

    vector<int> a = {3,5,1,5,2,6,3,21};
    vector<int> b;

    print(selection_sort(a, b));

}
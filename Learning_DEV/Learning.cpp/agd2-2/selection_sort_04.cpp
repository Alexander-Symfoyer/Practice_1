#include <iostream>
#include <vector>


using namespace std;


template<typename T>
vector<T> selection_sort(vector<T> &a) {

    size_t pos = a.size() - 1;
    for ( ; pos > 0; pos --) {
        
        int max_index = 0;
        for (size_t i = 0; i <= pos; i++) {

            if (a[i] > a[max_index]) {          //* O(n^2)
                max_index = i;
            }

        }

        swap(a[pos], a[max_index]);             //* swap from right to left <--

    }

    return a;

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

    vector<int> a = {3,5,2,532,98,730,03,183,9,0,3278,382};
    print(selection_sort(a));

}
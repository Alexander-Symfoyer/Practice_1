#include <iostream>
#include <vector>


using namespace std;                        //! O(n) | worst case O(n^2)

template <typename T>
vector<T> insertion_sort(vector<T> &a){

    for (int pos = a.size() - 2; pos >= 0; pos--) {

        T temp = a[pos];                        //* Stores current value
        size_t i = pos + 1;                     //* Comparing with the next element

        while(i < a.size() && a[i] < temp) {    //* Shift smaller elements to the left (next < current)
            a[i-1] = a[i];                      //* Move the current one position left
            i++;                                //* Move to the next element
        }

        a[i-1] = temp;          //* Insert temp into the correct position

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

    vector<int> a = {100,99,98,97,96,95,94,93,92,91,90};
    print(insertion_sort(a));

}
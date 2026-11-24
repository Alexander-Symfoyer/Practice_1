#include <iostream>
#include <vector>

using namespace std;


template<typename T>
vector<T> shell_sort(vector<T> &a) {                        //* Time complexity depends on the gap sequence

    vector<int> gaps = {701, 301, 132, 57, 23, 10, 4, 1};   //* Gap sequence use by shell sort
    int n = a.size();
    
    for (int gap : gaps) {                      //* Processes each gap from large to small

        if (gap >= n) continue;                 //* Skip gap that are to large for the vector

        for (int pos = n - gap - 1; pos >= 0; pos--) {    //! Start at the last position where pos + gap is still a valid index  

            T temp = a[pos];                    //* Stores the current value
            int i = pos + gap;                  //* Comparing with the next element
            while (i < n && temp > a[i]) {      //? Shift smaller element to the left

                a[i-gap] = a[i];                //? Move one gap to the left
                i += gap;                       //* Move to the next element in the group

            }

            a[i-gap] = temp;                    //* Insert temp into the correct position
        }

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

    vector<int> a = {
        1,4,18,93,83,90,9,4,8,0,100                 //todo n = 11
    };

    print(shell_sort(a));

}
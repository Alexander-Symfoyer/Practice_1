#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace chrono;


int bsearch(vector<int> a, int k) {     //? T(n) = T(n-1) + O(n) --> O(n^2)

    if (a.size() == 1) {                //* Base case : only one element left
        if (a[0] == k) return 1;
        return -1;
    }

    if (a[0] == k) return 1;            //* check first element
    else {

        vector<int> b(a.begin() + 1, a.end());      //* Create new array without first element
        int r = bsearch(b, k);                      //* Search in smaller array

        if (r != -1) return r + 1;                  //* Adjust index if found
        else return -1;

    }

}


int main() {

    auto start = high_resolution_clock::now();


    vector<int> a = {5,2,8,1,10,4,3,93,100,38,29,7};
    int k = 7;
    int pos = bsearch(a, k);

    if (pos != -1) {
        cout << "Found at position : " << pos << '\n';
    }
    else {
        cout << "Not found\n";
    }


    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);

    cout << "Time : " << duration.count() <<  "mcs\n";


}
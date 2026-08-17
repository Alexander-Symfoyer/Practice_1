#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace chrono;


int search(vector<int> v, int k) {           //* O(n)

    for (int i = 1; i <= v.size(); i++) {
        if (v[i] == k) return i;
    }
    return -1;

}


int main() {

    auto start = high_resolution_clock::now();


    vector<int> v = {1,2,3,4,5};
    int k = 5;
    cout << search(v, k) << '\n';


    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);

    cout << "Time : " << duration.count() <<  "mcs\n";


}

// 1 second
// = 1,000 milliseconds
// = 1,000,000 microseconds
// = 1,000,000,000 nanoseconds
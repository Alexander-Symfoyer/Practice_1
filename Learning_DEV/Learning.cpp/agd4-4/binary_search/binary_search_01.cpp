#include <iostream>
#include <vector>
#include <queue>
#include <chrono>


using namespace std;                        //! O(n)
using namespace chrono;


template<typename T>
int bsearch(queue<T> &v, T k) {             //* Recursively search each element in the queue

    if (v.size() == 1) {                    //* Stop recursion when only one elements remains
        if (v.front() == k) return 1;       //? O(1)
        return -1;
    } 
    else {

        if (v.front() == k) return 1;       //* Check the current first element before removing it
        v.pop();                            //* Remove it       O(1)
        int r = bsearch(v, k);              //* Search remaining elements               T(n) = T(n-1) + O(1)
        
        return (r == -1) ? r : r + 1;       //* Add 1 because the result is one position further

    }


}

template<typename T>
int bsearch_slow(vector<T> &v, T k) {       //* Convert vector to queue before searching

    queue<T> q;
    for (auto &x : v) {
        q.push(x);                          //? O(n)
    }
    return bsearch(q, k);               //* Start

}


int main() {

    auto start = high_resolution_clock::now();



    vector<int> v = {1,3,5,8,9,10,11,38,49,50,67};
    int k = 67;
    cout << "Found at : " << bsearch_slow(v, k) << '\n';



    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);

    cout << "Time : " << duration.count() <<  "mcs\n";


}


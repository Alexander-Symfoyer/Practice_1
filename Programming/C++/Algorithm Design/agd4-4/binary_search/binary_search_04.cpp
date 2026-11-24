#include <iostream>
#include <vector>

using namespace std;


template<typename T>
int bsearch(vector<T> &v, T k, int start, int stop) {         //* O(log n) --> 

    if (start == stop) {                        //* Only one element remains
        return v[start] == k ? start : -1;
    }

    int m = (start + stop) >> 1;                //* Find the middle index (>>1 = / 2)
    if (v[m] >= k) {
        return bsearch(v, k, start, m);         //* left half
    } else {
        return bsearch(v, k, m+1, stop);        //* right half
    }

}

template<typename T>
int real_bsearch(vector<T> &v, T k) {

    return bsearch(v, k, 0, v.size() - 1);

}



int main() {


    vector<int> v = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    int k = 5;
    cout << "Found at : " << real_bsearch(v,k) << '\n';

    
}
#include <iostream>
#include <vector>


using namespace std;


template<typename T>
int bsearch(vector<T> &v, T k, int start) {

    if (v[start] == k) return start + 1;
    if (start == v.size() - 1) return -1;
    return bsearch(v, k, start + 1);

}


template<typename T>
int bsearch_slow(vector<T> &v, T k) {

    return bsearch(v,k,0);

}


int main() {

    vector<int> v = {1,3,5,9,10,389,390,100,382,109,393};
    int k = 393;
    cout << "Found at : " << bsearch_slow(v, k) << '\n';

}
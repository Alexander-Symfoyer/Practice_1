#include <iostream>
#include <vector>


using namespace std;


template<typename T>
int bsearch(vector<T> &v, T k, int start) {

    if (start == v.size() - 1) {

        if (v[start] == k) return start + 1;
        return -1;

    }
    else {

        if (v[start] == k) return start + 1;
        return bsearch(v, k, start + 1);

    }

}


template<typename T>
int bsearch_slow(vector<T> &v, T k) {
    return bsearch(v, k, 0);
}



int main() {

    vector<int> v = {1,3,5,32,64,67,99};
    int k = 99;

    cout << "Found at : " << bsearch_slow(v, k) << '\n';

}
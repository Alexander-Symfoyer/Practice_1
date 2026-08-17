#include <iostream>
#include <vector>

using namespace std;

                                                //! T(n) = 2T(n/2) + O(n)
template<typename T>                            //! O(n log n)
void merge(                     //* Merge two sorted halves
    vector<T> &v, 
    vector<T> &temp, 
    int start, 
    int stop, 
    int m
) {

    int bi = start;                             //* Points to the current element in the left half
    int ci = m + 1;                             //* Points to the current element inn the right half!
    for (int i = start; i <= stop;) {

        if (ci > stop) {                        //* The right half has no element left
            temp[i++] = v[bi++];                //* Take the remaining element from the left half
            continue;
        }

        if (bi > m) {                           //* The left half has no elemetn left
            temp[i++] = v[ci++];                //* Take the remaining element from the right half   
            continue;
        }
                                                                //* Both halves still have elements
        temp[i++] = (v[bi] < v[ci]) ? v[bi++] : v[ci++];        //* Take the smaller values

    }

    for (int i = start; i <= stop; i++) {
        v[i] = temp[i];
    }

}


template<typename T>                //* Divide vector into smaller halves
void merge_sort(                    
    vector<T> &v,                  
    vector<T> &temp, 
    int start, 
    int stop
) {

    if (start < stop) {

        int m = (start + stop) >> 1;        //* Find the middle index
        
        merge_sort(v, temp, start, m);          //* Recursively sort the left half
        merge_sort(v, temp, m+1, stop);         //* Recursively sort the right half
        merge(v, temp, start, stop, m);         //* Both half are now sorted
                                                //* Merge them into one sorted range
    }

}

template<typename T>
void print(vector<T> v) {

    cout << "{";
    for (int i = 0; i < v.size(); i++) {

        cout << v[i];
        if (i != v.size() - 1) {
            cout << ",";
        }

    }
    cout << "}\n";

}


int main() {

    vector<int> v = {3,5,1,93,39,10,33,18,19,35,50,29,30,93,85,78};
    vector<int> temp(v.size());

    merge_sort(v, temp, 0, v.size() - 1);

    print(v);
}

//
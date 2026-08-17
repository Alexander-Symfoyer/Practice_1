#include <iostream>
#include <vector>


using namespace std;                        //! Best case O(n log n)
                                            //! Worts case O(n ^ 2)

template<typename T>                                        //* Hoare partition
int partition(vector<T> &a, int start, int stop) {          

    int pivot = a[start];
    int left = start - 1;
    int right = stop + 1;

    while(true) {

        do {                            //* Find an element on the left that belongs on the right
            left++;
        } while (a[left] < pivot);      //? Until a[left] >= pivot

        do {                            //* Find an element on the right that belongs on the left
            right--;
        } while (a[right] > pivot);     //? Unti a[right] <= pivot

        if (left >= right) {            //* Stop when the two pointers meet
            return right;
        }

        swap(a[left], a[right]);        //* Put element in the correct side of the pivot

    }

}


template<typename T>
void quick_sort(vector<T> &a, int start, int stop) {

    if (start < stop) {

        int p = partition(a, start, stop);          //* Partition the array and get the dividing point
        
        quick_sort(a, start, p);                    //* Sort the left part
        quick_sort(a, p + 1, stop);                 //* Sort the right part

    }

}


int main() {

    vector<int> a = {8,4,7,3,9,2,6,1,5};

    quick_sort(a, 0, a.size() - 1);

    for (int x : a) {
        cout << x << " ";
    }
    cout << '\n';

}
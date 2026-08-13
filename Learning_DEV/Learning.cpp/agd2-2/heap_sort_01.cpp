#include <iostream>
#include <vector>


using namespace std;            //! O(n log n)


void fix_down(vector<int> &a, int i, int size) {            //* Fix down from node i

    int temp = a[i];

    while(2 * i + 1 < size) {                       //* Find the larger child

        int c = 2 * i + 1;                          //* Get the left child
        
        if (c + 1 < size && a[c]  < a[c+1]) {       //* Choose the larger child
            c++;
        }

        if(a[c] < temp) break;              //* Stop if parent is already larger!

        a[i] = a[c];                        //* Move the child up
        i = c;                              //* Move down to the child

    }

    a[i] = temp;                //* Place the values_ in the correct position

}


void heap_sort(vector<int> &a) {

    int n = a.size();

    for (int i = n / 2 - 1; i >= 0; i--) {          //* Build the max heap
        fix_down(a, i, n);
    }

    int pos = n;            //* Track the heap size

    while (pos > 1) {                   //* Extract maximum value

        swap(a[0], a[pos - 1]);         //* Move maximum to the end
        pos--;                          //* Reduce the heap size
        fix_down(a, 0, pos);            //* Restore the max heap

    }


}


int main() {

    vector<int> a = {3,5,6,9,13,29,11,4};       // n = 8

    heap_sort(a);

    cout << "{";
    for (int i = 0; i < a.size(); i++) {
        
        cout << a[i];
        if (i != a.size() - 1) {
            cout << ",";
        }

    }
    cout << "}";

    return 0;

}

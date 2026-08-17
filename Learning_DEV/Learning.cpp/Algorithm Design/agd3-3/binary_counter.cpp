#include <iostream>
#include <vector>


using namespace std;


void print(vector<int> &v) {

    cout << "{";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i];
        if (i != v.size() - 1) {
            cout << ",";
        }
    }
    cout << "}" << '\n';

}


int counter(vector<int> v, int i, int n) {          //* Big theta (n(2^n))

    if (i > 0) {
        v[i] = 0;
        counter(v, i-1, n);
        v[i] = 1;
        counter(v, i-1, n);
    }
    else {
        print(v);
    }
    return 0;
}


int main() {

    vector<int> v = {1,2,3};
    int i = 3;
    int n = 3;
    counter(v, i, n);

}
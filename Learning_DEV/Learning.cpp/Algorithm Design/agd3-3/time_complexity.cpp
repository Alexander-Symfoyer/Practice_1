#include <iostream>
#include <vector>

using namespace std;


int test(vector<int> &v) {

    int sum = 0;
    for (int i = 0; i < v.size(); i++) {
        for (int j = i + 1; j < v.size(); j++) {
            sum += v[i] + v[j];                         //! Most executed line
        }                                               //? T(n) grow similar to n^2
    }
    return sum;

}


void erase( ) {

    vector<int> v = {0,0,0,0};
    int mSize;
    auto it = v.begin();

    while ((it + 1) != v.end()) {                   
        
        *it = *(it + 1);                    //? Mostly, it is the one in the inermost loopf
        it++;

    }

    mSize--;
}



int main() {

    vector <int> v = {1,1,1,1,1,1,1,1,1,1,1,0,0,0,0};
    cout << test(v) << '\n';

}
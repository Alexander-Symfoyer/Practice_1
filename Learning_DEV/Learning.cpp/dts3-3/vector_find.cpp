#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    vector<int> v = {1,1,2,3,5,8,13,21};

    int x = 5;
    if ( find(v.begin(), v.end(), x) != v.end()) {      //* find(a,b,c)
        cout << "found" << endl;                        //* find c from a to before b
    } else {                                            //* if not found return b
        cout << "not found" << endl;                    //! find() return iterator not bool
    }

    if ( find(v.begin(), v.begin() + 3, x) != v.begin() + 3) {      //! if use != v.end() it will always true
        cout << "found" << endl;
    } else {
        cout << "not found" << endl;
    }
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> v1 = {0,10,20,30,40,50,60,70,80};
    vector<float> v2 = {0.2, -4, 0.13, 3.14, 2.73};

    vector<int>::iterator it1 = v1.begin() + 3;
    vector<float>::iterator it2 = v2.end();
    
    // getting value at iterator by using "*" operator
    cout << *it1 << endl;           
    cout << *it2 << endl;
    cout << *(it2 - 1) << endl;
    cout << *(it1 + 3) + 7 << endl;

    // iterator arithmetics
    vector<int>::iterator it3 = it1 + 2;
    cout << *it3 << endl;
    cout << "Different of it1 and it3 : " << (it3 - it1) << " (position)" << endl;
    cout << "Different of it1 and it3 : " << (*it3 - *it1) << " (value)" << endl;

    vector<float>::iterator it4 = v2.end();
    it4--;
    cout << *it4 << endl;

}
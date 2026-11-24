#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> v1 = {0,10,20,30,40,50,60,70,80};
    vector<float> v2 = {0.2, -4, 0.13, 3.14, 2.73, 0.008};

    vector<int>::iterator it1 = max_element(v1.begin(), v1.end());   
    auto it2 = min_element(v2.begin() + 2, v2.end());

    cout << *it1 << endl;       // max/min_element(a,b) from a to before b
    cout << *it2 << endl;
    
}

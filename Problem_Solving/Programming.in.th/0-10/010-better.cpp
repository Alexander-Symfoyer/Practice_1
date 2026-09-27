#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {

    string str;
    cin >> str;
    vector<int> v = {1,0,0};

    for (char i : str) {
        if (i == 'A') swap(v[0],v[1]);
        else if (i == 'B') swap(v[1],v[2]);
        else swap(v[0],v[2]);
    }
    
    auto it = find(v.begin(), v.end(), 1);
    int index = it - v.begin() + 1;
    cout << index;

}
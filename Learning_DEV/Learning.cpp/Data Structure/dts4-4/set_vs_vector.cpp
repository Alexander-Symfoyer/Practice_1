#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> v;
    for (int i = 0; i < 1000; i++) {
        v.push_back(i);
    }

    auto it1 = find(v.begin(), v.end(), 555);


    set<int> s;
    for (int i = 0; i < 1000; i++) {
        s.insert(i);
    }
    
    auto it2 = s.find(555);
}
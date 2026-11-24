#include <bits/stdc++.h>
using namespace std;
int main() {

    int n;
    static int count;
    while (cin >> n && n != 0) {
        count++;
    }
    cout << count;

    do {        //* Guarunteed to atleast once
        cout << "Enter positive number : ";
        cin >> n;
    }   while (n <= 0);

    vector<int> v = {1,1,1,1};
    v.reserve(100);     //* Capacity = 100
    n = v.size();                   //* Efficient
    for (int i = 0; i < n; i++) {   //* Call size once outside
        cout << v[i] << " ";
    }   cout << '\n';

}
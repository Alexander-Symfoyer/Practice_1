#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> v1;
    cout << "Size of v1 " << v1.size() << endl;
    cout << v1.empty() << endl;

    vector<int> v2 = {2,3,4};

    cout << v2[1] << endl;
    v1 = v2;
    v1[0] = 20;

    cout << v1[0] << endl;
    cout << v1.empty() << endl;

    v1.push_back(5);
    cout << "Size of v1 " << v1.size() << endl;

    for (int i = 0; i < v1.size(); i++) {
        cout << v1[i] << endl;
    }
}

// Vector = A linear storage of a single data type
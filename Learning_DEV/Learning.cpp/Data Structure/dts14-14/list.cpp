#include <iostream>
#include <list>

using namespace std;

void print(list<int> &a) {

    for (int i : a) {
        cout << i << " ";
    }
    cout << '\n';

}

int main() {

    list<int> a = {10, 20, 30};

    a.push_front(0);
    a.push_back(50);

    print(a);

    a.pop_front();
    a.pop_back();

    print(a);
    

}